// some mistake in code 
#include <iostream>
#include<iostream>
#include<vector>
using namespace std;

vector<string> key = {"", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
vector<string> ans;

void helper(int a[], int n, string temp, int i){
    if(i == n){
        ans.push_back(temp);
        return;
    }

    for(int j = 0; j<key[a[i]].size(); j++){
        helper(a,n,temp+key[a[i]][j], i+1);
    }
}

vector<string> possiblewords(int a[], int n){
    helper(a,n,"",0);
    return ans;
}

int main(){
    int a[10];
    int n;
    cout<<"Enter no of elements: "<<endl;
    cin>>n;
    for(int i = 0; i < n; i++){
        cout<<"Enter element "<<i+1<<" ";
        cin>>a[i];
    }

    possiblewords(a,n);
    for (int i = 0; i < ans.size(); i++){
    cout << ans[i] << endl;
    }
    
return 0;
}