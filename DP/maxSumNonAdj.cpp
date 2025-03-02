#include<iostream>
#include<vector>
using namespace std;


// 1. Using Recursion
// int solve(vector<int> &nums, int n){
//     //right to left
//     //base case
//     if(n < 0){
//         return 0;
//     }
//     if(n == 0){
//         return nums[0];
//     }

//     int incl = solve(nums, n-2) + nums[n];
//     int excl = solve(nums, n-1) + 0;

//     return max(incl,excl);
// }

// int maximumNonAdjacentSum(vector<int> &nums){
//     int n = nums.size();
//     int ans = solve(nums, n-1);
//     return ans;
// }

// int main(){
//     vector<int> nums;
//     nums.push_back(9);
//     nums.push_back(9);
//     nums.push_back(8);
//     nums.push_back(2);

//     cout << "The maximum sum of non adj elements is: " << maximumNonAdjacentSum(nums);
//     return 0;
// }




// 2. Top - Down or Recursion + memoization approach
// int solve(vector<int> &nums, int n, vector<int> &dp){
//     //right to left
//     //base case
//     if(n < 0){
//         return 0;
//     }
//     if(n == 0){
//         return nums[0];
//     }
//     // step 3:
//     if(dp[n] != -1){
//         return dp[n];
//     }

//     int incl = solve(nums, n-2, dp) + nums[n];
//     int excl = solve(nums, n-1, dp) + 0;
//     // step 2:
//     dp[n] = max(incl,excl);

//     return dp[n];
// }

// int maximumNonAdjacentSum(vector<int> &nums){
//     int n = nums.size();
//     // step 1:
//     vector<int> dp(n+1, -1);
//     int ans = solve(nums, n-1,dp);
//     return ans;
// }

// int main(){
//     vector<int> nums;
//     nums.push_back(9);
//     nums.push_back(9);
//     nums.push_back(8);
//     nums.push_back(2);

//     cout << "The maximum sum of non adj elements is: " << maximumNonAdjacentSum(nums);
//     return 0;
// }



// 3. Bottom-Up or Tabulation Form approach
// int solve(vector<int> &nums){
//     int n = nums.size();
//     vector<int> dp(n, 0);

//     dp[0] = nums[0];

//     for(int i = 1; i < n; i++){
//         int incl = dp[i-2] + nums[i];
//         int excl = dp[i-1] + 0;
//         dp[i] = max(incl, excl);
//     }
//     return dp[n - 1];
// }

// int maximumNonAdjacentSum(vector<int> &nums){
//     return solve(nums);
// }

// int main(){
//     vector<int> nums;
//     nums.push_back(9);
//     nums.push_back(9);
//     nums.push_back(8);
//     nums.push_back(2);

//     cout << "The maximum sum of non adj elements is: " << maximumNonAdjacentSum(nums);
//     return 0;
// }



// 4. Space Optimisation
int solve(vector<int> &nums){
    int n = nums.size();
    int prev2 = 0;
    int prev1 = nums[0];

    for(int i = 1; i < n; i++){
        int incl = prev2 + nums[i];
        int excl = prev1 + 0;

        int ans = max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums){
    return solve(nums);
}

int main(){
    vector<int> nums;
    nums.push_back(9);
    nums.push_back(9);
    nums.push_back(8);
    nums.push_back(2);

    cout << "The maximum sum of non adj elements is: " << maximumNonAdjacentSum(nums);
    return 0;
}