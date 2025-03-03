#include<iostream>
#include<stack>
using namespace std;

class SpecialStack{
    int mini;
    stack<int> s;

    public:
    void push(int data){
    //for first element
    if(s.empty()){
        s.push(data);
        mini = data;
        }
    else{
        if(data < mini){
            int val = 2*curr - mini;
            s.push(val);
            mini = val;
        }
        else{
            s.push(data);
        }
        }
    }
    void pop(){
        if(s.empty()){
            return -1;
        }
        int curr = s.top();
        s.pop();
        if(curr > mini){
            return curr;
        }
        else{
            int prevMin = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevMin;
        }
    }
    int top(){
        if(s.empty())
        return -1;
        
        int curr = s.top();

        if(curr < mini){
            return curr;
        }
        else{
            return mini;
        }
    }
    int getMin(){
        if(s.empty())
        return -1;

        return mini;
    }
}st;

int main(){
    
}
