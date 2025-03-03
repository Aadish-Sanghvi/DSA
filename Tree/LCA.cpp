#include<iostream>
#include<map>
#include<queue>
#include<vector>
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

Node* lca(Node* root, int n1, int n2){
    //base case
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* leftans = lca(root->left, n1, n2);
    Node* rightans = lca(root->right, n1, n2);

    if(leftans != NULL && rightans != NULL){
        return root;
    }
    else if(leftans == NULL && rightans == NULL){
        return NULL;
    }
    else if(leftans != NULL && rightans == NULL){
        return leftans;
    }
    else{
        return rightans;
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(6);
    root->left->left->right = new Node(8);
    root->right = new Node(3);
    root->right->left = new  Node(4);
    root->right->right = new Node(5);
    root->right->right->left = new Node(21);

    int n1 = 4;
    int n2 = 21;

    Node* ans = lca(root, n1, n2);
    
    if (ans != NULL) {
        cout << "The Lowest Common Ancestor (LCA) is: " << ans->data << endl;
    } else {
        cout << "One or both nodes not found in the tree." << endl;
    }

    return 0;
}
