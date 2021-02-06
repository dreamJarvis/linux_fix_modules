/*
    0-1 Knapsack Problem | DP-10
    https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
*/
#include <bits/stdc++.h>
using namespace std;


// ==================== recursive ===================== //
// tc : O(2^n)
int util(vector<int> &value, vector<int> &weight, int W, int n){
    /* return 0, either when we are past the last item,
    or, we have crosses the max weight*/
    if(n == -1 || W == 0)
        return 0;

    /* if current weight exceeds the total current limit of weight,
    skip the current weight, and start a new recursive call from this weight,
    without including the current weight */
    if(weight[n] > W)
        return util(value, weight, W, n-1);

    /* else , we have 2 cases :
        Case 1: The item is included in the optimal subset.
        Case 2: The item is not included in the optimal set.
    */
    else
        return max(
            value[n] + util(value, weight, W-weight[n], n-1),       // case 1
            util(value, weight, W, n-1)                             // case 2
        );
}

int knapsack(vector<int> &value, vector<int> &weight, int W){
    return util(value, weight, W, value.size()-1);
}

// ============================== Memoisation ================================ //
// tc : O(N*W)
// sc : O(N*W)
int util(   vector<int> &value, vector<int> &weight,
            int W, int n, unordered_map<string, int> &dp)
{
    string key = to_string(n) + "_" + to_string(W);
    if(n == -1 || W == 0){
        return 0;
    }

    if(dp.count(key))
        return dp[key];

    if(weight[n] > W)
        return util(value, weight, W, n-1, dp);
    else{
        dp[key] = max(
                    value[n] + util(value, weight, W-weight[n], n-1, dp),
                    util(value, weight, W, n-1, dp)
                );
    }

    return dp[key];
}

int knapsackMemo(vector<int> &value, vector<int> &weight, int W){
    unordered_map<string, int> dp;
    return util(value, weight, W, value.size()-1, dp);
}

// top down approach
// tc : O(n*w)
// sc : O(n*w)
int knapsackDP(vector<int> &value, vector<int> &weight, int W){
    int n = value.size();
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    // initializing values
    // if the weight is zero, then no capacity can be satisfied
    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;

    // if capacity is 0, no weight can satisfy it
    for(int i = 0; i <= W; i++)
        dp[0][i] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= W; j++){
            if(j >= weight[i-1]){
                dp[i][j] = max(
                    value[i-1] + dp[i-1][j-weight[i-1]],
                    dp[i-1][j]
                );
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][W];
}

// Driver function
int main(){
    // vector<int> value ({60, 100, 120});
    // vector<int> weight ({10, 20, 30});
    // int W = 50;

    vector<int> value({1, 4, 5, 7});
    vector<int> weight({1, 3, 4, 5});
    int W = 8;


    // clock_t a, b, c;

    // a = clock();
    // cout << knapsack(value, weight, W) << endl;
    // a = clock() - a;

    // b = clock();
    // cout << knapsackMemo(value, weight, W) << endl;
    // b = clock() - b;

    // c = clock();
    cout << knapsackDP(value, weight, W) << endl;
    // c = clock() - c;

    // cout << "recur : " << a << endl;
    // cout << "Memo : " << b << endl;
    // cout << "DP : " << c << endl;

    return 0;
}
