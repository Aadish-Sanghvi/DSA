#include<iostream>
#include<vector>
using namespace std;

vector< vector < int > > ans;

void helper(vector<int> &candidates, int target, int i, int currsum, vector<int> temp){
    //Bounding Condition 
    if(currsum > target){
        return;
    }
    //Base Case
    if(i == candidates.size()){
        if(currsum == target){
            ans.push_back(temp);
        }
        return;
    }
    
    //recursive call
    //Inclusion
    currsum += candidates[i];
    temp.push_back(candidates[i]);
    helper(candidates,target,i,currsum,temp);
    currsum -= candidates[i];
    temp.pop_back();

    //Exclusion
    helper(candidates,target,i+1,currsum,temp);
    
return;
}

vector< vector<int> > combinationsum(vector<int> &candidates, int target){
    vector<int> temp;
    helper(candidates,target,0,0,temp);
    return ans;
}

int main(){
    vector<int> candidates;
    int target;
    int ele;
    int number;
    cout<<"Enter number of elements: "<<endl;
    cin>>ele;
    for(int i = 0; i<ele; i++){
        cout<<"Enter number: "<<endl;
        cin>>number;
        candidates.push_back(number);
    }
    cout<<"Enter the target sum you want: "<<endl;
    cin>>target;
    combinationsum(candidates,target);
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