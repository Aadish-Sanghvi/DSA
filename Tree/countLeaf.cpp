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

void inorder(BinaryTreeNode *root, int &cnt)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left, cnt);

    // Leaf Node
    if(root->left == NULL && root->right == NULL){
        cnt++;
    }

    inorder(root->right, cnt);
}

int noOfLeafNodes(BinaryTreeNode *root){
    int cnt = 0;
    inorder(root, cnt);
    return cnt;
}

int main(){

    BinaryTreeNode* root = new BinaryTreeNode(1);
    root->left = new BinaryTreeNode(2);
    root->right = new BinaryTreeNode(3);
    root->left->left = new BinaryTreeNode(4);
    root->left->right = new BinaryTreeNode(5);
    root->right->left = new BinaryTreeNode(6);
    root->right->right = new BinaryTreeNode(7);

    int ans = noOfLeafNodes(root);
    cout << "Number of leaf nodes: " << ans << endl;

    return 0;
}
