/*
    518. Coin Change 2
    https://leetcode.com/problems/coin-change-2/
*/
#include <bits/stdc++.h>
using namespace std;

// ===================================== Memoisation ============================= //
// tc : O(n*amount)
// sc : O(n*amount)
unordered_map<string, int> dp;
int helper(vector<int> &coins, int amount, int n){
    string key = to_string(n) + '_' + to_string(amount);

    // base case
    if(n < 0){
        if(amount == 0){
            return 1;
        }
        return 0;
    }

    if(amount == 0){
        return 1;
    }

    if(dp.count(key))
        return dp[key];

    if(coins[n] > amount)
        return helper(coins, amount, n-1);
    else{
        dp[key] =   helper(coins, amount-coins[n], n) +
                    helper(coins, amount, n-1);
    }

    return dp[key];
}

int changeMemo(int amount, vector<int>& coins) {
    return helper(coins, amount, coins.size()-1);
}

// =================================== top down ================================//
// tc : O(n*amount)
// sc : O(n*amount)
int changeDP(int amount, vector<int>& coins){
    int n = coins.size();
    int dp[n+1][amount+1];
    memset(dp, -1, sizeof dp);

    // initialization
    for(int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= amount; j++){
            if(j >= coins[i-1]){
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][amount];
}

// ============================== Better/efficient solution ============================ //
// tc : O(n*m), m < amount
// tc : O(n*m), m < amount
int change(int amount, vector<int>& coins) {
    int dp[amount+1];
    memset(dp, 0, sizeof dp);

    // initialization
    dp[0] = 1;

    for (int coin : coins) {
        for (int x = coin; x <= amount; x++) {
            dp[x] += dp[x - coin];
        }
    }

    return dp[amount];
}

// Driver function
int main(){
    vector<int> coins({1, 2, 5});
    int amount = 5;

    // vector<int> coins({2});
    // int amount = 3;

    // vector<int> coins({10});
    // int amount = 10;

    // vector<int> coins({1, 2, 5});
    // int amount = 500;

    cout << changeMemo(amount, coins) << endl;
    // cout << changeDP(amount, coins) << endl;
    // cout << change(amount, coins) << endl;

    return 0;
}
