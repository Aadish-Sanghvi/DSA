#include <iostream>
using namespace std;

int peakindex(int arr[],int n){
    
    int s=0,e=n-1;
    int mid=(s+e)/2;
    
    while(s<e){
        if(arr[mid]<arr[mid+1])
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
    int arr[8]={1, 2, 3, 4, 5, 4, 3, 2};
    int peak = peakindex(arr,8);
    cout<<"The peak element is: "<< arr[peak];
    return 0;
}