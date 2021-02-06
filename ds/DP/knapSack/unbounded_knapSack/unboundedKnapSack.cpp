/*
    Unbounded Knapsack (Repetition of items allowed)
    https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/
*/
#include <bits/stdc++.h>
using namespace std;


// =========================== Memo =========================//
// tc : O(n*W)
// sc : O(n*W)
unordered_map<string, int> dp;
int util(vector<int> &value, vector<int> &weight, int W, int n){
    string key = to_string(n) + '_' + to_string(W);

    if(n == -1 || W == 0)
        return 0;

    if(weight[n] > W)
        return util(value, weight, W, n-1);
    else{
        if(!dp.count(key)){
            dp[key] = max(
                        value[n] + util(value, weight, W-weight[n], n),
                        util(value, weight, W, n-1)
                    );
        }
    }

    return dp[key];
}

int UnboundedKnapsack(vector<int> &value, vector<int> &weight, int W){
    return util(value, weight, W, value.size()-1);
}


// ============================== top down ========================= //
// tc : O(n*W)
// sc : O(n*W)
int UnboundedKnapsackDP(vector<int> &value, vector<int> &weight, int W){
    int n = value.size();
    int dp[n+1][W+1];
    memset(dp, 0, sizeof dp);

    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for(int i = 0; i <= W; i++)
        dp[0][i] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= W; j++){
            if(j >= weight[i-1]){
                dp[i][j] = max(
                    value[i-1] + dp[i][j-weight[i-1]],
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
    // vector<int> Wt({2, 1});
    // vector<int> Val({1, 1});
    // int W = 3;

    // vector<int> Wt({1, 50});
    // vector<int> Val({1, 30});
    // int W = 100;

    // vector<int> Val({10, 40, 50, 70});
    // vector<int> Wt({1, 3, 4, 5});
    // int W = 110;

    vector<int> Val({1, 4, 5, 7});
    vector<int> Wt({1, 3, 4, 5});
    int W = 8;

    cout << UnboundedKnapsack(Val, Wt, W) << endl;
    // cout << UnboundedKnapsackDP(Val, Wt, W) << endl;

    return 0;
}
/*
4 8
1 4 5 7
1 3 4 5
*/
