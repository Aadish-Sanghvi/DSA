#include <iostream>
using namespace std;

int getpivot(int arr[],int n){
    
    int s=0,e=n-1;
    int mid=(s+e)/2;
    
    while(s<e){
        if(arr[mid]>=arr[0])
        {
            s=mid+1;
        }
        else
        {
        e = mid;
        }
        mid=(s+e)/2;
    }
    return s;
}

int main() {
    int arr[5]={3,8,10,17,1};
    int pivot = getpivot(arr,5);
    cout<<"The peak element is:"<<pivot;
    return 0;
}