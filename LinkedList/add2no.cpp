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

Node* reverse(Node* head){
    Node* curr = head;
    Node* next = NULL;
    Node* prev = NULL;

    while(curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next; 
    }
    return prev;
}

void insertAtTail(Node*& head, Node*& tail, int val){
    Node* temp = new Node(val);
    if(head == NULL){
        head = temp;
        tail = temp;
        return; 
    }
    else{
        tail -> next = temp; 
        tail = temp;
    }
}

Node* add(Node* first, Node* second){
    int carry = 0;
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    
    while(first != NULL && second != NULL){
        int sum = carry + first -> data + second -> data;
        int digit = sum % 10;
        
        //create node and add in and LL
        insertAtTail(ansHead, ansTail, digit);
    
        carry = sum/10;
        
        first = first -> next;
        second = second -> next;
    }

    while(first != NULL){
        int sum = carry + first -> data;
        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
        first = first -> next;
    }

    while(second != NULL){
        int sum = carry + second -> data;
        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
        second = second -> next;
    }
    
    while(carry != 0){
        int sum = carry;
        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
    }

    return ansHead;
}

Node* addList(Node* first, Node* second){
    //reverse input LL
    first = reverse(first);
    second = reverse(second);

    //add 2 LL
    Node* ans = add(first, second);

    //reverse ans
    ans = reverse(ans);

return ans;
}

int main() {
    Node* first = new Node(4);
    first->next = new Node(5);

    Node* second = new Node(3);
    second->next = new Node(4);
    second->next->next = new Node(5);

    Node* ans = addList(first,second);
    printList(ans);

    return 0;
}