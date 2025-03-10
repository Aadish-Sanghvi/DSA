#include<iostream>
#include<vector>

using namespace std;
 
void merge(int arr1[], int m, int arr2[], int n, int arr3[]){
    int i=0,j=0,k=0;
    while(i<m && j<n){
        if(arr1[i]<arr2[j]){
            arr3[k++]=arr1[i++];
        }
        else{
            arr3[k++]=arr2[j++];
        }
    }

    while(i<m){
        arr3[k++]=arr1[i++];
    }

    while(j<n){
        arr3[k++]=arr2[j++];
    }

    for(i=0;i<m+n;i++)
    printf("%d\n",arr3[i]);
    return;
} 

int main(){
    int arr1[5]={1,3,5,7,9};
    int arr2[4]={2,4,6,8};
    int arr3[9]={0};
    merge(arr1,5,arr2,4,arr3);
    return 0;
}
