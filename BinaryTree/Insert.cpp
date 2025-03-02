#include<iostream>
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

Node* insertIntoBST(Node* &root, int d){
    if(root == NULL){
        root = new Node(d);
        return root;
    }
    if(d > root -> data){
        root -> right = insertIntoBST(root -> right, d);
    }
    else{
        root -> left = insertIntoBST(root -> left, d);
    }
    return root;
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

void takeInput(Node* & root){
    int data;
    cin >> data;

    while(data != -1){
        root = insertIntoBST(root,data);
        cin >> data;
    }
}

int main(){
    Node* root = NULL;

    cout << "Enter Data to create binary search tree" << endl;
    takeInput(root);
    cout << "Printing the tree" << endl;
    levelordertraversal(root);

    return 0;
}

// input 10 20 15 22 13 28 8 -1 ====> "-1" se end hoga input 