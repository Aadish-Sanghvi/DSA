//mistake in code

#include <iostream>
using namespace std;

int binarysearch(int  n){
    
    int s=0;
    int e=n;
    int mid=(s+e)/2;
    int square=mid*mid;
    int ans=-1;
    
    while(s<=e){
        if(square==n){
            return mid;
        }
        if(square>n){
        ans=mid;    
        e=mid-1;
        }
        else if(square<n) {
        s=mid+1;
        }
    mid=(s+e)/2;
    }
    return -2;
}

int main() {
    int n,ans;  
    cout<<"Enter any no.\n";
    cin>>n;
    ans=binarysearch(n);
    cout<<"The ans is: "<<ans;
    return 0;
}