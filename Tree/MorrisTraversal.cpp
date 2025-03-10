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

void MorrisTraversal(Node* root){
    Node* curr = root;

    while(curr != NULL){
        if(curr -> left == NULL){
            visit(curr);
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
                visit(curr);
                curr = curr -> right;
            }
        }
    }
    return;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->right = new Node(7);
    root->right->right = new Node(6);

    MorrisTraversal(root);
    return 0;
}