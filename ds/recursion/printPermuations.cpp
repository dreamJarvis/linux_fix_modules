/*
    https://leetcode.com/problems/permutations/submissions/
    46. Permutations
*/
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void helper(vector<int> nums, vector<int> list,
        vector<vector<int>> &result)
    {
        if(nums.size() == 0){
            result.push_back(list);
            return ;
        }

        vector<int> temp = nums;
        for(int i = 0; i < nums.size(); i++){
            int element = nums[i];

            nums.erase(nums.begin()+i);
            list.push_back(element);

            helper(nums, list, result);

            list.pop_back();
            nums = temp;
        }
    }

    vector<vector<int>> permuteI(vector<int>& nums) {
        vector<vector<int>> result;
        helper(nums, vector<int>(), result);
        return result;
    }

    // =========================  method 2 ======================
    void helperII(vector<int> nums, vector<vector<int>> &result, int pos){
        if(pos == nums.size()){
            result.push_back(nums);
            return ;
        }

        for(int i = pos; i < nums.size(); i++){
            swap(nums[i], nums[pos]);
            helperII(nums, result, pos+1);
            swap(nums[i], nums[pos]);
        }
    }

    vector<vector<int>> permuteII(vector<int>& nums) {
        vector<vector<int>> result;
        helperII(nums, result, 0);
        return result;
    }
};

int main(){
    vector<int> arr({1, 2, 3});

    Solution s;
    // vector<vector<int>> result = s.permute(arr);
    for(auto &i:s.permuteII(arr)){
        for(auto &j:i)
            cout << j << " ";
        cout << endl;
    }

	return 0;
}
