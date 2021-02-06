/*
    494. Target Sum
    https://leetcode.com/problems/target-sum/
*/
#include <bits/stdc++.h>
using namespace std;

/*
    tc : O(n * m)
    n -> no. of elements in the array
    m -> (s+Sum)/2
*/
class Solution {
public:
    //============================== memoisation ========================= //
    unordered_map<string, int> dp;
    int util(vector<int> &nums, int n, int target, int sum){
        string key = to_string(n) + '_' + to_string(sum);

        if(n == nums.size()){
            if(sum == target)
                return 1;
            return 0;
        }

        if(dp.count(key))
            return dp[key];

        dp[key] = util(nums, n+1, target, sum + nums[n]) +
                  util(nums, n+1, target, sum);

        return dp[key];
    }

    int findTargetSumWaysMemo(vector<int>& nums, int S){
        int n = nums.size();
        int sum = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        if(S > sum) return 0;
        if((S+sum)%2 != 0)  return 0;

        int s = (S + sum)/2;

        return util(nums, 0, s, 0);
    }

    // ======================== top down ================================= //
    int findTargetSumWaysTopDown(vector<int>& nums, int S) {
        int n = nums.size();
        int countOfZeroes = 0, sum = 0;

        for(auto &i:nums){
            sum += i;
            if(i==0)  countOfZeroes++;
        }

        /*we cant divided our array to have S diff,
        if even the totoal sum is < S */
        if(S > sum) return 0;

        /*
        if (S+sum)%2 is not even , the the subset s1, we want to find
        will come in points, that it simply means that our array can't be divided into 2 part's,
        such that we will get an subset s1

        according to questionss
                s1 - s2 = S             (eq 1)
                s1 + s2 = totalSum           (eq 2)
                ______________
                2s1 = S + totalSum

            =>  s1  = (S + totalSum)/2       (eq 3)

                now, for eq 3 to be valid , our s1 should be achievable, i.e.
                it is only possible to find s1, if (S + totalSum)%2 == 0,
                i.e. (S + totalSum) is even.
        */
        if((S+sum)%2 != 0)  return 0;

        int s = (S+sum)/2;

        int dp[n+1][s+1];
        memset(dp, -1, sizeof dp);

        // initialization
        for(int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for(int i = 1; i <= s; i++)
            dp[0][i] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= s; j++){
                // we will avoid 0's, as we have already taken them into account
                if(nums[i-1] == 0 || j < nums[i-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
            }
        }

        /*
            so adding or subtracting 0 won't make a difference to the total sum,
            but it can increase our number of subsets,
            as we can place them however we wish,
            so if we have n zeroes , than the total number of subsets formed = 2^n
            i.e if the count of subset s1 found in array is --> m,
            then the no. of subsets we can having n number of zeroes is --> m * 2^n

            ex : s1 = 3, and number of zeroes = 2;
            then we can have {0, s1}, {0, s1},  {0, 0, s1}, {0, 0, s1}
            now remember all these zeroes are at different indexes,
            so they will have different combinations
        */
        return (pow(2, countOfZeroes)*dp[n][s]);
    }
};

// Driver function
int main(){
    // vector<int> arr({1, 1, 1, 1, 1});
    // int S = 3;

    // vector<int> arr({1, 2, 1});
    // int S = 0;

    // vector<int> arr({1000});
    // int S = -1000;

    // vector<int> arr({1});
    // int S = 2;

    // vector<int> arr({7,9,3,8,0,2,4,8,3,9});
    // int S = 0;

    // vector<int> arr({1, 0});
    // int S = 1;

    // vector<int> arr({5,2,2,7,3,7,9,0,2,3});
    // int S = 9;

    vector<int> arr({0,0,0,0,0,0,0,0,1});
    int S = 1;

    Solution s;
    cout << s.findTargetSumWaysMemo(arr, S) << endl;

    return 0;
}
/*
[7,9,3,8,0,2,4,8,3,9]
0

[5,2,2,7,3,7,9,0,2,3]
9
*/
