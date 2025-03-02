#include <iostream>
using namespace std;

int binarysearch(int arr[] , int size , int key){
    int s=0;
    int n=size;
    int e=n-1;
    int mid=(s+e)/2;

    while(s<=e){
        if(arr[mid]==key)
        return mid;
        else if(key>arr[mid])
        s=mid+1;
        else if(key<arr[mid])
        e=mid-1;

        mid=(s+e)/2;

    }
    return -1;
}

int main() {
    int arr[5]={1,3,8,10,17};
    int x = binarysearch(arr,5,10);
    cout<<"The element is at:"<<x;
    return 0;
}