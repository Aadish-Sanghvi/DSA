#include <iostream>
using namespace std;

// Node class for the linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize node with given data
    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }
};

int getlength(Node* head){
    int len = 0;
    while(head != NULL){
        len++ ;
        head = head -> next;
    }
    return len;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


// APPROACH 2
// Node* findMiddle(Node* &head){
//     int len = getlength(head);
//     int ans = (len/2) + 1;
    
//     int cnt = 1;
//     Node* temp = head;
    
//     while(cnt < ans){
//         temp = temp -> next;
//         cnt ++;
//     }
//     return temp;
// }


// APPROACH 2
Node* findMiddle(Node* &head){
    //0 or 1 NODE
    if(head == NULL || head -> next == NULL)
    return head;
    
    //2 NODE
    if(head -> next -> next == NULL)
    return head -> next;
    
    Node* fast = head -> next;
    Node* slow = head;
    
    while(fast != NULL){
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }
        slow = slow -> next;
    }
    return slow;
}

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Linked List: ";
    printList(head);

    // Finding the middle node
    Node* middle = findMiddle(head);

    if (middle != nullptr) {
        cout << "Middle Node: " << middle->data << endl;
    } else {
       cout << "The list is empty." << endl;
    }
    return 0;
}