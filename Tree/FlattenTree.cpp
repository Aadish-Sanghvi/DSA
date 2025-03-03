//Flatten a binary tree to a linked list in preorder manner

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
    while(pred -> right != NULL && pred -> right != curr){
        pred = pred -> right;
    }
    return pred;
}

void visit(Node* curr){
    cout << curr -> data << " ";
    return;
}

void flattenTree(Node* root){
    Node* curr = root;
    while(curr != NULL){
        visit(curr);
        if(curr -> left != NULL){
            Node* pre = find(curr);
            pre -> right = curr -> right;
            curr -> right = curr -> left;
        }
        curr = curr -> right;
    }
    return;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);

    flattenTree(root);
    return 0;
}