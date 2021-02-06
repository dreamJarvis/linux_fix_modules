/*
    39. Combination Sum
    https://leetcode.com/problems/combination-sum/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(vector<int> &nums, vector<int> &temp, int target, int pos, vector<vector<int>> &result){
        if(target < 0){
            return ;
        }

        if(target == 0){
            result.push_back(temp);
            return;
        }

        for(int i = pos; i < nums.size(); i++){
            temp.push_back(nums[i]);
            helper(nums, temp, target-nums[i], i, result);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        helper(candidates, temp, target, 0, result);
        return result;
    }
};

// Drier function
int main(){
    // vector<int> arr({2, 3, 6, 7});
    // int target = 7;
    vector<int> arr({2, 3, 5});
    int target = 8;

    Solution s;
    for(auto &i:s.combinationSum(arr, target)){
        for(auto &j:i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
