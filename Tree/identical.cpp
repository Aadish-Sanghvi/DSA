#include<iostream>
using namespace std;

template<typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T value) {
        data = value;
        left = right = NULL;
    }
};

bool isIdentical(BinaryTreeNode<int>* r1, BinaryTreeNode<int>* r2){
    //base case
    if(r1 == NULL && r2 == NULL){
        return true;
    }
    if(r1 != NULL && r2 == NULL){
        return false;
    }
    if(r1 == NULL && r2 != NULL){
        return false;
    }

    bool left = isIdentical(r1 -> left, r2 -> left);
    bool right = isIdentical(r1 -> right, r2 -> right);
    bool value = r1 -> data == r2 -> data;

    if(left && right && value){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    BinaryTreeNode<int>* r1 = new BinaryTreeNode<int>(1);
    r1->left = new BinaryTreeNode<int>(2);
    r1->left->left = new BinaryTreeNode<int>(4);
    r1->left->right = new BinaryTreeNode<int>(5);
    r1->right = new BinaryTreeNode<int>(3);

    BinaryTreeNode<int>* r2 = new BinaryTreeNode<int>(1);
    r2->left = new BinaryTreeNode<int>(2);
    r2->left->left = new BinaryTreeNode<int>(4);
    r2->left->right = new BinaryTreeNode<int>(5);
    r2->right = new BinaryTreeNode<int>(3);

    bool ans = isIdentical(r1,r2);

    if(ans == true){
        cout<<"Identical";
    }
    else{
        cout<<"Not Identical";
    }
    return 0;
}