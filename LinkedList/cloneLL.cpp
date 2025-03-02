#include<iostream>
#include<unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* random;

    // Constructor
    Node(int d) {
        this -> data = d;
        this -> next = NULL;
        this -> random = NULL;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
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

// // APPROACH 1 --------------------------------------------------------------------------------
// Node* copyList(Node* head, Node* tail, int d){
//     // Step 1: create a clone list
//     Node* clonehead = NULL;
//     Node* clonetail = NULL;

//     Node* temp = head;

//     while(temp != NULL){
//         //clone -> next = temp -> data;
//         insertAtTail(clonehead, clonetail, temp -> data);
//         temp = temp -> next;
//     }

//     // Step 2: Create a map
//     unordered_map<Node*, Node*> oldToNewNode;
//     Node* originalNode = head;
//     Node* cloneNode = clonehead;

//     while(originalNode != NULL){
//         oldToNewNode[originalNode] = cloneNode;
//         originalNode = originalNode -> next;
//         cloneNode = cloneNode -> next;
//     }

//     originalNode = head;
//     cloneNode = clonehead;

//     while(originalNode != NULL){
//         cloneNode -> random = oldToNewNode[originalNode -> random];
//         originalNode = originalNode -> next;
//         cloneNode = cloneNode -> next;
//     }
//     return clonehead;
// }

// APPROACH 2 --------------------------------------------------------------------------------
Node* copyList(Node* head){

    // Step 1: Create a clone list
    Node* clonehead = NULL;
    Node* clonetail = NULL;
    Node* temp = head;

    while(temp != NULL){
        insertAtTail(clonehead, clonetail, temp -> data);
        temp = temp -> next;
    }

    // Step 2: Clone Nodes in between the original LL
    Node* originalNode = head;
    Node* cloneNode = clonehead;

    while(originalNode != NULL && cloneNode != NULL){
        Node* next = originalNode -> next; // to track to forward part
        originalNode -> next = cloneNode; 
        originalNode = next; // original node is updated

        //same steps for clone node
        next = cloneNode -> next; 
        cloneNode -> next = originalNode;
        cloneNode = next;
    }

    // Step 3: random pointer copy
    temp = head;
    while(temp != NULL){
        if(temp -> next != NULL){
            if(temp -> random != NULL){
                temp -> next -> random = temp -> random -> next;
            }
        }
        else{
            temp -> next = NULL;
        }
    }

    // Step 4: revert changes done in step 2
        originalNode = head;
        cloneNode = clonehead;
        while(originalNode != NULL && cloneNode != NULL){
        originalNode -> next = cloneNode -> next;
        originalNode = originalNode -> next;
        //same for clone node
        if(originalNode != NULL){
        cloneNode -> next = originalNode -> next;
        cloneNode = cloneNode -> next;
        }
    }   
    return clonehead;
}

int main() {
    // Create the original linked list with random pointers
    Node* originalHead = new Node(1);
    Node* originalTail = originalHead;
    insertAtTail(originalHead, originalTail, 2);
    insertAtTail(originalHead, originalTail, 3);
    insertAtTail(originalHead, originalTail, 4);
    insertAtTail(originalHead, originalTail, 5);

    // Set random pointers (for example, make the last node point to the second node)
    originalHead->random = originalHead->next->next->next->next;

    Node* temp = originalHead->next;
    temp->random = originalHead->next->next;
    temp = temp->next;
    temp->random = originalHead;
    temp = temp->next;
    temp->random = originalHead->next->next->next;
    temp = temp->next;
    temp->random = originalHead->next->next->next;

    // Copy the linked list
    //Node* clonedHead = copyList(originalHead, originalTail, 0);
    Node* clonedHead = copyList(originalHead);

    // Print the original and cloned linked lists
    cout << "Original List:" << endl;
    printList(originalHead);

    cout << "Cloned List:" << endl;
    printList(clonedHead);

    return 0;
}