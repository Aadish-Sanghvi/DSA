// some mistake

#include <iostream>
#include <math.h>
using namespace std;

bool ispossible(int stalls[], int k, int mid){
    
    int cowcount = 1;
    int firstpos = stalls[0];
    
    for(int i=0; i<5 ; i++){
        if (stalls[i]-firstpos >=mid){
            cowcount ++ ;
            if (cowcount==k)
            return true;
        }
        firstpos=stalls[i];
    }
    return false;
}

int aggressivecows(int stalls[],int k){
    
    int s=0;
    int maxi=0;
    int ans=0;
    int sum=0;
    
    for(int i=0;i<5;i++){
        sum+=stalls[i];
        maxi=max(maxi,stalls[i]);
    }
    
    int e=maxi;
    int mid=(s+e)/2;
    
    while(s<=e){
        if(ispossible(stalls,k,mid)){
            ans=mid;
            e=mid + 1;
        }
        else{
            s=mid - 1;
        }
        mid=(s+e)/2;
    }
    return ans;
}

int main() {
    int arr[5];
    for(int i=0;i<4;i++){
        cin>>arr[i];
    }
    
    int answer = aggressivecows(arr,2);
    cout<<"The answer is= "<<answer;
    return 0;
}