/*
    377. Combination Sum IV
    https://leetcode.com/problems/combination-sum-iv/
*/
#include <bits/stdc++.h>
using namespace std;

// ==================================== Memoisation ================================= //
/*
tc : O(n*amount)
sc : O(n*amount)

we are finding the total number of possibilities it would give us to make an target,
now in this we are continiously decreasing the target, (in the for loop),
in order to avoid the overlapping sub-problems we will just store it,
as we are going depth first, all the smallest targets, will be filled first,
then those values will be used to fill out the bigger values of target,
eventually we will fill the values in the original target value

i would recommend to draw the recursive tree, and find out the overlapping sub-problems
*/
unordered_map<string, double> dp;
int helper(vector<int>& nums, int target){
    string key = to_string(target);

    if(target == 0)
        return 1;

    if(target < 0)
        return 0;

    // count's the total no. of combination that will give me the current target
    int count = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] <= target){
            /*
            if the target already exist we will just get our value
            from the stored value in out dp,
            we wont have to recur again
            */
            if(!dp.count(key))
                count += helper(nums, target-nums[i]);
            else
                count = dp[key];
        }
    }

    // we will store the total combination for this current target
    dp[key] = count;
    return count;
}

int combinationSum4(vector<int>& nums, int target) {
    return helper(nums, target);
}

// ====================================== Bottom Up =========================== //
// tc : O(n*amount)
// sc : O(n*amount)

/*
    https://leetcode.com/problems/combination-sum-iv/discuss/835673/C%2B%2B-solution-well-commented
    similar to climbing stairs question
*/
int combinationSum4DP(vector<int>& nums, int target) {
    vector<double> dp(target+1, 0);

    dp[0] = 1;

    for(int i = 1; i <= target; i++){
        for(auto &num:nums)
            if(i-num >= 0)
                dp[i] += dp[i-num];
    }

    return dp[target];
}


// Driver function
int main(){
    vector<int> arr({1, 2, 3});
    int target = 4;

    // vector<int> arr({3, 1, 2, 4});
    // int target = 4;

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
