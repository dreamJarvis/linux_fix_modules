/*
    Count of subsets with sum equal to X
    https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/
*/
#include <bits/stdc++.h>
using namespace std;

// ===================================== Memo =============================== //
unordered_map<string, int> dp;
int util(vector<int> &nums, int target, int n, int sum){
    string key = to_string(n) + '_' + to_string(sum);
    if(n < 0){
        if(sum == target)
            return 1;
        return 0;
    }

    if(dp.count(key))
        return dp[key];

    dp[key] = util(nums, target, n-1, sum+nums[n]) +
              util(nums, target, n-1, sum);

    return dp[key];
}

int countOfSubsets(vector<int> &arr, int target){
    int n = arr.size();
    return util(arr, target, n-1, 0);
}

// ================================= top down =================================== //
int countOfSubsetsTopDown(vector<int> &arr, int target){
    int n = arr.size();

    int dp[n+1][target+1];
    memset(dp, 0, sizeof dp);

    for(int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= target; j++){
            if(j >= arr[i-1])
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= target; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    return dp[n][target];
}

// Driver function
int main(){
    vector<int> arr({1, 2, 3, 3});
    int x = 6;

    // vector<int> arr({1, 4, 2, 6, 5, 3});
    // int x = 7;

    // vector<int> arr({1, 1, 1, 1});
    // int x = 1;

    // vector<int> arr({0,0,0,0,0,0,0,0,1});
    // int x = 1;

    // cout << countOfSubsets(arr,x) << endl;
    cout << countOfSubsetsTopDown(arr,x) << endl;

    return 0;
}
