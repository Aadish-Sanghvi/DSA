#include<iostream>
#include<vector>
using namespace std;



// 1. Using Recursion and similarly create it for all other methods
int solve(vector<int> &houses, int n){
    //base case
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return houses[0];
    }

    int incl = solve(houses, n-2) + houses[n];
    int excl = solve(houses, n-1) + 0;

    return max(incl,excl);
}

int maximumRobberyNonAdjacentHouses(vector<int> &houses){
    int n = houses.size();
    int ans = solve(houses, n-1);
    return ans;

    vector<int> first, second;
    for(int i = 0; i < n-1; i++){
        if(i != n-1)
            first.push_back(houses[i]);
        if(i != 0)    
            second.push_back(houses[i]);
    }

    return max(solve(first, n-1), solve(second, n-1));
}

int main(){
    vector<int> houses;
    houses.push_back(1);
    houses.push_back(2);
    houses.push_back(3);
    houses.push_back(4);
    houses.push_back(5);
    houses.push_back(6);
    houses.push_back(7);
    houses.push_back(8);

    cout << "The maximum sum of non adj houses is: " << maximumRobberyNonAdjacentHouses(houses);
    return 0;
}

