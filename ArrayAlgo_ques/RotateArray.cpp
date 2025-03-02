#include<iostream>
using namespace std;

void rotate (int arr[], int k){
    int temp[5];
    for(int i=0;i<5;i++){
        temp[(i+k)%5]=arr[i];
    }
    for(int i=0;i<5;i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;
    return;
}

int main(){
    int key;
    cout<<("Enter key: \n");
    cin>>key;
    int arr[5]={1,2,3,4,5};

    rotate(arr,key);
    return 0;
}