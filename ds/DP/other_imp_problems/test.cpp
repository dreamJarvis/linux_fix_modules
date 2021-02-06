// 0/1 knapsack problem
#include <bits/stdc++.h>
using namespace std;

// recursive approach
int maxProfit(vector<int> &value, vector<int> &weight, int W, int n){
    // base condition
    if(n == 0 || W == 0){
        return 0;
    }

    // int includeKrnaH = 0, includeNhiKrnaH = 0;
    if(W - weight[n-1] >= 0)
        return max(
                    value[n-1] + maxProfit(value, weight, W - weight[n], n-1),
                    maxProfit(value, weight, W, n-1)
                );
    else
        return maxProfit(value, weight, W, n-1);
}

// ------ DP ------- //

// memoisation
int knapsackMemo(   vector<int> &value, vector<int> &weight, int W, int n,
                    vector<vector<int>> &dp, int capacity
){
    // string key = to_string(W) + "_" + to_string(n-1);   // key
    if(n == 0 || W == 0)    return 0;

    if(dp[n-1][W] != -1)    return dp[n-1][W];

    // // to see the filling of the matrix
    // for(int i = 0; i < value.size(); i++){
    //     for(int j = 0; j < capacity; j++)
    //         cout << dp[i][j] << "\t";
    //     cout << endl;
    // }
    // cout << "\n\n";

    if(W - weight[n-1] >= 0)
        return dp[n-1][W] =  max(  value[n-1] + knapsackMemo(value, weight, W - weight[n-1], n-1, dp, capacity),
                                knapsackMemo(value, weight, W, n-1, dp, capacity)
                            );
    else
        return dp[n-1][W] = knapsackMemo(value, weight, W, n-1, dp, capacity);
}

int maxProfitMemo(vector<int> &value, vector<int> &weight, int W){
    // unordered_map<string, int> dp;
    vector<vector<int>> dp(value.size(), vector<int>(W+1, -1));
    return knapsackMemo(value, weight, W, value.size(), dp, W+1);
}

// Tabulation method : (bottom-up approach)
int knapsackTabulationDP(vector<int> &value, vector<int> &weight, int W){
    // tabulation table
    int row = value.size();
    int dp[row+1][W+1];
    memset(dp, -1, sizeof(dp));     // initializing the table with -1

    // ab remaining table to fill krenge
    for(int n = 0; n <= row; n++){
        for(int w = 0; w <= W; w++){
            if(n == 0 || w == 0)
                dp[n][w] = 0;
            else if(weight[n-1] <= w)
                dp[n][w] = max(
                                (value[n-1] + dp[n-1][w - weight[n-1]]),
                                dp[n-1][w]
                            );
            else
                dp[n][w] = dp[n-1][w];
        }
    }

    return dp[row][W];
}

// Driver function
int main(){
    vector<int> value({60, 100, 120});
    vector<int> weight({10, 20, 30});
    int W = 50;
    // vector<int> value({10, 15, 40});
    // vector<int> weight({1, 2, 3});
    // int W = 6;

    // cout << maxProfit(value, weight, W, value.size()) << endl;
    // cout << maxProfitMemo(value, weight, W) << endl;
    cout << knapsackTabulationDP(value, weight, W) << endl;


    return 0;
}
