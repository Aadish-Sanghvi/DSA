#include<iostream>
using namespace std;

int binarysearch(int arr[], int s, int e, int k){
    //base case element not found
    if(s>e)
    return -1;

    int mid = (s+e)/2;

    //base case element found
    if(arr[mid] == k){
        return mid;
    }
    

    if(arr[mid]<k){
        return binarysearch(arr,mid+1,e,k);
    }
    else{
        return binarysearch(arr,s,mid-1,k);
    }
}


int main(){
    int arr[6] = {2,4,6,10,14,16};
    int k = 4; 
    int ans = binarysearch(arr, 0, 5, k);

    if(ans == -1){
        cout<<"the element is absent"<<endl;
    }
    else{
        cout<<"the element is present at index "<<ans<<endl;
    }
    return 0;
}