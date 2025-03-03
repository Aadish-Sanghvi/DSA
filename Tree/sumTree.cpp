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

pair<bool,int> isSumTree(BinaryTreeNode* root){
    //base case
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    //leaf Node
    if(root -> left == NULL && root -> right == NULL){
        pair<bool,int> p = make_pair(true, root -> data);
    } 

    pair<bool,int> leftAns = isSumTree(root -> left);
    pair<bool,int> rightAns = isSumTree(root -> right);    

    bool left = leftAns.first;
    bool right = rightAns.first;

    bool condition = root -> data = leftAns.second + rightAns.second;

    pair<bool,int> ans;
    ans.second = 2*(root -> data);

    if(left && right && condition){
        ans.first = true;
    } 
    else{
        ans.second = false;
    }
    return ans;
}

int main(){
    BinaryTreeNode* root = new BinaryTreeNode(70);
    root->left = new BinaryTreeNode(20);
    root->left->left = new BinaryTreeNode(10);
    root->left->right = new BinaryTreeNode(10);
    root->right = new BinaryTreeNode(30);
    
    pair<bool,int> answer = isSumTree(root);

    if(answer.first == 1){
        cout << "its sum tree" << answer.first << endl;
    }
    else{
        cout << "its not a sum tree" << answer.first << endl;
    }
    return 0;
}