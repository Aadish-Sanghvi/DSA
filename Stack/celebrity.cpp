#include<iostream>
#include<stack>
using namespace std;

bool knows(int M[][3], int a, int b, int n){
    if(M[a][b] == 1)
    return true;
    else 
    return false;
}

int celebrity(int M[][3], int n){
    stack<int> s;
    //push all elements in stack
    for(int i = 0; i<n; i++){            
        s.push(n);
    }
    while(s.size() > 1){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if(knows(M,a,b,n))
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }
    int candidate = s.top();
    //if single element which is present in the stack then verify it

    bool rowcheck = false;
    int zerocount = 0;
    int count = 0;
    for(int i = 0; i < n; i++){
        if(M[candidate][i] == 0){
            count++;
        }
    }
    //all zeros
    if(zerocount == n){
        rowcheck = true;
    }

    bool colcheck = false;
    int onecount = 1;
    count = 0;
    for(int i = 0; i < n; i++){
        if(M[candidate][i] == 1){
            count++;
        }
    }
    //all 1 except diagonal
    if(count == n-1){
        colcheck = true;
    }

    if(rowcheck == true && colcheck == true){
        return candidate;
    }
return -1;
}

int main()
{
	cout<<"enter the person"<<endl;
	int arr[3][3];
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>arr[i][j];
		}
	}
	cout<<"your chart is "<<endl;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	int finalans=celebrity(arr,3);
	cout<<"the celebrity is "<<finalans;
	return 0;
}
