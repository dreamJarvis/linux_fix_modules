/*
    Power Set Using Recursion
    https://practice.geeksforgeeks.org/problems/power-set-using-recursion/1/?track=sp-recursion&batchId=105

    78. Subsets
    https://leetcode.com/problems/subsets/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // recursive Solution : O(2^n)
    void helper(vector<int> nums, vector<int> list, vector<vector<int>> &result){
        if(nums.size()==0){
            result.push_back(list);
            return;
        }

        int tp = nums[0];
        nums.erase(nums.begin());

        helper(nums, list, result);

        list.push_back(tp);
        helper(nums, list, result);
    }

    vector<vector<int>> subsetsRecursive(vector<int>& nums) {
        vector<vector<int>> result;
        helper(nums, vector<int>(), result);

        return result;
    }

    // iterative Solution : O(n^2)
    vector<vector<int>> subsetsIterative(vector<int>& nums) {
        vector<vector<int>> result = {{}};

        for(auto &num:nums){
            int n = result.size();
            for(int j = 0; j < n; j++){
                result.push_back(result[j]);
                result.back().push_back(num);
            }
        }

        return result;
    }

    // bitwise Solution : O(n^2)
    vector<vector<int>> subsetsBit(vector<int>& nums) {
        int n = nums.size();
        int totalSubsets = 1 << n;
        vector<vector<int>> result(totalSubsets);

        for(int i = 0; i < totalSubsets; i++){
            for(int j = 0; j < n; j++){
                if(i&(1<<j))
                    result[i].push_back(nums[j]);
            }
        }

        return result;
    }
};

// Driver function
int main(){
    vector<int> arr({1, 2, 3});

    Solution s;
    for(auto i:s.subsetsBit(arr)){
        for(auto j:i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
