#include<iostream>
using namespace std;

int linearsearch(int arr[], int n, int key){
    if(n == 0){
        return false; 
    }
    if(arr[0] == key){
        return true;
    }
    else{
        bool remainingpart = linearsearch(arr+1, n-1, key);
        return remainingpart;
    }
}

int  main(){
    int arr[5] = {1,2,3,4,5};
    int size = 5;
    int key = 8;
    bool ans = linearsearch(arr,size,key);

    if(ans){
        cout<<"present"<<endl;
    }
    else{
        cout<<"absent"<<endl;
    }
    return 0;
}