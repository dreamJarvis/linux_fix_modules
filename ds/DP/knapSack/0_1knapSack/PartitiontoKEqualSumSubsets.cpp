/*
    698. Partition to K Equal Sum Subsets
    https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
*/
#include <bits/stdc++.h>
using namespace std;

// tc : O(n*2^n)
class Solution {
public:
    bool helper(vector<int> &nums, int n, int target, int sum, int k, vector<bool> &visited){
        if(k == 1)
            return true;

        if(n < 0 || sum < 0)
            return false;

        if(sum == 0){
            cout << k << endl;
            return helper(nums, nums.size()-1, target, target, k-1, visited);
        }

        // cout << "a" << endl;
        bool flag;
        if(nums[n] > sum || visited[n])
            return helper(nums, n-1, target, sum, k, visited);
        else{
            // if(!visited[n]){
            visited[n] = true;
            flag = helper(nums, n-1, target, sum-nums[n], k, visited);

            visited[n] = false;
            flag = flag || helper(nums, n-1, target, sum, k, visited);
            // }
        }

        return flag;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto &i:nums)
            sum += i;

        if(sum%k == 0){
            int target = sum/k;
            vector<bool> visited(nums.size(), false);
            return helper(nums, nums.size()-1, target, target, k, visited);
        }
        else
            return false;
    }
};

// Driver function
int main(){
    // vector<int> arr({4, 3, 2, 3, 5, 2, 1});
    // int k = 4;

    // vector<int> arr({1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1});
    // int k = 1;

    // vector<int> arr({2,2,2,2,3,4,5});
    // int k = 4;

    // vector<int> arr({10,10,10,7,7,7,7,7,7,6,6,6});
    // int k = 3;

    vector<int> arr({5,8,3,8,1,6,1,5,1,6});
    int k = 4;

    Solution s;
    cout << s.canPartitionKSubsets(arr, k) << endl;

    return 0;
}
/*
[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
1

[2,2,2,2,3,4,5]
4

[10,10,10,7,7,7,7,7,7,6,6,6]
3

[5,8,3,8,1,6,1,5,1,6]
4
*/
