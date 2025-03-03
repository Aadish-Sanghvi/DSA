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

vector<int> verticalOrder(Node* root){
    map<int, map<int, vector<int> > > node;
    queue<pair<Node*, pair<int,int> > > q;
    vector<int> ans;

    if(root == NULL){
        return ans;
    }
    //first line level = 0 & horizontal dist = 0
    q.push(make_pair(root, make_pair(0,0)));

    while(!q.empty()){
        pair<Node*, pair<int,int> > temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second.first;
        int level = temp.second.second;

        node[hd][level].push_back(frontNode->data);
        if(frontNode->left){
            q.push(make_pair(frontNode->left, make_pair(hd-1, level+1)));
        }

        if(frontNode->right){
            q.push(make_pair(frontNode->right, make_pair(hd+1, level+1)));
        }
    }

    for(auto i: node){
        for(auto j: i.second){
            for(auto k: j.second){
                ans.push_back(k);
            }
        }
    }

    return ans;
}

int main(){
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new  Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->left->right = new Node(8);
    root->right->right = new Node(7);
    root->right->right->right = new Node(9);

    vector<int> answer = verticalOrder(root);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}
