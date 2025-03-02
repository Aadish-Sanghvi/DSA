#include<iostream>
#include<vector>
#include <climits>
using namespace std;


// // 1. Using simple recursion
// int minimumNoOfCoins(vector<int> &num, int x){
//     // base case
//     if(x == 0){
//         return 0;
//     }
//     if(x < 0){
//         return -1;
//     }
//     int mini = INT_MAX;
//     for(int i = 0; i < num.size(); i++){
//         int ans = minimumNoOfCoins(num, x - num[i]);
//         // if answer is valid
//         if(ans != -1 || ans != INT_MAX){
//             mini = min(mini, 1+ans);
//         }
//     }
//     return (mini == INT_MAX) ? -1 : mini; // Check if mini remains INT_MAX
// }

// int main(){
//     int x;
//     cout << "Enter the amount: " << endl;
//     cin >> x;

//     int n;
//     cout << "Enter Number of Coins" << endl;
//     cin >> n;
    
//     vector<int> coins;
//     int input;
//     cout << "Enter coins: " << endl;
//     for(int i = 0; i < n; i++){
//         cin >> input;
//         coins.push_back(input);
//     }

//     cout << "The minimum no. of coins required is: " << minimumNoOfCoins(coins, x);

//     return 0;
// }




// // 2. Top - Down or Recursion + memoization approach
// int solve(vector<int> &num, int x, vector<int> &dp){
//     // base case
//     if(x == 0){
//         return 0;
//     }
//     if(x < 0){
//         return -1;
//     }

//     if(dp[x] != -1){
//         return dp[x];
//     }

//     int mini = INT_MAX;
//     for(int i = 0; i < num.size(); i++){
//         int ans = solve(num, x - num[i], dp);
//         // if answer is valid
//         if(ans != -1 || ans != INT_MAX){
//             mini = min(mini, 1+ans);
//         }
//     }
//     dp[x] = mini;

//     return mini; // Check if mini remains INT_MAX
// }

// int minimumNoOfCoins(vector<int> &num, int x){
//     vector<int> dp(x+1, -1);
//     int ans = solve(num, x, dp);
//     if(ans == INT_MAX)
//         return -1;
//     else
//         return ans;
// }

// int main(){
//     int x;
//     cout << "Enter the amount: " << endl;
//     cin >> x;

//     int n;
//     cout << "Enter Number of Coins" << endl;
//     cin >> n;
    
//     vector<int> coins;
//     int input;
//     cout << "Enter coins: " << endl;
//     for(int i = 0; i < n; i++){
//         cin >> input;
//         coins.push_back(input);
//     }

//     cout << "The minimum no. of coins required is: " << minimumNoOfCoins(coins, x);

//     return 0;
// }




// 3. Bottom-Up or Tabulation Form approach
int solve(vector<int> &num, int x){
    vector<int> &dp(x+1, INT_MAX);
    dp[0] = 0;

    for(i = 1; i <= x; i++){
        // solving every amount from 1 to x
        for(int j = 0; j < num.size(); j++){
            dp[i] = min(dp[i], 1+dp[i-num[j]]);
        }
    }
}

int minimumNoOfCoins(vector<int> &num, int x){
    vector<int> dp(x+1, -1);
    int ans = solve(num, x, dp);
    if(ans == INT_MAX)
        return -1;
    else
        return ans;
}

int main(){
    int x;
    cout << "Enter the amount: " << endl;
    cin >> x;

    int n;
    cout << "Enter Number of Coins" << endl;
    cin >> n;
    
    vector<int> coins;
    int input;
    cout << "Enter coins: " << endl;
    for(int i = 0; i < n; i++){
        cin >> input;
        coins.push_back(input);
    }

    cout << "The minimum no. of coins required is: " << minimumNoOfCoins(coins, x);

    return 0;
}