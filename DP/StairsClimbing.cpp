#include<iostream>
#include<vector>
using namespace std;

// int solve(int nStairs, int i){
//     // base case
//     if(i == nStairs){
//         return 1;
//     }
//     if(i > nStairs){
//         return 0;
//     }
//     return (solve(nStairs, i+1) + solve(nStairs, i+2));
// }

// int countDistinctWaysToClimbStairs(int nStairs){
//     int ans = solve(nStairs, 0);
//     return ans;
// }

// int main(){
//     int n;
//     cout << "Enter the no. of stairs" << endl;
//     cin >> n;

//     cout << "The distinct ways to climb stairs is: " << countDistinctWaysToClimbStairs(n);

//     return 0;
// }



// // 1. Min Cost of Climbing Stairs
// int solve(vector<int> &cost, int n){
//     // base case
//     if(n == 0){
//         return cost[0];
//     }
//     if(n == 1){
//         return cost[1];
//     }
//     return min(solve(cost, n-1) , solve(cost, n-2)) + cost[n];
// }

// int minCostClimbingStairs(vector<int> &cost){
//     int n = cost.size();
//     int ans = min(solve(cost, n-1), solve(cost, n-2));
//     return ans;
// }

// int main(){
//     vector<int> cost;
//     cost.push_back(1);
//     cost.push_back(100);
//     cost.push_back(1);
//     cost.push_back(1);
//     cost.push_back(1);
//     cost.push_back(100);
//     cost.push_back(1);
//     cost.push_back(1);
//     cost.push_back(100);
//     cost.push_back(1);

//     cout << "The minimum cost of climbing stairs is: " << minCostClimbingStairs(cost);
//     return 0;
// }



// // 2. Top - Down or Recursion + memoization approach
// int solve(vector<int> &cost, int n, vector<int> &dp){
//     // base case
//     if(n == 0){
//         return cost[0];
//     }
//     if(n == 1){
//         return cost[1];
//     }

//     //step 3:
//     if(dp[n] != -1){
//         return dp[n];
//     }

//     //step 2:
//     dp[n] = min(solve(cost, n-1, dp) , solve(cost, n-2, dp)) + cost[n];
//     return dp[n];
// }

// int minCostClimbingStairs(vector<int> &cost){
//     int n = cost.size();
//     vector<int> dp(n+1, -1);
//     int ans = min(solve(cost, n-1, dp), solve(cost, n-2, dp));
//     return ans;
// }

// int main(){
//     vector<int> cost;
//     cost.push_back(1);
//     cost.push_back(100);
//     cost.push_back(1);
//     cost.push_back(1);
//     cost.push_back(1);
//     cost.push_back(100);
//     cost.push_back(1);
//     cost.push_back(1);
//     cost.push_back(100);
//     cost.push_back(1);

//     cout << "The minimum cost of climbing stairs is: " << minCostClimbingStairs(cost);
//     return 0;
// }




// // 3. Bottom-Up or Tabulation Form approach
// int solve(vector<int> &cost, int n){
//     //step 1:
//     vector<int> dp(n+1);
//     //step 2:
//     dp[0] = cost[0];
//     dp[1] = cost[1];

//     //step 3:
//     for(int i = 2; i < n; i++){
//         dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
//     }
//     return min(dp[n - 1], dp[n - 2]);
// }

// int main(){
//     vector<int> cost;
//     cost.push_back(1);
//     cost.push_back(100);
//     cost.push_back(1);
//     cost.push_back(1);
//     cost.push_back(1);
//     cost.push_back(100);
//     cost.push_back(1);
//     cost.push_back(1);
//     cost.push_back(100);
//     cost.push_back(1);

//     cout << "The minimum cost of climbing stairs is: " << solve(cost, cost.size());
//     return 0;
// }



// 4. Space Optimisation
int solve(vector<int> &cost, int n){

    int prev1 = cost[0];
    int prev2 = cost[1];

    for(int i = 2; i < n; i++){
        int curr = cost[i] + min(prev1, prev2);
        prev2 = prev1;
        prev1 = curr;
    }
    return min(prev1, prev2);
}

int main(){
    vector<int> cost;
    cost.push_back(1);
    cost.push_back(100);
    cost.push_back(1);
    cost.push_back(1);
    cost.push_back(1);
    cost.push_back(100);
    cost.push_back(1);
    cost.push_back(1);
    cost.push_back(100);
    cost.push_back(1);

    cout << "The minimum cost of climbing stairs is: " << solve(cost, cost.size());
    return 0;
}