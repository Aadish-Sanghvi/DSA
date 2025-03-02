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

// bool search(Node* root, int x){
//     if(root == NULL){
//         return false;
//     }
//     if(root->data == x){
//         return true;
//     }
//     if(root->data > x){
//         return search(root->left, x); 
//     }
//     else{
//         return search(root->right, x);
//     }
// }

//OPTIMISED METHOD ----------------------------------------------------------------
bool search(Node* root, int x){
    while(root != NULL){
        if(root -> data == x){
            return true;
        }
        if(root -> data > x){
            root = root -> left;
        }
        else{
            root = root -> right;
        }
    }
    return false;
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(15);
    root->right->right = new Node(25);

    int x;
    cout << "Enter the number you want to search: ";
    cin >> x;

    bool found = search(root, x);
    if(found){
        cout << x << " is present in the binary search tree." << endl;
    }
    else{
        cout << x << " is not present in the binary search tree." << endl;
    }
    return 0;
}