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

// APPROACH 1 ----------------------------------------------------------------------------------
// bool checkPalindrome(vector<int> arr){
//     int n = arr.size();
//     int s = 0;
//     int e = n-1;

//     while(s <= e){
//         if(arr[s] != arr[e]){
//             return 0;
//         }
//         s++;
//         e--;
//     }
//     return 1;
// }

// bool isPalindrome(Node* head){
//     vector<int> arr;

//     Node* temp = head;

//     while(temp != NULL){
//         arr.push_back(temp -> data);
//         temp = temp -> next;
//     }
//     return checkPalindrome(arr);
// }


// APPROACH 1 ----------------------------------------------------------------------------------
Node* getMid(Node* head){
    Node* slow = head;
    Node* fast = head -> next;

        while(fast != NULL){
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }
        slow = slow -> next;
    }
    return slow;
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

bool isPalindrome(Node* head){
    if(head -> next == NULL){
        return true;
    }

    //get mid
    Node* middle = getMid(head);

    //reverse LL
    Node* temp = middle -> next;
    middle -> next = reverse(temp);

    //comapre both halves
    Node* head1 = head;
    Node* head2 = middle -> next;

    while(head2 != NULL){
        if(head1 -> data != head2 -> data){
            return false;
        }
        head1 = head1 -> next;
        head2 = head2 -> next;
    }

    //repeat step 2
    temp = middle -> next;
    middle -> next = reverse(temp);

return true;
}


int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    //head->next->next->next = new Node(4);

    int ans = isPalindrome(head);

    if(ans == 0){
        cout<<"it's not a palindrome";
    }
    else{
        cout<<"it's a palindrome";
    }
    return 0;
}