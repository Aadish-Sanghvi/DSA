#include<iostream>
#include<stack>
using namespace std;

void sortedInsert(stack<int>& stack, int num){
    if(stack.empty() || (!stack.empty() && stack.top() < num)){
        stack.push(num);
        return;
    }
    int n = stack.top();
    stack.pop();

    //recursive call
    sortedInsert(stack, num);

    stack.push(n);
}

void sortStack(stack<int>& stack){
    //base case
    if(stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();

    //recursive call
    sortStack(stack);

    sortedInsert(stack,num);
}

int main(){
    stack<int> s;

    s.push(5);
    s.push(-2);
    s.push(9);
    s.push(-7);
    s.push(3);

    sortStack(s);

    while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
    }

    return 0;
}