//Some problem,,, code is right

#include<iostream>
using namespace std;

void bubblesort(int arr[],int n){
for(int i=1; i<n; i++ ){
    for(int j=0; j<n-i; j++){
        if(arr[j]>arr[j+1]){
            int t= arr[i];
            arr[i]=arr[j];
            arr[j]=t;
        }
    }
}
for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main() {
    int n=5;
    int arr[5]={6,2,8,4,10};
    cout << "Sorted array: \n";
    bubblesort(arr,n);
    return 0;
}