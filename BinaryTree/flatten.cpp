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

void inorder(Node* root, vector<int>& in){
    if (root == nullptr) {
        return;
    }

    inorder(root -> left, in);
    in.push_back(root -> data);
    inorder(root -> right, in);
}

void displayList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->right;
    }
    cout << endl;
}

Node* flatten(Node* root, vector<int>& in){
    if (root == nullptr)
        return nullptr;
        
    Node* newRoot = new Node(in[0]);
    Node* curr = newRoot;

    for(int i = 1; i < in.size(); i++){
        Node* temp = new Node(in[i]);
        curr -> right = temp;
        curr = temp;
    }

    return newRoot;
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(15);
    root->right->right = new Node(25);

    vector<int> in;
    inorder(root,in);

    Node* ans = flatten(root,in);
    
    cout << "The sorted linked list starts with new Root: " << endl;
    displayList(ans);

    return 0;
}
