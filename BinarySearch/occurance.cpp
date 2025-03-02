#include <iostream>
using namespace std;

int firstocc(int arr[], int n, int key){
    
    int s = 0;
    int e = n - 1;
    int mid = (s+e)/2;
    int ans=-1;
    
    while(s<=e){
        
        if(arr[mid]==key){
            ans=mid;
            e=mid-1;
        }
        
        else if(key>arr[mid])
        s=mid+1;
        else if(key<arr[mid])
        e=mid-1;
        mid=(s+e)/2;
        
    }
    return ans;
}

int lastocc(int arr[], int n, int key){
    
    int s = 0;
    int e = n - 1;
    int mid = (s+e)/2;
    int ans=-1;
    
    while(s<=e){
        
        if(arr[mid]==key){
            ans=mid;
            s=mid+1;
        }
        
        else if(key>arr[mid])
        s=mid+1;
        else if(key<arr[mid])
        e=mid-1;
        mid=(s+e)/2;
        
    }
    return ans;
}

int main() {
    int even[5]={1,2,3,3,5};
    //int odd[5]={3, 9, 11, 17, 18};\
    
    int index = firstocc(even,5,3);
    int inde = lastocc(even,5,3);
    cout<<" The first occurance is: \n"<<index;
    cout<<" The last occurance is: \n"<<inde;
    return 0;
}