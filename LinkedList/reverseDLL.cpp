#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    // Constructor
    Node(int d) {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* reverseDoublyLinkedList(Node* head) {
    Node* temp = NULL;
    Node* current = head;

    // Swap next and prev pointers for all nodes of the doubly linked list
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // Update the head to the last node which is now the first node
    if (temp != NULL) {
        head = temp->prev;
    }

    return head;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    cout << "Original Doubly Linked List: ";
    printList(head);

    head = reverseDoublyLinkedList(head);

    cout << "Reversed Doubly Linked List: ";
    printList(head);

    return 0;
}
