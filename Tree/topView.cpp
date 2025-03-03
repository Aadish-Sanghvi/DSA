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

vector<int> topView(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    //mapping of Horizontal distance with node mapping
    map<int,int> topNode;
    
    //int is H.D.
    queue<pair<Node*, int> >q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;

        //if one value is present for a H.D. then do nothing
        if(topNode.find(hd) == topNode.end()){
            topNode[hd] = frontNode -> data;
        }
        if(frontNode -> left){
            q.push(make_pair(frontNode->left,hd-1));
        }
        if(frontNode -> right){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }
    for(auto i: topNode){
        ans.push_back(i.second);
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
    root->right->right = new Node(7);

    vector<int> answer = topView(root);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}