#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) { 
        this -> data = value;
        this -> left = this -> right = NULL;
    }
};

int height(Node* root){
    //base case
    if(root == NULL){
        return 0;
    }
    int left = height(root -> left);
    int right = height(root -> right);

    int ans = max(left, right) + 1;

    return ans;
}

bool isBalanced(Node* root){
    //base case
    if(root == NULL){
        return true;
    }
    bool left = isBalanced(root -> left);
    bool right = isBalanced(root -> right);
    bool diff = abs (height(root -> left) - height(root -> right)) <= 1;

    if(left && right && diff){
        return true;
    }
    else{
        return false;
    }
}

int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    bool ans = isBalanced(root);

    if(ans == true){
        cout << "Tree is balanced" << endl;
    }
    else{
        cout << "Tree is not balanced" << endl;
    }
    return 0;
}