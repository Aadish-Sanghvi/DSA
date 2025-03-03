#include<iostream>
#include<stack>
using namespace std;

//STRING REVERSE --------------------------------------------------------------------------------
// int main(){
//     string str = "babbar";

//     stack<char> s;

//     for(int i = 0; i<str.length(); i++){
//         char ch = str[i];
//         s.push(ch);
//     }

//     string ans = "";

//     while(!s.empty()){
//         char ch = s.top();
//         ans.push_back(ch);
//         s.pop();
//     } 
//     cout<< "answer is: " << ans << endl;
//     return 0;
// }

//INT STACK REVERSE --------------------------------------------------------------------------------

void insertAtBottom(stack<int>& s, int x){
    if((s.empty())){
        s.push(x);
        return;
    }
    int num = s.top();
    s.pop();

    //recursive call
    insertAtBottom(s, x);
    
    s.push(num);
}

void reverseStack(stack<int>& stack){
    if(stack.empty()){
        return;
    }
    int num = stack.top();
    stack.pop();

    reverseStack(stack);
    insertAtBottom(stack,num);
}

int main(){
    stack<int> s;   
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    reverseStack(s);

    while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
    }

    return 0;
}