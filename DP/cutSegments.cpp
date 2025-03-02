#include<iostream>
#include<vector>
using namespace std;

// 1. Using recursion
// int solve(int n, int x, int y, int z){
//     if(n == 0){
//         return 0;
//     }
//     if(n < 0){
//         return INT_MIN;
//     }

//     int a = solve(n-x, x, y, z) + 1;
//     int b = solve(n-y, x, y, z) + 1;
//     int c = solve(n-z, x, y, z) + 1;

//     return max(a,max(b,c));
// }

// int cutIntoSegments(int n, int x, int y, int z){
//     int ans = solve(n, x, y, z);
//     return ans;
// }

// int main(){
//     int n,x,y,z;
//     cout << "Enter the number: " << endl;
//     cin >> n;
//     cout << "Enter the segments: " << endl;
//     cin >> x >> y >> z;

//     cout << "The number of segments it can be cut into is: " << cutIntoSegments(n, x, y, z);
    
//     return 0;
// }




// 2. Top - Down or Recursion + memoization approach
// int solve(int n, int x, int y, int z, vector<int> &dp){
//     if(n == 0){
//         return 0;
//     }
//     if(n < 0){
//         return INT_MIN;
//     }
//     if(dp[n] != -1){
//         return dp[n];
//     }

//     int a = solve(n-x, x, y, z, dp) + 1;
//     int b = solve(n-y, x, y, z, dp) + 1;
//     int c = solve(n-z, x, y, z, dp) + 1;

//     dp[n] = max(a,max(b,c));

//     return dp[n];
// }

// int cutIntoSegments(int n, int x, int y, int z){
//     vector<int> dp(n+1, -1);
//     int ans = solve(n, x, y, z, dp);
//     return ans;
// }

// int main(){
//     int n,x,y,z;
//     cout << "Enter the number: " << endl;
//     cin >> n;
//     cout << "Enter the segments: " << endl;
//     cin >> x >> y >> z;

//     cout << "The number of segments it can be cut into is: " << cutIntoSegments(n, x, y, z);
    
//     return 0;
// }




// 3. Bottom-Up or Tabulation Form approach
int solve(int n, int x, int y, int z){
    vector<int> dp(n+1, -1); 
    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        //bcoz in previous function dp[n] depends upon dp[n-x, n-y, n-z]
        if((i-x) >= 0 && dp[i-x] != -1)
            dp[i] = max(dp[i], dp[i-x] + 1);
        if((i-y) >= 0 && dp[i-y] != -1)
            dp[i] = max(dp[i], dp[i-y] + 1);
        if((i-z) >= 0 && dp[i-z] != -1)
            dp[i] = max(dp[i], dp[i-z] + 1);
    }

    if(dp[n] < 0){
        return 0;
    }
    else{
        return dp[n];
    }
}

int cutIntoSegments(int n, int x, int y, int z){
    return solve(n, x, y, z);
}

int main(){
    int n,x,y,z;
    cout << "Enter the number: " << endl;
    cin >> n;
    cout << "Enter the segments: " << endl;
    cin >> x >> y >> z;

    cout << "The number of segments it can be cut into is: " << cutIntoSegments(n, x, y, z);
    
    return 0;
}




// 4. Space Optimisation -> not possible