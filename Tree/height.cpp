#include<iostream>
using namespace std;

class BinaryTreeNode {
public:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int value) {
        this->data = value;
        this->left = right = NULL;
    }
};

int height(BinaryTreeNode *root){
    //base case
    if(root == NULL){
        return 0;
    }
    int left = height(root -> left);
    int right = height(root -> right);

    int ans = max(left, right) + 1;

    return ans;
}
    
int main(){

    BinaryTreeNode* root = new BinaryTreeNode(1);
    root->left = new BinaryTreeNode(2);
    root->right = new BinaryTreeNode(3);
    root->left->left = new BinaryTreeNode(4);
    root->left->right = new BinaryTreeNode(5);
    root->left->right->left = new BinaryTreeNode(7);
    root->left->right->right = new BinaryTreeNode(NULL);
    root->right->left = new BinaryTreeNode(NULL);
    root->right->right = new BinaryTreeNode(6);
    root->right->right->left = new BinaryTreeNode(9);
    root->right->right->right = new BinaryTreeNode(NULL);
    root->right->right->left->left = new BinaryTreeNode(8);

    int ans = height(root);
    cout << "Max height is: " << ans << endl;

    return 0;
}
