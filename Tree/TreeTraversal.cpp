// #include<iostream>
// #include<queue>
// using namespace std;
// class node
// {
//    public:
// 	int data;
// 	node*left;
// 	node*right;
// 	node(int d)
// 	{
// 		this->data=d;
// 		this->left=NULL;
// 		this->right=NULL;
// 	}
// };
// node*buildtree(node*root)
// {
// 	cout<<"enter the data: "<<endl;
// 	int data;
// 	cin>>data;
// 	root=new node(data);
// 	if(data==-1)
// 	{
// 		return NULL;
// 	}
// 	cout<<"enter data for inserting in left of:"<<data<<endl;
// 	root->left=buildtree(root->left);
// 	cout<<"enter data for inserting in right of:"<<data<<endl;
// 	root->right=buildtree(root->right);
// 	return root;
// }
// void levelordertraversal(node*root)
// {
// 	queue <node*> q;
// 	q.push(root);
// 	q.push(NULL);
	
// 	while(!q.empty())
// 	{
// 		node*temp=q.front();
// 		q.pop();
// 		if(temp==NULL)
// 		{
// 			cout<<endl;
// 			if(!q.empty())
// 			{
// 				q.push(NULL);
// 			}
// 		}
// 		else
// 		{
// 			cout<<temp->data<<" ";
// 			 if(temp->left)
// 	 	  {
// 			  q.push(temp->left);
// 		  }
// 		     if(temp->right)
// 		   {
// 			  q.push(temp->right);
// 		   }
// 		}
// 	}
// }
// void inorder(node*root)
// {
// 	if(root==NULL)
// 	{
// 		return;
// 	}
// 	inorder(root->left);
// 	cout<<root->data<<" ";
// 	inorder(root->right);
// }
// int main()
// {
// 	node*root=NULL;
// 	root=buildtree(root);
// 	levelordertraversal(root);
// 	inorder(root);
// 	return 0;
// }
// //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
                               
// 							      preorder

// #include<iostream>
// #include<queue>
// using namespace std;
// class node
// {
//    public:
// 	int data;
// 	node*left;
// 	node*right;
// 	node(int d)
// 	{
// 		this->data=d;
// 		this->left=NULL;
// 		this->right=NULL;
// 	}
// };
// node*buildtree(node*root)
// {
// 	cout<<"enter the data: "<<endl;
// 	int data;
// 	cin>>data;
// 	root=new node(data);
// 	if(data==-1)
// 	{
// 		return NULL;
// 	}
// 	cout<<"enter data for inserting in left of:"<<data<<endl;
// 	root->left=buildtree(root->left);
// 	cout<<"enter data for inserting in right of:"<<data<<endl;
// 	root->right=buildtree(root->right);
// 	return root;
// }
// void levelordertraversal(node*root)
// {
// 	queue <node*> q;
// 	q.push(root);
// 	q.push(NULL);
	
// 	while(!q.empty())
// 	{
// 		node*temp=q.front();
// 		q.pop();
// 		if(temp==NULL)
// 		{
// 			cout<<endl;
// 			if(!q.empty())
// 			{
// 				q.push(NULL);
// 			}
// 		}
// 		else
// 		{
// 			cout<<temp->data<<" ";
// 			 if(temp->left)
// 	 	  {
// 			  q.push(temp->left);
// 		  }
// 		     if(temp->right)
// 		   {
// 			  q.push(temp->right);
// 		   }
// 		}
// 	}
// }
// void preorder(node*root)
// {
// 	if(root==NULL)
// 	{
// 		return;
// 	}
// 	cout<<root->data<<" ";
// 	preorder(root->left);
// 	preorder(root->right);
// }
// int main()
// {
// 	node*root=NULL;
// 	root=buildtree(root);
// 	levelordertraversal(root);
// 	preorder(root);
// 	return 0;
// }
// //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1


//                                    postorder


#include<iostream>
#include<queue>
using namespace std;
class node
{
   public:
	int data;
	node*left;
	node*right;
	node(int d)
	{
		this->data=d;
		this->left=NULL;
		this->right=NULL;
	}
};
node*buildtree(node*root)
{
	cout<<"enter the data: "<<endl;
	int data;
	cin>>data;
	root=new node(data);
	if(data==-1)
	{
		return NULL;
	}
	cout<<"enter data for inserting in left of:"<<data<<endl;
	root->left=buildtree(root->left);
	cout<<"enter data for inserting in right of:"<<data<<endl;
	root->right=buildtree(root->right);
	return root;
}
void levelordertraversal(node*root)
{
	queue <node*> q;
	q.push(root);
	q.push(NULL);
	
	while(!q.empty())
	{
		node*temp=q.front();
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
void preorder(node*root)
{
	if(root==NULL)
	{
		return;
	}
	preorder(root->left);
	preorder(root->right);
	cout<<root->data<<" ";
}
int main()
{
	node*root=NULL;
	root=buildtree(root);
	levelordertraversal(root);
	preorder(root);
	return 0;
}
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1