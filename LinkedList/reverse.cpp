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

// ITERATIVE METHOD ---------------------------------------------------------

// Node* reverse(Node* &head) {
//     if (head == NULL || head->next == NULL) {
//         return head;
//     }

//     Node* prev = NULL;
//     Node* curr = head;
//     Node* forward = NULL;

//     while (curr != NULL) {
//         forward = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = forward;
//     }
//     head = prev;
//     return head;
// }

// RECURSIVE METHOD 1 ---------------------------------------------------------

// void recursion(Node* &head, Node* &curr, Node* &prev){
//     //base case
//     if (curr == NULL) {
//         head = prev;
//         return;
//     }
//     Node* forward = curr -> next;
//     recursion(head, forward, curr);
//     curr -> next = prev;
// }

// Node* reverse(Node* &head){
//     Node* curr = head;
//     Node* prev = NULL;
//     recursion(head, curr, prev);
//     return head;
// }

// RECURSIVE METHOD 2 ---------------------------------------------------------

// Function prototypes
Node* recursion(Node* &head);
Node* reverse(Node* &head);

// Recursive method to reverse the linked list
Node* recursion(Node* &head) {
    // Base case
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* chotahead = recursion(head->next);
    head->next->next = head;
    head->next = NULL;

    return chotahead;
}

// Wrapper function to call the recursive method and update the head
Node* reverse(Node* &head) {
    head = recursion(head); // Update head after reversing
    return head;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original Linked List: ";
    printList(head);

    reverse(head);

    cout << "Reversed Linked List: ";
    printList(head);

    return 0;
}