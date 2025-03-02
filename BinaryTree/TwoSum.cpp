#include<iostream>
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

bool TwoSum(Node* root, int target, vector<int> in){
    int i = 0;
    int j = in.size() - 1;

    while(i < j){
        int sum = in[i] + in[j];

        if(sum == target){
            return true;
        }
        if(sum > target){
            j--;
        }
        if(sum < target){
            i++;
        }
    }
return false;
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
    
    int target;
    cout << "Enter the target value" << endl;
    cin >> target;

    if(TwoSum(root,target,in) == true){
        cout << "Two sum exists" << endl;
    }
    else{
        cout << "Two sum don't exists" << endl;
    }
    return 0;
}