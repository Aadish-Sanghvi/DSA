// #include<iostream>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* left;
//     Node* right;

//     Node(int value) {
//         this->data = value;
//         this->left = this->right = NULL;
//     }
// };

// // By inorder traversal approach T.C = o(N) and S.C = o(N)
// int kthSmallest(Node* root, int &i, int k){
//     //base case
//     if(root == NULL){
//         return -1;
//     }
    
//     int left = kthSmallest(root -> left, i, k);
//     if(left != -1){
//         return left;
//     }

//     i++;
//     if(k == i){
//         return root -> data;
//     }

//     int right = kthSmallest(root -> right, i, k);
//     return right;
// }

// int main(){
//     Node* root = new Node(10);
//     root->left = new Node(5);
//     root->right = new Node(20);
//     root->left->left = new Node(3);
//     root->left->right = new Node(7);
//     root->right->left = new Node(15);
//     root->right->right = new Node(25);
    
//     int i = 0; 
//     int kth;

//     cout << "Enter the kth smallest number to find form BST" << endl; 
//     cin >> kth;

//     int ans = kthSmallest(root, i, kth);

//     cout << "The " << kth << "th smallest number from BST is " << ans << endl;

//     return 0;
// }


// By Morris traversal approach T.C = o(N) and S.C = o(1) ----------------------------------
#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        this->data = value;
        this->left = this->right = NULL;
    }
};

Node* find(Node* curr){
    Node* pred = curr -> left ;
    while(pred -> right != NULL && pred -> right !=curr){
        pred = pred -> right;
    }
    return pred;
}

int kthSmallest(Node* root, int &i, int k){
    Node* curr = root;
    while(curr != NULL){
        if(curr -> left == NULL){
            i++;
            curr = curr -> right;
        }
        else{
            Node* pre = find(curr);
            if(pre -> right == NULL){
                pre -> right = curr;
                curr = curr -> left;
            }
            else{
                pre -> right = NULL;
                i++;
                curr = curr -> right;
            }
        }
        if(i == k){
            return curr -> data;
        }
    }
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(15);
    root->right->right = new Node(25);
    
    int i = 0; 
    int kth;

    cout << "Enter the kth smallest number to find form BST" << endl; 
    cin >> kth;

    int ans = kthSmallest(root, i, kth-1); //don't know reeason why doing -1 here 

    cout << "The " << kth << "th smallest number from BST is " << ans << endl;

    return 0;
}