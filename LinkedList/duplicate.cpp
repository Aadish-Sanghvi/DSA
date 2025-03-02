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

// Method - 1 -----------------------------------------------------------------------------------
// Node* sortList(Node* head) {

//     int zeroCount = 0;
//     int oneCount = 0;
//     int twoCount = 0;

//     Node* temp = head;
//     while(temp != NULL){
//         if(temp -> data == 0){
//             zeroCount++;
//         }
//         else if(temp -> data == 1){
//             oneCount++;
//         }
//         else if(temp -> data == 2){
//             twoCount++;
//         }
//         temp = temp -> next;
//     }

//     temp = head;
//     while(temp != NULL){
//         if(zeroCount != 0){
//             temp -> data = 0;
//             zeroCount--;
//         }
//         else if(oneCount != 0){
//             temp -> data = 1;
//             oneCount--;
//         }
//         else if(twoCount != 0){
//             temp -> data = 2;
//             twoCount--;
//         }
//         temp = temp -> next;
//     }
// return head;
// }

// Method - 1 -----------------------------------------------------------------------------------

void insertAtTail(Node* &tail, Node* curr){
    tail -> next = curr;
    tail = curr;
}

Node* sortList(Node* head){
    //dummy nodes
    Node* zerohead = new Node(-1);
    Node* zerotail = zerohead;
    Node* onehead = new Node(-1);
    Node* onetail = onehead;
    Node* twohead = new Node(-1);
    Node* twotail = twohead;

    Node* curr = head;
    //create seprate list for 0,1,2
    while(curr != NULL){
        int value = curr -> data;
        if(value == 0){
        insertAtTail(zerotail, curr);            
        }
        else if(value == 1){
            insertAtTail(onetail, curr);
        }
        else if(value == 2){
            insertAtTail(twotail, curr);
        }
        curr = curr -> next;
    }

    if(onehead -> next != NULL){  //one list is not empty
        zerotail -> next = onehead -> next;
    } 
    else{
        zerotail -> next = twohead -> next;
    }

    onetail -> next = twohead -> next;
    twotail -> next = NULL;

    //setup head
    head = zerohead -> next;

    //delete dummy nodes
    delete zerohead;
    delete onehead;
    delete twohead;

return head;
}


int main() {
    Node* head = new Node(1);
    head->next = new Node(0);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);

    cout << "Original List: ";
    printList(head);

    head = sortList(head);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}