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

vector<int> zigzag(Node*root)
{
	vector<int>result;
	if(root==NULL)
	{
		return result;
	}
	queue<Node*>q;
	q.push(root);
	bool lefttoright=true;
	while(!q.empty())
	{
		int size=q.size();
		vector<int>ans(size);
		for(int i=0;i<size;i++)
		{
			Node*frontnode=q.front();
			q.pop();
			int index=lefttoright?i:size-i-1;
			ans[index]=frontnode->data;
			if(frontnode->left)
			{
				q.push(frontnode->left);
			}
			if(frontnode->right)
			{
				q.push(frontnode->right);
			}
		}
		lefttoright=!lefttoright;
		for(auto i:ans)
		{
			result.push_back(i);
		}
	}
	return result;
}

int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> answer = zigzag(root);


    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;

}