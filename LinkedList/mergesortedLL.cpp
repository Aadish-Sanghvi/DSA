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

Node* solve(Node* first, Node* second){
    Node* curr1 = first;
    Node* next1 = curr1 -> next;
    Node* curr2 = second;
    Node* next2 = curr2 -> next;

    //if only one element is present in first list, point its next with entire second list
    if(first -> next == NULL){
        first -> next = second;
        return first;
    }

    while(next1 != NULL && curr2 != NULL){
        if(curr2 -> data <= next1 -> data && curr2 -> data >= curr1 -> data){
            //add nodes in between the lists
            curr1 -> next = curr2;
            next2 = curr2 -> next;
            curr2 -> next = next1;

            //updating pointer
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            //aage badhao
            curr1 = next1;
            next1 = next1 -> next;

            if(next1 == NULL){
                curr1 -> next = curr2;
                return first;
            }
        }
    }
}

Node* sortTwoLists(Node* first, Node* second){
    if(first == NULL){
        return second;
    }
    if(second == NULL){
        return first;
    }
    if(first -> data <= second -> data){
        return solve(first, second);
    }
    else{
        return solve(second, first); 
    }
}

int main() {
    Node* head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(5);
    head1->next->next->next = new Node(7);

    Node* head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);
    head2->next->next->next = new Node(8);

    cout << "Original List 1: "<<endl;
    printList(head1);
    cout << "Original List 2: "<<endl;
    printList(head2);

    Node* head = sortTwoLists(head1,head2);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}