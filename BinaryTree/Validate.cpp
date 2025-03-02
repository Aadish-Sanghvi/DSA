#include<iostream>
#include<queue>
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

bool validate(Node* root, int min, int max){
    //base case
    if(root == NULL){
        return true;
    }
    
    if(root -> data >= min && root -> data <= max){
        bool right = validate(root -> right, root -> data, max);
        bool left = validate(root -> left, min, root -> data);
        return left && right;
    }
    else{
        return false;
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
    
    if(validate(root, INT_MIN, INT_MAX)){
        cout << "It is BST" << endl; 
    }
    else{
        cout << "It's not a BST" << endl;
    }

    return 0;
}