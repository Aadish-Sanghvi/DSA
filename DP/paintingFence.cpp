#include<iostream>
#include<vector>
using namespace std;



// 1. Recursive Solution
// int numberOfWays(int n, int k){
//     //base case
//     if(n == 1){
//         return k;
//     }
//     if(n == 2){
//         return k*k;
//     }
//     int ans = (numberOfWays(n-2, k) * (k-1)) + (numberOfWays(n-1, k) * (k-1));

//     return ans;
// }

// int main(){
//     int n, k;
//     cout << "Enter the number of posts and colours: " << endl;
//     cin >> n >> k;

//     cout << "The total ways to color the posts are: " << numberOfWays(n, k) << endl;

//     return 0;
// }




// 2. Top - Down or Recursion + memoization approach
// int numberOfWays(int n, int k){
//     vector<int> dp(n+1, -1);
//     if(n == 1){
//         return k;
//     }
//     if(n == 2){
//         return k*k;
//     }
//     if(dp[n] != -1){
//         return dp[n];
//     }

//     dp[n] = (numberOfWays(n-2, k) * (k-1)) + (numberOfWays(n-1, k) * (k-1));

//     return dp[n];
// }

// int main(){
//     int n, k;
//     cout << "Enter the number of posts and colours: " << endl;
//     cin >> n >> k;

//     cout << "The total ways to color the posts are: " << numberOfWays(n, k) << endl;

//     return 0;
// }



// 3. Bottom-Up or Tabulation Form approach
// int numberOfWays(int n, int k){
//     vector<int> dp(n+1, -1);
//     dp[1] = k;
//     dp[2] = k*k;

//     for(int i = 3; i <= n; i++){
//         dp[i] = (numberOfWays(i-2, k) * (k-1)) + (numberOfWays(i-1, k) * (k-1));
//     }

//     return dp[n];
// }

// int main(){
//     int n, k;
//     cout << "Enter the number of posts and colours: " << endl;
//     cin >> n >> k;

//     cout << "The total ways to color the posts are: " << numberOfWays(n, k) << endl;

//     return 0;
// }




// 4. Space Optimisation
int numberOfWays(int n, int k){
    int prev2 = k;
    int prev1 = k*k;

    for(int i = 3; i <= n; i++){
        int curr = (prev1 + prev2) * (k-1);
        prev2 = prev1; 
        prev1 = curr;
    }

    return prev1;
}

int main(){
    int n, k;
    cout << "Enter the number of posts and colours: " << endl;
    cin >> n >> k;

    cout << "The total ways to color the posts are: " << numberOfWays(n, k) << endl;

    return 0;
}