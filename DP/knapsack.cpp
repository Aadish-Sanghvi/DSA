#include<iostream>
#include<vector>
using namespace std;




// 1. Using Recursion
// int solve(vector<int> &weight, vector<int> &value, int index, int capacity){
//     // Base case: If there are no items left to consider or capacity becomes 0
//     if(index < 0 || capacity == 0){
//         return 0;
//     }

//     // If the weight of the current item exceeds the capacity, skip it
//     if(weight[index] > capacity){
//         return solve(weight, value, index - 1, capacity);
//     }

//     int incl = solve(weight, value, index-1, capacity - weight[index]) + value[index];

//     int excl = solve(weight, value, index-1, capacity) + 0;

//     int ans = max(excl, incl)

//     return ans;
// }

// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){
//     int ans = solve(weight, value, n-1, maxWeight);
//     return ans;
// }

// int main(){
//     vector<int> weight, value;
//     int n, w;

//     cout << "Enter the weight of Bag: " << endl;
//     cin >> w;

//     cout << "Enter the number of elements: " << endl;
//     cin >> n;

//     cout << "Enter weights: " << endl;
//     for(int i = 0; i < n; i++){
//         int input;
//         cin >> input;
//         weight.push_back(input);
//     }

//     cout << "Enter values: " << endl;
//     for(int i = 0; i < n; i++){
//         int input;
//         cin >> input;
//         value.push_back(input);
//     }

//     cout << "The max value can be robbed in given weight is: " << knapsack(weight, value, n, w);

//     return 0;
// }




// 2. Top - Down or Recursion + memoization approach
// int solve(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int> > &dp){
//     // Base case: If there are no items left to consider or capacity becomes 0
//     if(index < 0 || capacity == 0){
//         return 0;
//     }

//     // If the weight of the current item exceeds the capacity, skip it
//     if(weight[index] > capacity){
//         return solve(weight, value, index - 1, capacity, dp);
//     }

//     // If the value is already computed, return it from the dp array
//     if(dp[index][capacity] != -1){
//         return dp[index][capacity];
//     }

//     int incl = solve(weight, value, index-1, capacity - weight[index], dp) + value[index];

//     int excl = solve(weight, value, index-1, capacity, dp) + 0;

//     dp[index][capacity] = max(excl, incl);

//     return dp[index][capacity];
// }

// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){
//     //The dp array should have dimensions (n+1) x (maxWeight+1) to cover all possible combinations of items and capacities.
//     vector<vector<int> > dp(n+1, vector<int>(maxWeight+1, -1));
//     return solve(weight, value, n-1, maxWeight, dp);
// }

// int main(){
//     vector<int> weight, value;
//     int n, w;

//     cout << "Enter the weight of Bag: " << endl;
//     cin >> w;

//     cout << "Enter the number of elements: " << endl;
//     cin >> n;

//     cout << "Enter weights: " << endl;
//     for(int i = 0; i < n; i++){
//         int input;
//         cin >> input;
//         weight.push_back(input);
//     }

//     cout << "Enter values: " << endl;
//     for(int i = 0; i < n; i++){
//         int input;
//         cin >> input;
//         value.push_back(input);
//     }

//     cout << "The max value can be robbed in given weight is: " << knapsack(weight, value, n, w);

//     return 0;
// }





// 3. Bottom-Up or Tabulation Form approach
int solve(vector<int> &weight, vector<int> &value, int index, int capacity){
    // Step 1: Create dp vector
    vector<vector<int> > dp(index+1, vector<int>(capacity+1, 0));
    
    // Step 2: analyse the base case
    for(int i = 0; i <= index; i++){
        for(int j = 0; j < capacity; j++){
            // If the weight of the current item exceeds the capacity, skip it
            if(weight[i - 1] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                // Calculate the maximum value by either including or excluding the current item
                int incl = 
            }
        }
    }

}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){
    return solve(weight, value, n-1, maxWeight);
}

int main(){
    vector<int> weight, value;
    int n, w;

    cout << "Enter the weight of Bag: " << endl;
    cin >> w;

    cout << "Enter the number of elements: " << endl;
    cin >> n;

    cout << "Enter weights: " << endl;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        weight.push_back(input);
    }

    cout << "Enter values: " << endl;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        value.push_back(input);
    }

    cout << "The max value can be robbed in given weight is: " << knapsack(weight, value, n, w);

    return 0;
}