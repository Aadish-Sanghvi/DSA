#include<iostream>
using namespace std;

class Queue{
    int *arr;
    int front;
    int rear;
    int size;
    public:
    Queue(int n){
        this->size = n;
        size = 10000;
        arr = new int[n];
        front = rear = -1;
    }

    bool enqueue(int value){
        if( (front == 0 && rear == size - 1) || (rear == (front - 1)%(size - 1)) )
        {
            cout << "Queue is full"<<endl;
            return false;
        }
        if(front == -1 )//first element
        {
            front = rear = 0;
        }
        else if(rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = value;
        return true;
    }
    int dequeue(){
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
    void display() {
        if (front == -1) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i < rear; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
}q;

int main() {
    Queue(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();

    q.dequeue();
    q.display();

    q.enqueue(4);
    q.enqueue(5);
    q.display();
    
    return 0;
}