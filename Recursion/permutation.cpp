#include<iostream>
#include<vector>
using namespace std;

vector< vector< int > > ans;
void helper( vector<int> &nums, int i ){
    if(i == nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int j=i; j<nums.size(); j++){
        swap(nums[i],nums[j]);
        helper(nums,i+1);
        //backtracking
        swap(nums[i],nums[j]);
    }
return;
}

int main(){
    vector<int> num;
    int n,element;
    cout<<"Enter no. of elements"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
	{
		cout<<"enter an element to add to this vector";
		cin>>element;
		num.push_back(element);
	}
    helper(num,0);
return 0;
}