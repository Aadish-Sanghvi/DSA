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

int LCA(Node* root, int a, int b){
    if(root == NULL){
        return -1;
    }
    if(root -> data < a && root -> data < b){
        return LCA(root -> right, a, b);
    }
    if(root -> data > a && root -> data > b){
        return LCA(root -> left, a, b);
    }
    else{
        return root -> data;
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
    
    int a,b;
    cout << "Enter the a and b nodes" << endl;
    cin >> a >> b;

    int ans;
    ans = LCA(root,a,b);
 
    cout << "The lowest common ancestor is: " << ans << endl;

    return 0;
}