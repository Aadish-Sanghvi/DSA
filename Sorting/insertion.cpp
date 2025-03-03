#include<iostream>
using namespace std;

void insertionsort(){
    for(int i=1; i<n, i++)
    {
        int temp=arr[i];
        for(int j=i-1; j<=0; j--)
        {
            if(arr[j]>temp)
            arr[j+1]=arr[j];
            else //ruk jao
            break;
        }
        arr[j+1]=temp;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main() {
    int n=5;
    int arr[7]={10,1,7,4,8,2,11};
    cout << "Sorted array: \n";
    selectionsort(arr,n);
    return 0;
}
