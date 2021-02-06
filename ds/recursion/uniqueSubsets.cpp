/*
    leetcode 90. Subsets II
    https://leetcode.com/problems/subsets-ii/
*/
#include <bits/stdc++.h>
using namespace std;

// ========================= recursive method =========================== //
// tc : O(2^n)
class Solution {
public:
    // total number of of subsequence of n length string = 2^n
    // tc : O(2^n)
    void subsets(vector<int> nums, vector<int> list, set<vector<int>> &st){
        if(nums.size() == 0){
            st.insert(list);
            return ;
        }

        int top = nums[0];
        nums.erase(nums.begin()+0);

        subsets(nums, list, st);

        list.push_back(top);
        subsets(nums, list, st);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> st;

        sort(nums.begin(), nums.end());             // O(nlog(n))
        subsets(nums, vector<int>(), st);           // O(2^n)

        for(auto i:st){
            result.push_back(i);
        }

        return result;
    }
};

// =============================== iterative method ============================= //
// tc : O(n^3)
class SolutionII {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> map;
        for(auto i:nums)
            map[i]++;

        vector<vector<int>> result;
        result.push_back({});

        for(auto &i:map){
            int n = result.size();
            for(int j = 0; j < n; j++){
                vector<int> temp = result[j];
                for(int k = 0; k < i.second; k++){
                    temp.push_back(i.first);
                    result.push_back(temp);
                }
            }
        }

        return result;
    }
};

// Driver function
int main(){
    vector<int> arr({1, 2, 2});

    SolutionII s;

    vector<vector<int>> result = s.subsetsWithDup(arr);
    for(auto i:result){
        for(auto j:i)
            cout << j << ", ";
        cout << endl;
    }


    return 0;
}
