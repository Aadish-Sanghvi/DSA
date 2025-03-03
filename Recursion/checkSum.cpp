#include<iostream>
#include<vector>
using namespace std;

bool helper(vector<int> a, int sum, int tempsum, int i){
    if(sum == tempsum){
        return true;
    }

    if(i>=a.size()){
        return false;
    }

    int reccall1 = helper(a,sum,tempsum+a[i],i+1);
    int reccall2 = helper(a,sum,tempsum,i+1);

return reccall1 || reccall2 ;
}

int main(){
    vector<int> a;
    int sum;
    int element;
    for(int i = 0; i<6; i++){
        cout<<"Enter element "<<i+1<<": ";
        cin>>element;
        a.push_back(element);
    }
    cout<<"Enter the sum you wanna check "<<endl;
    cin>>sum;
    int ans = helper(a,sum,0,0);
    if(ans == 0){
        cout<<"Sum not matched "<<endl;
    } 
    if(ans == 1){
        cout<<"sum matched "<<endl;
    }
    return 0;
}