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

void solve(Node* root, int &count, int k, vector<int> path){
    //base case
    if(root == NULL){
        return;
    }

    path.push_back(root->data);

    //left and right
    solve(root-> left, count, k, path);
    solve(root-> right, count, k, path);

    int size = path.size();
    int sum = 0;
    for(int i = size-1; i>=0; i--){
        sum += path[i];
        if(sum == k){
            count ++; 
        }
        path.pop_back();
    }
}

int kSum(Node* root, int k){
    vector<int> path;
    int count = 0;
    solve(root,count,k,path);
    return count;
}

int main(){ 
    int k = 3;

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    // root->left->left = new  Node(4);
    // root->left->right = new Node(5);
    // root->left->right->left = new Node(8);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);

    int ans = kSum(root, k);
    cout<<"The count of path giving the sum k is: "<< ans << endl;

    return 0;
}