// odd col -->  bottom to top print
// even col -->  top to bottom print

#include<iostream>
using namespace std;

int wave_print(int arr[][], int nrow, int mcol)
{
    for(int col = 0; col < mcol ; col++)
    {
        if(col & 1)
        {//odd index
            for(int row = nrow-1; row>=0; row--)
            {
                cout << arr[row][col] <<" ";
            }
        }
        else
        {//even index
            for(int row = 0; row < nrow; row++)
            {
                cout << arr[row][col] << " ";
            }
        }
    }
return 0;
}

int main(){
    int arr[3][3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<arr[i][j];
        }
    }
    wave_print(arr[][],3,3);
return 0;
}