/*
    Count the number of subset with a given difference
    https://www.youtube.com/watch?v=ot_XBHyqpFc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=11
*/
#include <bits/stdc++.h>
using namespace std;

// ================================= Recusion ============================ //
// tc : O(2^n)
// sc : O(2^n)
int util(vector<int> &nums, int target, int n, int sum){
    if(n >= nums.size()){
        if(sum == target)
            return 1;
        return  0;
    }

    return (
        util(nums, target, n+1, sum+nums[n]) +
        util(nums, target, n+1, sum)
    );
}

int countOfSubsets(vector<int> &nums, int diff){
    int n = nums.size();
    int sum = 0;
    for(auto &i:nums)
        sum+=i;

    if(diff > sum) return 0;
    if((diff+sum)%2 != 0)  return 0;

    int s = (diff+sum)/2;

    return util(nums, s, 0, 0);
}

//=================================== memoisation ================================ //
// tc : O(n * |sum of all elements|/2)
// sc : O(n * |sum of all elements|/2)
unordered_map<string, int> dp;
int utilMemo(vector<int> &nums, int target, int n, int sum){
    string key = to_string(n) + '_' + to_string(sum);

    if(n == nums.size()){
        if(sum == target)
            return 1;
        return 0;
    }

    if(dp.count(key))
        return dp[key];

    dp[key] = util(nums, target, n+1, sum+nums[n])
              + util(nums, target, n+1, sum);
    return dp[key];
}

int countOfSubsetsMemo(vector<int> &nums, int diff){
    int sum = 0;
    for(auto &i:nums)
        sum += i;

    if(diff > sum) return 0;
    if((diff+sum)%2 != 0)  return 0;

    int s = (diff+sum)/2;

    return utilMemo(nums, s, 0, 0);
}

// ================================= top down =================================//
// tc : O(n * sum)
// sc : O(n * sum)
int countOfSubsetsTopDown(vector<int> &nums, int diff){
    int n = nums.size();
    int countOfZeroes = 0, sum = 0;

    for(auto &i:nums){
        sum += i;
        if(!i)  countOfZeroes++;
    }

    if(diff > sum) return 0;
    if((diff+sum)%2 != 0)  return 0;

    int s = (diff+sum)/2;

    int dp[n+1][s+1];
    memset(dp, -1, sizeof dp);

    for(int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for(int j = 0; j <= s; j++)
        dp[0][j] = 0;


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= s; j++){
            if(nums[i-1] && j >= nums[i-1])
                dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return (pow(2, countOfZeroes) * dp[n][s]);
}

// Driver function
int main(){
    // vector<int> arr({1, 1, 2, 3});
    // int diff = 1;

    // vector<int> arr({1, 2, 1});
    // int diff = 0;

    vector<int> arr({0,0,0,0,0,0,0,0,1});
    int diff = 1;

    // cout << countOfSubsets(arr, diff) << endl;
    // cout << countOfSubsetsMemo(arr, diff) << endl;
    cout << countOfSubsetsTopDown(arr, diff) << endl;

    return 0;
}
