#include<iostream>
#include<stack>
using namespace std;

class TwoStack{
    //properties
    public:
    int *arr;
    int size;
    int top1;
    int top2;
public: 
    //behaviour
    TwoStack(int s){
        this -> size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    void push1(int num){
        //atleast one empty space is present
        if(top1 - top2 > 1){
            top1++;
            arr[top1] = num;
        }
        else{
            cout<<"stack overflow"<<endl;
        }
        return;
    }
    void push2(int num){
        //atleast one empty space is present
        if(top1 - top2 > 1){
            top2--;
            arr[top2] = num;
        }
        else{
            cout<<"stack overflow"<<endl;
        }
        return;
    }
    int pop1(){
        if(top1 >= 0){
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else{
            return -1; 
        }
    }
    int pop2(){
        if(top2 < size){
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else{
            return -1;
        }
    }
};

int main(){
    TwoStack s(10);

    s.push1(2);
    s.push1(3); 
    s.push1(4);
    s.push1(5);

    s.push2(6);
    s.push2(7);
    s.push2(8);
    s.push2(9);

return 0;
}