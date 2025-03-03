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

void solve(Node* root, int sum, int &maxSum, int len, int &maxLen){
    //base case
    if(root == NULL){
        
    if(len > maxLen){
        maxLen = len;
        maxSum = sum;
    }
    else if(len == maxLen){
        maxSum = max(sum,maxSum);
    }
    return;
    }

    sum = sum + root->data;
    solve(root->left, sum, maxSum, len+1, maxLen);
    solve(root->right, sum, maxSum, len+1, maxLen);
}

int sumOfLongestPathRootToLeaf(Node* root){
    int len = 0;
    int maxLen = 0;

    int sum = 0;
    int maxSum = 0;

    solve(root,sum,maxSum,len,maxLen);

    return maxSum;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new  Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int ans = sumOfLongestPathRootToLeaf(root);
    cout<<"The sum of longest path from root to leaf is: "<< ans << endl;

    return 0;
}