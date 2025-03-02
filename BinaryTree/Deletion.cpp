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

Node* min(Node* root){
    Node* temp = root;
    while(temp -> left != NULL){
        temp = temp -> left;
    }
    return temp;
}

Node* max(Node* root){
    Node* temp = root;
    while(temp -> right != NULL){
        temp = temp -> right;
    }
    return temp;
}

Node* deleteNode(Node* root, int x){
    //base case
    if(root == NULL){
        return root;
    }

    if(root -> data == x){
        // 0 child
        if(root -> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }
        // 1 child -> left only
        if(root -> left != NULL && root -> right == NULL){
            Node* temp = root -> left;
            delete root;
            return temp;
        }
        // 1 child -> right only
        if(root -> right != NULL && root -> left == NULL){
            Node* temp = root -> right;
            delete root;
            return temp;
        }
        // 2 child
        if(root -> left != NULL && root -> right != NULL){
            
            // // With minimum value from right
            // int minVal = min(root -> right) -> data;
            // root -> data = minVal;
            // root -> right = deleteNode(root -> right, minVal);
            // return root;

            // With maximum value from left
            int maxVal = max(root -> left) -> data;
            root -> data = maxVal;
            root -> left = deleteNode(root -> left, maxVal);
            return root;
        }
    }

    else if(root -> data > x){
        // left part me jao 
        root -> left = deleteNode(root -> left, x);
        return root;
    }
    else{
        // right part me jao 
        root -> right = deleteNode(root -> right, x);
        return root;
    }
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(15);
    root->right->right = new Node(25);
    
    cout << "before deletion" << endl;
    levelordertraversal(root);

    int x;
    cout << "Enter the value you wanna delete" << endl;
    cin >> x;

    deleteNode(root,x);

    cout << "after deletion" << endl;
    levelordertraversal(root);

    return 0;
}