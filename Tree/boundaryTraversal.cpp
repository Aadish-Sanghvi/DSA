#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        this->data = value;
        this->left = right = NULL;
    }
};

void leftTraversal(Node* root, vector<int> &ans){
    //base case
    if( (root == NULL) || (root->left == NULL && root->right == NULL) ){
        return;
    }
    
    ans.push_back(root->data);
    
    if(root->left){
        leftTraversal(root->left, ans);
    }
    else{
        leftTraversal(root->right, ans);
    }
}

void leafTraversal(Node* root, vector<int> &ans){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }

    leafTraversal(root->left, ans);
    leafTraversal(root->right, ans);
}

void rightTraversal(Node* root, vector<int> &ans){
    //base case
    if( (root == NULL) || (root->left == NULL && root->right == NULL) ){
        return;
    }
    if(root->right){
        rightTraversal(root->right,ans);
    }
    else{
        leftTraversal(root->left,ans);
    }

    //wapas aagae
    ans.push_back(root->data);
}

vector<int> boundaryTraversal(Node* root){
    vector<int> ans;

    if(root == NULL){
        return ans;
    }

    ans.push_back(root->data);

    //left part print/store
    leftTraversal(root->left, ans);
    //leaf node print/store
    leafTraversal(root, ans);
    //right part print/store 
    rightTraversal(root->right, ans);

    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new  Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(8);
    root->right->right->right->right = new Node(9);

    vector<int> answer = boundaryTraversal(root);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
    
    return 0;
}