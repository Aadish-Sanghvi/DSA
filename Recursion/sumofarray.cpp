#include<iostream>
using namespace std;

int sumofarray(int arr[], int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return arr[0];
    }
    int remainingpart = sumofarray( arr + 1, n - 1 );
    int sum = arr[0] + remainingpart;
    return sum;
}

int main(){
    int arr[5] = {1,2,3,4,5};
    int size = 5;

    int ans = sumofarray(arr, size);
    cout<<"the sum of elements of array is = "<< ans;
    return 0;
}