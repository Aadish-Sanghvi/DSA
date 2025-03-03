#include<iostream>
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

//<a,b>  a: max sum including nodes at current level and b: by excluding
pair<int, int> solve(Node* root){
    //base case
    if(root == NULL){
        return make_pair(0,0);
    }
    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    pair<int,int> res;
    res.first = root->data + left.second + right.second;
    res.second = max(left.first, left.second) + max(right.first, right.second);

    return res;
}

int getMaxSum(Node* root){
    pair<int,int> ans = solve(root);
    return max(ans.first, ans.second);
}

int main(){ 
    int n = 4;
    int k = 2;

    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->right = new Node(3);
    root->right->left = new  Node(5);
    root->right->right = new Node(6);

    int ans = getMaxSum(root);

    cout << "the max is: "<< ans;

    return 0;
}