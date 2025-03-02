#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){             //parametric constructor
        this -> data = data;
        this -> next = NULL;
    }

    ~Node(){                    //destructor
        int value = this -> data;
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }

    cout<<"memory is free from node with data: "<<value<<endl;
    }
};

void insertAtHead(Node* &head, int d){
    Node *temp = new Node(d);
    temp -> next = head;         //temp ka next point krega head ko
    head = temp;
}

void insertAtTail(Node* &tail, int d){
    Node *temp = new Node(d);
    tail -> next = temp;
    tail = temp;
    //or tail = tail -> next;
}

void insertAtPosition(Node* &tail, Node* &head, int position, int d){
    Node* temp = head;
    int count = 1;

    if(position == 1){
        insertAtHead(head,d);
    }

    //insert at tail
    if(temp -> next == NULL){
        insertAtTail(tail,d);
        return;
    }

    while(count < position - 1){
        temp = temp -> next;
        count++;
    }

    //creating a node for d
    Node* nodetoinsert = new Node(d);
    
    nodetoinsert -> next = temp -> next;
    temp -> next = nodetoinsert;

}

void deleteNode(int position, Node* &head){
    //deleting form the start
    if(position == 1){
        Node *temp = head;
        head = head -> next;
        //start node ki memory free krr do through destructor
        temp -> next = NULL; 
        delete temp;
    }
    else{
        //deleting any middle or last node
        Node *curr = head;
        Node *prev = NULL;
        int count = 1;
        while(count < position){
            prev = curr;
            curr = curr -> next;
            count++;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp -> data<< " ";
        temp = temp -> next;
    } 
    cout<<endl;
}

int main(){
    Node* node1 = new Node(10);
    //cout << node1 -> data << endl;
    //cout << node1 -> next <<endl;

    //head pointed to node1
    Node *head = node1;
    //tail pointed to node1
    Node *tail = node1;
    
    print(head);

    insertAtTail(tail, 12);
    print(head);

    insertAtTail(tail, 15);
    print(head);

    insertAtPosition(tail,head,4,44);
    print(head);

    cout<< "head " << head -> data << endl;
    cout<< "tail " << tail -> data << endl;

    deleteNode(4,head);
    print(head);

    cout<< "head " << head -> data << endl;
    cout<< "tail " << tail -> data << endl;
return 0;
}