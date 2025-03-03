#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isValidParenthesis(string expression){
    stack<char> s;
    for(int i = 0; i<expression.length(); i++){
        char ch = expression[i];

        if(ch == '(' || ch == '[' || ch == '{'){
            s.push(ch);
        }
        else{
            // for closing bracket
            if(!s.empty()){
                char top = s.top();
                if((top == '(' && ch == ')') || (top == '{' && ch == '}') || (top == '[' && ch == ']')){
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    return s.empty();
}

int main(){
    string expression = "{[()]}";
    
    if (isValidParenthesis(expression)) {
        cout << "The expression has valid parentheses." << endl;
    } else {
        cout << "The expression has invalid parentheses." << endl;
    }

    return 0;
}
