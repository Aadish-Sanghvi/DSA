// #include<iostream>
// #include<vector>
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

// //Approach 1 using vector------------------------------------------------------------------------------------
// bool solve(Node* root, int k, int n, vector<int>& path){
//     //base case
//     if(root == NULL)
//         return false;

//     // If the node is found, store the path and return true
//     if(root->data == n){
//         path.push_back(root->data);
//         return true;
//     }

//     // If the node is not found in the left or right subtree, return false
//     if(solve(root->left, k, n, path) || solve(root->right, k, n, path)){
//         path.push_back(root->data);
//         return true;
//     }

//     return false;
// }

// void kthAncestor(Node* root, int k, int n){
//     vector<int> path;

//     // If the node is not present, print an error message
//     if(!solve(root, k, n, path)){
//         cout << "Node not found!" << endl;
//         return;
//     }

//     // Print the path and the Kth ancestor if it exists
//     int size = path.size();
//     cout << "The path is: "<<endl;
//     for(int i = 0; i < size; i++){
//         cout << path[i] << " ";
//     }

//     if(k < size){
//         cout << "\nThe Kth ancestor is: "<< path[k] << endl;
//     } else {
//         cout << "\nK is greater than the number of ancestors!" << endl;
//     }
// }

// int main(){ 
//     int n = 4;
//     int k = 2;

//     Node* root = new Node(1);
//     root->left = new Node(2);
//     root->right = new Node(3);
//     root->left->left = new  Node(4);
//     root->left->right = new Node(5);

//     kthAncestor(root, k, n);

//     return 0;
// }

// //Approach 2 using recursion------------------------------------------------------------------------------------
 
#include<iostream>
#include<vector>
#include <climits>
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

Node* solve(Node* root, int &k, int n){
    if(root == NULL){
        return NULL;
    }

    if(root->data == n){
        return root;
    }

    Node* leftans = solve(root->left, k, n);
    Node* rightans = solve(root->right, k, n);

    if(leftans == NULL && rightans != NULL){
        // we have to lock the node and send it to the root of tree so that value do not change
        k--;
        if(k <= 0){
            // lock the answer(by this k will never be <= 0) hence  
            k = INT_MAX;
            return root;
        }
        return rightans;
    }
    else if(leftans != NULL && rightans == NULL){
        k--;
        if(k <= 0){
            // lock the answer(by this k will never be <= 0) hence  
            k = INT_MAX;
            return root;
        }
        return leftans;
    }
    else{
        return NULL;
    }
}

int kthAncestor(Node* root, int k, int n){
    Node* ans = solve(root, k, n);
    if(ans == NULL){
        return -1;
    }
    return ans->data;
}

int main(){ 
    int n = 4;
    int k = 2;

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new  Node(4);
    root->left->right = new Node(5);

    int ans = kthAncestor(root, k, n);

    cout << "the kth ancestor of the node is: "<< ans;

    return 0;
}
