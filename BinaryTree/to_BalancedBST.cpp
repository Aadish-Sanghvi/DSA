#include<iostream>
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

void inorder(Node* root, vector<int>& in){
    if (root == nullptr) {
        return;
    }

    inorder(root -> left, in);
    in.push_back(root -> data);
    inorder(root -> right, in);
}

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

Node* inorderToBST(vector<int>& in, int s, int e){
    if(s > e){
        return NULL;
    }

    int mid = (s+e) / 2;

    Node* root = new Node(in[mid]);
    root -> left = inorderToBST(in, s, mid - 1);
    root -> right = inorderToBST(in, mid + 1, e);

return root;
}

int main(){
    Node* root = new Node(50);
    root->left = new Node(25);
    root->right = new Node(75);
    root->left->left = new Node(12);
    root->right->right = new Node(88);
    root->left->left->left = new Node(6);
    root->right->right->right = new Node(94);

    cout << "Before conversion to balanced tree: " << endl;
    levelordertraversal(root);

    vector<int> in;
    inorder(root,in);

    Node* ans = inorderToBST(in, 0, in.size()-1);
    
    cout << "After conversion to balanced tree: " << endl;
    levelordertraversal(ans);

    return 0;
}