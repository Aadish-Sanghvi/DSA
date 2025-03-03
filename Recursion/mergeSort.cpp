#include<iostream>
#include<vector>
using namespace std;

vector<int> merge(vector<int> &a, vector<int> &b){
    int sizeA = a.size();
    int sizeB = b.size();
    int i = 0;
    int j = 0;
    vector<int> ans;

    //compare and fill ans vector
    while(i < sizeA && j < sizeB){
        if(a[i]<b[j]){
            ans.push_back(a[i]);
            i++;
        }
        else{
            ans.push_back(b[j]);
            j++;
        }
    }

    //Add remaining elements from A
    while(i < sizeA){
        ans.push_back(a[i]);
        i++;
    }

    //Add remaining elements from A
    while(j < sizeB){
        ans.push_back(b[j]);
        j++;
    }

    return ans;
}

vector<int> mergeSort(vector<int> &nums, int s, int e){
    int mid = (s+e)/2;
    //Base Case
    if(s > e){
        return{};
    }
    if(s == e){
        return {nums[s]};
    }

    //merge sort call
    vector<int> a = mergeSort(nums,0,mid-1);
    vector<int> b = mergeSort(nums,mid+1,e);

    //merge
    return merge(a,b);
}

vector<int> sortArray(vector<int> &nums){
    int n = nums.size();
    return mergeSort(nums, 0, n-1);
}

int main(){
    vector<int> nums;
    int n;

    cout<<"Enter the number of elements: "<<endl;
    cin>>n;

    cout<<"Enter the array elements: "<<endl;
    for(int i = 0; i<n; i++){
        cin>>nums[i];
    }
    sortArray(nums);
    return 0;
}