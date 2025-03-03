#include <iostream>
using namespace std;

void selectionsort(int arr[],int n){
    for (int i = 0; i < n-1; i++ ){
            int minindex=i;
        for (int j = i+1; j < n ;j++ ){
            if(arr[minindex]>arr[j])
                minindex=j;
            }
            int temp = arr[minindex];
            arr[minindex]=arr[i];
            arr[i]=temp;
            for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
    }
}

int main() {
    int n=5;
    int arr[5]={6,2,8,4,10};
    cout << "Sorted array: \n";
    selectionsort(arr,n);
    return 0;
}