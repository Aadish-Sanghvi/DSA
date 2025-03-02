#include<iostream>
#include<map>
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

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// APPROACH - 1
// bool detectloop(Node* head){
//     if(head == NULL){
//         return false;
//     }
//     map<Node* , bool> visited;
//     Node* temp = head;
//     while(temp != NULL){
//         if(visited[temp] == true){
//             return true;
//         }
//         visited[temp] = true;
//         temp = temp -> next;
//     }
//     return false;
// }


// APPROACH - 2 (FLOYD'S CYCLE DETECTION ALGO)
Node* floyddetectloop(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){
        fast = fast -> next;
        
        if(fast != NULL){
            fast = fast -> next;
        }
        slow = slow -> next;
        if(slow == fast){
            return slow;
        }
    }
    return NULL;
}

Node* getStartingNode(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* intersection = floyddetectloop(head);
    Node* slow = head;

    while(slow != intersection){
        slow = slow -> next;
        intersection = intersection -> next;
    }
    return slow;
}

void removeLoop(Node* head){
    if(head == NULL){
        return;
    }

    Node* start = getStartingNode(head);
    Node* temp = start;

    while(temp -> next != start){
        temp = temp -> next;
    }
    temp -> next = NULL;
    return;
}

int main() {
    // Creating a sample linked list: 10 -> 12 -> 15 -> 22 
    Node* head = new Node(10);
    head->next = new Node(12);
    head->next->next = new Node(15);
    head->next->next->next = new Node(22);
    
    //making cycle
    head->next->next->next->next = head->next;

    // if(detectloop(head)){
    //     cout<<"cycle is present"<<endl;
    // }
    // else{
    //     cout<<"cycle is absent"<<endl;
    // }

    if (floyddetectloop(head) != NULL){
        cout<<"cycle is present"<<endl;
    }
    else{
        cout<<"cycle is absent"<<endl;
    }

    cout<<"starting at: "<<getStartingNode(head) -> data <<endl;
    
    removeLoop(head);
    printList(head);

    return 0;
}

