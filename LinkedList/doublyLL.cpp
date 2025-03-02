#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *prev;
    Node *next;

    //constructor
    Node(int d){
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }
    //destructor
    ~Node(){
        int value = this -> data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout << "Memory is for node with data " << value << endl;
    }
};

void print(Node* &head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int getlength(Node* &head){
    int len = 0;
    Node* temp = head;
    while(temp!=NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}

void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head -> prev = temp; 
    head = temp;
}

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    temp -> prev = tail;
    tail -> next = temp;
    temp -> next = NULL;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int pos, int d){
    //inserting at afirst position
    if(pos == 1){
        insertAtHead(head,d);
        return;
    }

    int count = 1;
    Node* temp = head;
    while(count < (pos-1)){
        temp = temp -> next;
        count++;
    }

    //inserting at last position
    if(temp -> next == NULL){
        insertAtTail(tail,d);
        return;
    }

    //creating a node for d
    Node* nodetoinsert = new Node(d);
    nodetoinsert -> next = temp -> next;
    temp -> next -> prev = nodetoinsert;
    temp -> next = nodetoinsert;
    nodetoinsert -> prev = temp;

}

void deleteNode(int pos,  Node* &head){
    //deleting first or start node
    if(pos == 1){
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next; 
        temp -> next = NULL;
        delete temp;
    }
    //deleting middle or last node
    else{
        Node* curr = head;
        Node* prev = NULL;

        int count = 1;
        while(count < pos){
            prev = curr;
            curr = curr -> next;
            count++;
        }
        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print(head);
    cout<<"length is: "<<getlength(head)<<endl;

    insertAtHead(head,11);
    print(head);

    insertAtHead(head,1);
    print(head);

    insertAtHead(head,13);
    print(head);

    insertAtTail(tail,4);
    print(head);

    insertAtPosition(head, tail, 6, 66);
    print(head);

    insertAtPosition(head, tail, 1, 61);
    print(head);

    insertAtPosition(head, tail, 8, 68);
    print(head);

    deleteNode(8,head);
    print(head);
    
return 0;
}