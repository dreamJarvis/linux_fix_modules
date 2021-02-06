/*
    46. Permutations
    https://leetcode.com/problems/permutations-ii/submissions/

*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void helper(vector<int> nums, vector<vector<int>> &result, int pos){
        if(pos == nums.size()){
            result.push_back(nums);
            return ;
        }

        for(int i = pos; i < nums.size(); i++){
            /* here we are applying this knowing that our array is sorted
            and all the similar elements appear together, then we can vaoid all the
            repeated elements
            */
            if(i != pos && nums[i] == nums[pos])  continue;

            swap(nums[i], nums[pos]);
            helper(nums, result, pos+1);

            /* here we are not swapping back in order to maitain the order
            of the array,
            i mean if your gonna mess up the order by swapping up,
            the why did you even sorted the array ?

            remember we swapped back in-order to find all the permutations,
            even the repeated ones, but if we dont care about the repeated ones
            then dont swap back
             */
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        helper(nums, result, 0);
        return result;
    }

    // ========================== method 2 : easy one =========================== //
    // link : https://www.youtube.com/watch?v=A3ge2mdQi4g&t=95s
    void helperII(  vector<int> &nums, vector<int> &per,
                    vector<vector<int>> &result, vector<bool> &visited
    ){
        if(per.size() == nums.size()){
            result.push_back(per);
            return ;
        }

        for(int i = 0; i < nums.size(); i++){
            // in-order to avoid taking the current index again and again
            if(visited[i])    continue;

            visited[i] = true;
            per.push_back(nums[i]);

            helperII(nums, per, result, visited);

            per.pop_back();
            visited[i] = false;

            // to skip the repeated numbers
            while(i+1 < nums.size() && nums[i] == nums[i+1]) ++i;
        }
    }

    vector<vector<int>> permuteUniqueII(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() == 0)
            return result;

        sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false);

        vector<int> per;
        helperII(nums, per, result, visited);
        return result;
    }
};

// Driver function
int main(){
    vector<int> arr({1, 1, 2});
    Solution s;
    for(auto &i:s.permuteUniqueII(arr)){
        for(auto &j:i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
