#include <iostream>
using namespace std;

class Queue {
private:
    int size;
    int* arr;
    int front;
    int rear;

public:
    Queue(){
        size = 10000;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    bool isEmpty() {
        if(front == rear){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int data) {
        if (rear == size) {
            cout << "Queue is full. Cannot enqueue.\n";
            return;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if (front == rear) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return -1;
        }
        else{
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if(front == rear){
                front = 0;
                rear = 0;
            }
        return ans;
        }        
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
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
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();

    q.dequeue();
    q.display();

    q.enqueue(4);
    q.enqueue(5);
    q.display();

    int front = q.peek();
    cout << "The front element is: "<< front;
    
    return 0;
}
