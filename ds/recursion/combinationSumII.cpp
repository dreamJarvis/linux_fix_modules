/*
    40. Combination Sum II
    https://leetcode.com/problems/combination-sum-ii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(vector<int>& nums, vector<int> &temp, int target,
        int pos, vector<vector<int>> &result)
    {
        if(target == 0){
            result.push_back(temp);
            return;
        }

        if(target < 0)
            return ;

        for(int i = pos; i < nums.size(); i++){
            // to make sure we dont take repeated elements
            if(i == pos || nums[i] != nums[pos]){
                temp.push_back(nums[i]);
                helper(nums, temp, target-nums[i], i+1, result);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        helper(candidates, temp, target, 0, result);
        return result;
    }
};

// Driver function
int main(){
    vector<int> arr({10, 1, 2, 7, 6, 1, 5});
    int target = 8;
    // vector<int> arr({2, 5, 2, 1, 2});
    // int target = 5;

    Solution s;
    for(auto &i:s.combinationSum2(arr, target)){
        for(auto &j:i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
