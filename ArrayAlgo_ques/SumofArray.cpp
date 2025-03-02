// //not geting the approach

// #include<iostream>
// using namespace std;


// int add (int arr1[], int m , int arr2[] , int n ){
//     int sum;
//     int i=m-1;
//     int j=n-1;
//     int ans[4];
//     int carry=0;
//     while(i>=0 && j>=0){
//         sum=arr1[i]+arr2[j]+carry;
//         carry=sum/10;
//         sum=sum%10;
//         ans[i]=sum;
//         i--;
//         j--;
//         }
        
//         while(i>=0 && j==0){
//             sum=arr1[i]+carry;
//             carry=sum/10;
//             sum=sum%10;
//             ans[i]=sum;
//             i--;
//         }
        
//         while(j>=0 && i==0){
//             sum=arr2[j]+carry;
//             carry=sum/10;
//             sum=sum%10;
//             ans[j]=sum;
//             j--;
//         }
        
//         while(carry!=0){
//             sum=carry;
//             carry=sum/10;
//             sum=sum%10;
//             ans[i]=sum;
//         }

//         for(int i=0; i<m; i++){
//             cout<<ans[i]<<endl;
//         }
//     return 0;
// }   

// int main(){
//     int arr1[3]={9,9,9};
//     int arr2[3]={9,9,9};
    
//     add(arr1,3,arr2,3);
    
//     return 0;
// }



//another method 
#include<iostream>
using namespace std;

int add (int arr1[], int m , int arr2[] , int n ){
    int sum=0;
    int ans[4];
    int carry=0;
    int i=m-1;
    int j=n-1;
    while(i>=0 && j>=0){
        sum=arr1[i]+arr2[j]+carry;
        carry=sum/10;
        sum=sum%10;
        ans[m]=sum;
        i--;
        j--;
        }
        
    while(i>=0 && j==-1){
        sum=arr1[i]+carry;
        carry=sum/10;
        sum=sum%10;
        ans[i]=sum;
        i--;
    }
        
    while(j>=0 && i==-1){
        sum=arr2[j]+carry;
        carry=sum/10;
        sum=sum%10;
        ans[j]=sum;
        j--;
    }
    
    for(int i=0; i<m; i++){
        cout<<ans[i];
    }
    
return 0;
}   

int main(){
    int arr1[3]={9,9,9};
    int arr2[2]={9,9};
    
    add(arr1,3,arr2,2);
    
    return 0;
}