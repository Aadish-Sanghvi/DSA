// APPROACH 1 ------------------------------------------------------------------------------------
// #include<iostream>
// #include<vector>
// #include<queue>
// using  namespace std;

// class Node {
// public:
//     int data;
//     Node* left;
//     Node* right;

//     Node(int value) {
//         this->data = value;
//         this->left = this->right = NULL;
//     }
// };

// void inorder(Node* root, vector<int>& in){
//     if (root == nullptr) {
//         return;
//     }

//     inorder(root -> left, in);
//     in.push_back(root -> data);
//     inorder(root -> right, in);
// }

// void levelordertraversal(Node* root)
// {
// 	queue<Node*> q;
// 	q.push(root);
// 	q.push(NULL);
	
// 	while(!q.empty())
// 	{
// 		Node* temp=q.front();
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

// Node* inorderToBST(vector<int>& in, int s, int e){
//     if(s > e){
//         return NULL;
//     }

//     int mid = (s+e) / 2;

//     Node* root = new Node(in[mid]);
//     root -> left = inorderToBST(in, s, mid - 1);
//     root -> right = inorderToBST(in, mid + 1, e);

// return root;
// }

// vector<int> mergeBST(vector<int> in1, vector<int> in2) {
//     vector<int> in3;
//     int i = 0, j = 0;

//     // Merge the sorted vectors
//     while (i < in1.size() && j < in2.size()) {
//         if (in1[i] < in2[j]) {
//             in3.push_back(in1[i]);
//             i++;
//         } else {
//             in3.push_back(in2[j]);
//             j++;
//         }
//     }

//     // Add remaining elements from in1
//     while (i < in1.size()) {
//         in3.push_back(in1[i]);
//         i++;
//     }

//     // Add remaining elements from in2
//     while (j < in2.size()) {
//         in3.push_back(in2[j]);
//         j++;
//     }

//     return in3;
// }

// int main(){
//     Node* root1 = new Node(10);
//     root1->left = new Node(5);
//     root1->right = new Node(20);
//     root1->left->left = new Node(3);
//     root1->left->right = new Node(7);
//     root1->right->left = new Node(15);
//     root1->right->right = new Node(25);
//     cout << "The first tree is as follows: " << endl;
//     levelordertraversal(root1);
//     cout << endl;

//     Node* root2 = new Node(60);
//     root2->left = new Node(55);
//     root2->right = new Node(70);
//     root2->left->left = new Node(50);
//     root2->right->right = new Node(75);
//     cout << "The second tree is as follows: " << endl;
//     levelordertraversal(root2);
//     cout << endl;

//     vector<int> in1;
//     inorder(root1, in1);
    
//     vector<int> in2; 
//     inorder(root2, in2);

//     vector<int> in3 = mergeBST(in1, in2);

//     Node* ans = inorderToBST(in3, 0, in3.size() - 1);

//     cout << "The tree after merging looks like: " << endl;
//     for (int i = 0; i < in3.size(); i++){
//     cout << in3[i] << " ";
//     }
//     levelordertraversal(ans);
    
//     return 0;
// }

// APPROACH 2 ------------------------------------------------------------------------------------
#include<iostream>
#include<vector>
#include<queue>
using  namespace std;

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

Node* convertIntoSortedDLL(Node* root, Node* &head){
    if(root == NULL){
        return NULL;
    }    

}

int main(){
    Node* root1 = new Node(10);
    root1->left = new Node(5);
    root1->right = new Node(20);
    root1->left->left = new Node(3);
    root1->left->right = new Node(7);
    root1->right->left = new Node(15);
    root1->right->right = new Node(25);
    cout << "The first tree is as follows: " << endl;
    levelordertraversal(root1);
    cout << endl;

    Node* root2 = new Node(60);
    root2->left = new Node(55);
    root2->right = new Node(70);
    root2->left->left = new Node(50);
    root2->right->right = new Node(75);
    cout << "The second tree is as follows: " << endl;
    levelordertraversal(root2);
    cout << endl;

    Node* head = convertIntoSortedDLL(root);
    
    return 0;
}