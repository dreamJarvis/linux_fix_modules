/*
    leetcode 416. Partition Equal Subset Sum
    https://leetcode.com/problems/partition-equal-subset-sum/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // =========================== memoised ====================== //
    // // tc : O(n*m)
    // // sc : O(n*m)
    unordered_map<string, int> dp;
    bool util(vector<int> &nums, int n, int target){
        string key = to_string(n) + '_' + to_string(target);

        if(target == 0) return 1;
        if(n < 0)       return 0;

        if(dp.count(key))
            return  dp[key];

        if(nums[n] <= target){
             dp[key] =  util(nums, n-1, target-nums[n]) ||
                        util(nums, n-1, target);
        }

        return dp[key];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto &i:nums)
            sum += i;

        if(sum%2 != 0)  return 0;
        return util(nums, nums.size()-1, sum/2);
    }

    // ========================== DP ========================== //
    // tc : O(n*m)
    // sc : O(n*m)
    bool canPartitionDP(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto &i:nums)
            sum += i;

        if(sum%2 == 0){
            int target = sum/2;
            int dp[n+1][target+1] = {0};

            for(int i = 0; i <= n; i++)
                dp[i][0] = true;

            for(int i = 1; i <= target; i++)
                dp[0][i] = false;

            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= target; j++){
                    if(nums[i-1] <= j){
                        dp[i][j] = (dp[i-1][j-nums[i-1]] || dp[i-1][j]);
                    }
                    else
                        dp[i][j] = dp[i-1][j];
                }
            }

            return dp[n][target];
        }
        else
            return false;
    }
};

// Driver function
int main(){
    vector<int> arr({1, 5, 11, 5});
    // vector<int> arr({1, 2, 3, 5});

    Solution s;
    cout << s.canPartition(arr) << endl;

    return 0;
}
