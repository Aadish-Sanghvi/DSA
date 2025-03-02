#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* kreverse(Node* &head, int k){
    if(head ==  NULL){
        return NULL;
    }
    // step 1: reverse first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int cnt = 0;

    while(curr != NULL && cnt < k){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    //step 2: recursion dekh lega aage ka
    if(next != NULL){
        head -> next = kreverse (next,k);
    }

    //step 3: return head of reversed list
    return prev;     
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    
    cout << "Original Linked List: ";
    printList(head);

    head = kreverse(head,2);

    cout << "Reversed Linked List: ";
    printList(head);

    return 0;
}