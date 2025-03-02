#include<iostream>
using  namespace std;

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

class info{
    public:
        int mini;
        int maxi;
        bool isBST;
        int size;
};

info solve(Node* root, int &ans){
    if( root == NULL ){
        return{INT_MIN, INT_MAX, true, 0};
    }

    info left = solve(root -> left, ans);
    info right = solve(root -> right, ans);

    info currNode;
    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(left.maxi, right.maxi);
    currNode.mini = min(left.mini, right.mini);
    
    if(left.isBST && right.isBST && (root -> data > left.maxi && root -> data < right.mini)){
        currNode.isBST = true;
    }
    else{
        currNode.isBST = false;
    }

    if(currNode.isBST){
        ans =  max(ans,currNode.size);
    }
    return currNode;
}

int largestBST(Node* root){
    int maxSize = 0;
    info temp = solve(root,maxSize);
    return temp.size;
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(15);
    root->right->right = new Node(25);

    int ans = largestBST(root);

    cout << "The largest BST is of " << ans << " size" << endl;
    
    return 0;
}