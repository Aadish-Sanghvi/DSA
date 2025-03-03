#include<iostream>
#include<stack>
using namespace std;

// USING ARRAY ----------------------------------------------------------------------------------------------------------------------------------
// class s{
//     //properties
//     public:
//     int *arr;
//     int size;
//     int top;
//     //behaviour
//     s(int size){
//         this -> size = size;
//         arr = new int[size];
//         top = -1;
//     }

//     void push(int element){
//         if(size - top > 1){
//             top++;
//             arr[top] = element;
//         }
//         else{
//             cout<<"stack overflow"<<endl;
//         }
//     }

//     void pop(){
//         if(top >= 0){
//             top--;
//         }
//         else{
//             cout<<"stack underflow"<<endl;
//         }
//     }

//     int peek(){
//         if(top >= 0){
//             return arr[top];
//         }
//         else{
//             cout<<"stack is empty"<<endl;      
//             return -1;
//         }
//     }

//     bool isEmpty(){
//         if(top == -1){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
// };

// int main(){
//     s st(5);
//     st.push(11);
//     st.push(12);
//     st.push(13);
//     st.push(12);
//     st.push(14);
//     st.push(17);

//     cout<<st.peek()<<endl;

//     if(st.isEmpty()){
//         cout<<"empty"<<endl;
//     }
//     else{
//         cout<<"not empty"<<endl;
//     }

//     return 0;
// }


//USING LINKED LIST ----------------------------------------------------------------------------------------------------------------------------------
//class for Linked List
class Node
{
    public:
        int data;
        Node* next;
        Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
class stack
{
    public:
    Node* top = NULL;
    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next=top;
        top=temp;
    }
    void pop()
    {
        if(top==NULL)
        {
            cout<<"stack is empty"<<endl;
        }
        else
        {
            int data = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
    int peek()
    {
        return top->data;
    }  
    int size()
    {
    	int cnt=0;
    	Node*size = top;
    	while(size!=NULL)
    	{
    		cnt++;
    		size=size->next;
		}
		return cnt;
	}
	bool isempty()
	{
	    if(top==NULL)
	    {
	        return true;
	    }
	    else 
	    {
	        return false;
	    }
	}
};
int main() {
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.pop();
    cout<<"top element is "<<st.peek()<<endl;
    if(st.isempty())
    {
        cout<<"stack is empty"<<endl;
    }
    else
    {
        cout<<"stack is not empty"<<endl;
    }
     cout<<"current size of stack is "<<st.size()<<endl;
    return 0;
}