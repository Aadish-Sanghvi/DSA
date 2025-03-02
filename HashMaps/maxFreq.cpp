#include<iostream>
#include<map>
#include<vector>
#include<climits>
#include<unordered_map>
using namespace std;

int maxFrequency(vector<int> &arr){
    unordered_map<int,int> count; 

    for(int i = 0; i < arr.size(); i++){
        count[arr[i]]++;
    }

    int maxi = INT_MIN;
    int ans = -1;

    for(auto i:count){
        if(i.second > maxi){
            maxi = i.second;
            ans = i.first;
        }
    }
    return ans;
}

int main(){
    vector<int> arr; // ans = 1
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(2); // here 2 and both have max freq. but we need to return the ans with lowest index

    cout << "The maximum freq. in the array is of number " << maxFrequency(arr) <<endl;
    return 0;
}