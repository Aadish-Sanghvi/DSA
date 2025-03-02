#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* findMid(Node* &head){
    Node* slow = head;
    Node* fast = head -> next;

    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next; 
    }
    return slow;
}

Node* merge(Node* left, Node* right){
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }
    Node* ans = new Node(-1);
    Node* temp = ans;

    while(left != NULL && right != NULL){
        if(left -> data < right -> data){
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else{
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }

    while(left != NULL){
        temp -> next = left;
        temp = left;
        left = left -> next;
    }

    while(right != NULL){
        temp -> next = right;
        temp = right;
        right = right -> next;
    }

    return ans->next; // Return the starting node of the merged list
}

Node* mergeSort(Node* head){
    //base case
    if(head == NULL || head -> next == NULL){
        return head;
    }

    //break LL into two halves after finding mid
    Node* mid = findMid(head);
    Node* left = head;
    Node* right = mid -> next;
    mid -> next = NULL;

    //recursive call to both left and right halves
    left = mergeSort(left);
    right = mergeSort(right);

    //merge both halves
    Node* result = merge(left, right);

    return result;
}

int main(){
    Node* head = new Node(11);
    head->next = new Node(33);
    head->next->next = new Node(5);
    head->next->next->next = new Node(77);

    cout << "Original List: "<<endl;
    printList(head);

    Node* ans = mergeSort(head);

    cout << "Sorted List: "<<endl;
    printList(ans);

    return 0;
}
