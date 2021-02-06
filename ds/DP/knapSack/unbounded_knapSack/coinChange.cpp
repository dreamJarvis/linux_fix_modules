/*
    322. Coin Change
    https://leetcode.com/problems/coin-change/
*/
#include <bits/stdc++.h>
using namespace std;

// =============================== Memo ============================ //
// tc : O(n*amount)
// sc : O(n*amount)
int dp[13][10001];
int util(vector<int>& coins, int amount, int n){
    if(n < 0)
        return INT_MAX-1;

    if(amount == 0)
        return 0;

    if(dp[n][amount] != -1)
        return dp[n][amount];

    if(coins[n] > amount)
        return util(coins, amount, n-1);
    else{
        dp[n][amount] = min(
                    1 + util(coins, amount-coins[n], n),
                    util(coins, amount, n-1)
                );

        return dp[n][amount];
    }
}

int coinChange(vector<int>& coins, int amount) {
    memset(dp, -1, sizeof(dp));
    int n = coins.size();
    int res = util(coins, amount, n-1);
    return res >= 10000 ? -1: res;
}

// ==================================== bottom up ==============================//
// tc : O(n*amount)
// sc : O(n*amount)
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();

    int dp[n+1][amount+1];
    memset(dp, 0, sizeof(dp));

    for(int i = 0; i <= amount; i++)
        dp[0][i] = INT_MAX-1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= amount; j++){
            if(j-coins[i-1] >= 0)
                dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-coins[i-1]]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][amount] >= 10000 ? -1 : dp[n][amount];
}

// ========================= top down approach ============================ //
// tc : O(n*amount)
// sc : O(n*amount)
int coinChangeDPII(vector<int>& coins, int amount) {
    int dp[amount+1];
    for(int i = 0; i <= amount; i++)
        dp[i] = amount+1;

    dp[0] = 0;
    for(int i = 1; i <=amount; i++)
        for(auto &coin:coins)
            if(i-coin >= 0)
                dp[i] = min(dp[i], dp[i-coin]+1);

    return (dp[amount] > amount ? -1 : dp[amount]);
}

// Driver function
int main(){
    vector<int> arr({1, 2, 5});
    int amount = 11;

    // vector<int> arr({2});
    // int amount = 3;

    // vector<int> arr({1});
    // int amount = 1;

    // vector<int> arr({1});
    // int amount = 0;

    // cout << coinChange(arr, amount) << endl;
    // cout << coinChangeDPI(arr, amount) << endl;
    cout << coinChangeDPII(arr, amount) << endl;

    return 0;
}
