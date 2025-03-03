#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>& s, int x, int count){
    
    if((s.empty())){
        s.push(x);
        return;
    }
    int num = s.top();
    int cnt = ++count;
    s.pop();

    //recursive call
    solve (s, x, cnt);

    cout<<endl;
    cout<<cnt<<endl;

    s.push(num);

    cout<<endl;
    cout<<"after"<<endl;
}

stack<int> pushAtBottom(stack<int>& myStack, int x){
    solve(myStack,x,0);
    return myStack;
}

int main(){
    stack<int> s;
    s.push(7);
    s.push(1);
    s.push(4);
    s.push(5);
    int x = 9;

    // Call pushAtBottom to modify the stack
    pushAtBottom(s, x);

    // Print the modified stack
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}