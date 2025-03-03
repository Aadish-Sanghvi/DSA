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

Node* createParentMapping(Node* root, int target, map<Node* , Node*> &nodeToParent){
    queue<Node*> q;
    q.push(root);
    Node* res = NULL;

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front->data == target){
            res = front;
        }
        if(front->left){
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if(front->right){
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
}

void burnTree(Node* root, map<Node* , Node* &nodeToParent){
    map<Node*, bool> visited;
    queue<Node*> q;

    q.push(root);
    visited[root] = true;
}

int minTime(Node* root, int target){
    int ans = 0;
    map<Node* , Node*> nodeToParent;
    Node* targetNode = createParentmapping(root, target, nodeToParent);

    burnTree(targetNode, nodeToParent);

    return ans;
}