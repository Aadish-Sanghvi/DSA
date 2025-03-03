#include<iostream>
using namespace std;

void isSorted(int arr[], int size){
    if(size == 0 || size == 1)
    {
        return;
    }

    if(arr[0] > arr[1])
    {
        cout<<"The array is not sorted"<<endl;
    }
    else
    {
        cout<<"The array is sorted"<<endl;
    }

    isSorted(arr +1  ,size - 1);
}

int main(){
    int arr[5] = {1,2,6,4,5};
    int n = 5;

    isSorted(arr,n);
    return 0;
}