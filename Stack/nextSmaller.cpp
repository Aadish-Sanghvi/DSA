#include<iostream>
#include<stack>
using namespace std;

void nextSmallerElement(vector<int> &arr, int n){
    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for(int i = 0; i < n; i++){
        int curr = arr[i];
        while(s.top() >= curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }

    for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
    }

    return;
}


int main(){
    vector<int> vect;
 
    vect.push_back(2);
    vect.push_back(3);
    vect.push_back(1);

    nextSmallerElement(vect,3);

    return 0;
}