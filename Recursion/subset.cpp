#include<iostream>
#include<vector>
using namespace std;

vector< vector<int> > ans;
void helper(vector<int> a, vector<int> temp, int i){
    if(i == a.size()){
        ans.push_back(temp);
        return;
    }
    //take
    temp.push_back(a[i]);
    helper(a,temp,i+1);
    //not take
    temp.pop_back();
    helper(a,temp,i+1);
    return;
}

vector< vector<int> > subset(vector<int> &a){
    vector<int> temp;
    helper(a,temp,0);
    return ans;
}

int main(){
    vector<int> a;
    int n;
    int element;
    cout<<"Enter no. of elements"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
	{
		cout<<"enter an element: ";
		cin>>element;
		a.push_back(element);
	}
    vector< vector<int> > ans = subset(a);
    
    cout<<"The subsets are as follows: "<<endl;
    for (int i = 0; i < ans.size(); i++) 
    { 
        for (int j = 0; j < ans[i].size(); j++) 
        { 
            cout << ans[i][j] << " "; 
        }     
        cout << endl; 
    }
return 0;
}