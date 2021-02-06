/*
    377. Combination Sum IV
    https://leetcode.com/problems/combination-sum-iv/
*/
#include <bits/stdc++.h>
using namespace std;

// ==================================== Memoisation ================================= //
// tc : O(n*amount)
// sc : O(n*amount)
unordered_map<string, double> dp;
int helper(vector<int>& nums, int target){
    string key = to_string(target);
    if(target == 0)
        return 1;

    if(target < 0)
        return 0;

    int count = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] <= target){
            if(!dp.count(key))
                count += helper(nums, target-nums[i]);
            else
                count = dp[key];
        }
    }

    dp[key] = count;
    return count;
}

int combinationSum4(vector<int>& nums, int target) {
    return helper(nums, target);
}

// ====================================== Bottom Up =========================== //
// tc : O(n*amount)
// sc : O(n*amount)
int combinationSum4DP(vector<int>& nums, int target) {
    vector<double> dp(target+1, 0);
    dp[0] = 1;

    for(int i = 1; i <= target; i++){
        for(auto &num:nums)
            if(num <= i)
                dp[i] += dp[i-num];
    }

    return dp[target];
}


// Driver function
int main(){
    // vector<int> arr({1, 2, 3});
    // int target = 4;

    vector<int> arr({3, 1, 2, 4});
    int target = 4;

    // vector<int> arr({3,33,333});
    // int target = 10000;

    cout << combinationSum4(arr, target) << endl;
    // cout << combinationSum4DP(arr, target) << endl;

    return 0;
}
/*
[3,33,333]
10000
*/
