// Find the Inorder Successor and Inorder Predecessor of the key element 
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

Node* findKey(Node* root, int k){
    if(root == NULL){
        return NULL;
    }
    if(root -> data == k){
        return root;
    }
    if(root -> data > k){
        return findKey(root -> left, k);
    }
    else{
        return findKey(root -> right, k);
    }
}


int predecessor(Node* root, int k){
    Node* key = findKey(root, k);
    if(key -> left != NULL){
        return (key -> left) -> data;
    }
    else{
        return -1;
    }
}

int successor(Node* root, int k){
    Node* key = findKey(root, k);
    if(key -> right != NULL){
        return (key -> right) -> data;
    }
    else{
        return -1;
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
    
    int k;
    cout << "Enter the key for successor and predecessor: " << endl;
    cin >> k;

    cout << "The predecessor of given key is: " << predecessor(root,k) << endl;
    cout << "The predecessor of given key is: " << successor(root,k) << endl;

    return 0;
}