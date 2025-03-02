#include<iostream>
#include<vector>
#include<queue>
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

void levelordertraversal(Node* root)
{
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	
	while(!q.empty())
	{
		Node* temp=q.front();
		q.pop();
		if(temp==NULL)
		{
			cout<<endl;
			if(!q.empty())
			{
				q.push(NULL);
			}
		}
		else
		{
			cout<<temp->data<<" ";
			 if(temp->left)
	 	  {
			  q.push(temp->left);
		  }
		     if(temp->right)
		   {
			  q.push(temp->right);
		   }
		}
	}
}

Node* solve(vector<int> &preorder, int min, int max, int &i){
    if(i > preorder.size()){
        return NULL;
    }
    if(preorder[i] < min || preorder[i] > max){
        return NULL;
    }  
    
    Node* root = new Node(preorder[i]);
    i++;
    root -> left = solve(preorder, min, root -> data, i);
    root -> right = solve(preorder, root -> data, max, i);
    return root;
}

Node* preorderToBST(vector<int> &preorder){
    int min = INT_MIN;
    int max = INT_MAX;
    int i = 0;

    return solve(preorder, min, max, i);
}

int main(){
    vector<int> preorder;
    preorder.push_back(20);
    preorder.push_back(10);
    preorder.push_back(5);
    preorder.push_back(15);
    preorder.push_back(13);
    preorder.push_back(35);
    preorder.push_back(30);
    preorder.push_back(42);
    
    Node* newRoot = preorderToBST(preorder);

    levelordertraversal(newRoot);

    return 0;
}