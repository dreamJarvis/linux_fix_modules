/*
    746. Min Cost Climbing Stairs
*/
#include <bits/stdc++.h>
using namespace std;

// ============================== recursion =============================== //
// tc : O(2^n)
int util(vector<int>& cost, int n){
    if(n < 0)   return 0;
    if(n == 0 || n == 1)    return cost[n];

    return (
        cost[n] + min(util(cost, n-1), util(cost, n-2))
    );
}

int minCostClimbingStairsRecur(vector<int>& cost){
    int n = cost.size();
    return min (
        util(cost, n-1),
        util(cost, n-2)
    );
}

// ============================== Memoisation =============================== //
// tc : O(n)
// sc : O(n)
int utilHelper(vector<int>& cost, int n, int *dp){
    if(n < 0)   return 0;

    if(n == 0 || n == 1)    return cost[n];

    if(dp[n])
        return dp[n];

    dp[n] = cost[n] + min(
                        utilHelper(cost, n-1, dp),
                        utilHelper(cost, n-2, dp)
                    );

    return dp[n];
}

int minCostClimbingStairsMemo(vector<int>& cost){
    int n = cost.size();
    int dp[n+1];
    memset(dp, 0, sizeof(dp));

    return (
        min(
            utilHelper(cost, n-1, dp),
            utilHelper(cost, n-2, dp)
        )
    );
}

// ================================ top-down ======================================== //
// tc : O(n)
// sc : O(n)
int minCostClimbingStairsDP(vector<int>& cost){
    int n = cost.size();
    vector<int> dp(n+1, 0);

    for(int i = 0; i < n; i++)
        dp[i] = cost[i];

    for(int i = 2; i <= n; i++){
        dp[i] = dp[i] + min(dp[i-1], dp[i-2]);
    }

    return dp[n];
}

// ============================= constant space complexity ======================== //
// tc : O(n)
// sc : O(1)
int minCostClimbingStairsII(vector<int>& cost){
    int n = cost.size();
    int first = cost[0];
    int second = cost[1];

    if(n <= 2)  return min(first, second);

    for(int i = 2; i < n; i++){
        int curr = cost[i] + min(first, second);
        first = second;
        second = curr;
    }

    return min(first, second);
}

// Driver function
int main(){
    // vector<int> costs({10, 15, 20});
    // vector<int> costs({1, 100, 1, 1, 1, 100, 1, 1, 100, 1});
    // vector<int> costs({0, 0, 1, 0});
    // vector<int> costs({0, 0, 0, 1});

    // cout << minCostClimbingStairs(costs) << endl;
    cout << minCostClimbingStairsMemo(costs) << endl;
    // cout << minCostClimbingStairsDP(costs) << endl;

    return 0;
}
/*
1, 100, 1, 1, 1, 100, 1, 1, 100, 1
*/
