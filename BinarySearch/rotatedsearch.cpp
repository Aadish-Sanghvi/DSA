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

int binarysearch(int arr[] , int s , int e , int key){
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

int findposition(int arr[], int n, int k){
    int pivot = getpivot(arr,n);
    if(arr[pivot]<=k && arr[n-1]>=k)
    return binarysearch(arr , pivot , n-1 , k);
    else 
    return binarysearch(arr , 0 , pivot-1 , k);
}

int main(){
    
    int arr[5]={7,9,1,2,3};
    int ans = findposition(arr,5,2);
    cout<<"The element is at: "<<ans;
    return 0;
}
