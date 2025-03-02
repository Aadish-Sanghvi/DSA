#include<iostream>
#include<vector>
using namespace std;



// 1. Recursive Solution
// int countNoOfDearangements(int n){
//     if(n == 1){
//         return 0;
//     }
//     if(n == 2){
//         return 1;
//     }
//     int ans = (n-1) * (countNoOfDearangements(n-1) + countNoOfDearangements(n-2));
//     return ans;
// }

// int main(){
//     int n;
//     cout << "Enter any number" << endl;
//     cin >> n;

//     cout << "The total no. of dearangements are: " << countNoOfDearangements(n);
    
//     return 0;
// }




// 2. Top - Down or Recursion + memoization approach
// int countNoOfDearangements(int n){
//     vector<int> dp(n+1, -1);
//     if(n == 1){
//         return 0;
//     }
//     if(n == 2){
//         return 1;
//     }
//     if(dp[n] != -1){
//         return dp[n];
//     }
//     dp[n] = (n-1) * (countNoOfDearangements(n-1) + countNoOfDearangements(n-2));
//     return dp[n];
// }

// int main(){
//     int n;
//     cout << "Enter any number" << endl;
//     cin >> n;

//     cout << "The total no. of dearangements are: " << countNoOfDearangements(n);
    
//     return 0;
// }




// 3. Bottom-Up or Tabulation Form approach
// int countNoOfDearangements(int n){
//     vector<int> dp(n+1, 0);
//     dp[1] = 0;
//     dp[2] = 1;

//     for(int i = 3; i <= n; i++){
//         dp[i] = (i-1) * (dp[i-1] + dp[i-2]);
//     }

//     return dp[n];
// }

// int main(){
//     int n;
//     cout << "Enter any number" << endl;
//     cin >> n;

//     cout << "The total no. of dearangements are: " << countNoOfDearangements(n);
    
//     return 0;
// }



// 4. Space Optimisation
int countNoOfDearangements(int n){
    vector<int> dp(n+1, 0);
    int prev2 = 0;
    int prev1 = 1;

    for(int i = 3; i <= n; i++){
        int curr = (i-1) * (prev2 + prev1);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main(){
    int n;
    cout << "Enter any number" << endl;
    cin >> n;

    cout << "The total no. of dearangements are: " << countNoOfDearangements(n);
    
    return 0;
}