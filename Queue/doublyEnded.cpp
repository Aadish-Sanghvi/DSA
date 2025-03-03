#include<iostream>
using namespace std;

class Deque{
    int *arr;
    int front;
    int rear;
    int size;

    public:
    Deque(int n){
        int size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool pushFront(int x){
        //check full or not
        if( (front == 0 && rear == size - 1) || (rear == (front - 1)%(size - 1)) ){
            return false;
        }
        else if(front == -1){
            front = rear = 0;
        }
        else if(front == 0 && rear != size - 1){
            front = n-1;
        }
        else{
            front--;
        }
        arr[front] = x;
        return true;
    }
    bool pushRear(int x){
        //check full or not
        if( (front == 0 && rear == size - 1) || (rear == (front - 1)%(size - 1)) ){
            return false;
        }
        else if(front == -1){
            front = rear = 0;
        }
        else if(rear == n-1; front != 0){
            rear = 0;
        }
        else{
            rear++;
        }
        arr[rear] = x;
        return true;
    }
    int popFront(){
        if(front == -1){ // to check queue is empty
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear){ //single element is present
            front = rear = -1;
        }
        else if(front == size - 1){ //to maintain cyclic relation 
            front = 0;
        }
        else{
            front++;
        }
        return ans;
    }
    int popRear(){
        if(front == -1){ // to check queue is empty
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;
        if(front == rear){ //single element is present
            front = rear = -1;
        }
        else if(rear == 0){ //to maintain cyclic relation 
            rear = size - 1;
        }
        else{//normal flow
            rear--;
        }
        return ans;
    }
}q;

int main(){
    
    return 0;
}