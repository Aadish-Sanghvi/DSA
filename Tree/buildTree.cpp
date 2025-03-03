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

// Build tree from inorder and preorder and print postorder

// int findPosition(int arr[], int element, int n){
//     for(int i = 0; i<n; i++){
//         if(arr[i] == element)
//         return i;
//     }
    
//     return -1;
// }
// Node* solve(int in[], int pre[], int &index, int start, int end, int n){
//     //base case
//     if(index >= n || start > end){
//         return NULL;
//     }

//     int element = pre[index++];
//     Node* root = new Node(element);
//     int position = findPosition(in, element, n);
//     root->left = solve(in,pre,index,0,position-1,n);
//     root->right = solve(in,pre,index,position+1,end,n);

// return root;
// }

// Node* buildTree(int in[], int pre[], int n){
//     int preOrderIndex = 0;
//     Node* ans = solve(in, pre, preOrderIndex, 0, n-1, n);
//     return ans;
// }

// int main(){
//     int n = 6;
//     int in[6] = {3,1,4,3,5,2};
//     int pre[6] = {0,1,3,4,2,5};

//     Node* answer = buildTree(in,pre,n);
        
//     return 0;
// }



// Build tree from inorder and postorder and print preorder

int findPosition(int arr[], int element, int n){
    for(int i = 0; i<n; i++){
        if(arr[i] == element)
        return i;
    }
    
    return -1;
}

Node* solve(int in[], int post[], int &index, int start, int end, int n){
    //base case
    if(index < 0 || start > end){
        return NULL;
    }

    int element = post[index--];
    Node* root = new Node(element);
    //cout<<root->data<<" ";
    int position = findPosition(in, element, n);
    root->right = solve(in,post,index,position+1,end,n);
    root->left = solve(in,post,index,0,position-1,n);
    cout<<root->data<<" ";

return root;
}

Node* buildTree(int in[], int post[], int n){
    int postOrderIndex = n-1;
    Node* ans = solve(in, post, postOrderIndex, 0, n-1, n);
    return ans;
}

int main(){
    int n = 8;
    int in[8] = {4,8,2,5,1,6,3,7};
    int pre[8] = {8,4,5,2,6,7,3,1};

    Node* answer = buildTree(in,pre,n);
        
    return 0;
}