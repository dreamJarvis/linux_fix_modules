// leetcode 78. Subsets
#include <bits/stdc++.h>
using namespace std;

// recursive/backtracking Method
void subsets(vector<int> nums, vector<int> ans, vector<vector<int>>& result){
    if(nums.size() == 0){
        result.push_back(ans);
        return ;
    }

    int item = nums[0];

    nums.erase(nums.begin());

    subsets(nums, ans, result);
    ans.push_back(item);
    subsets(nums, ans, result);
}

// utility function
vector<vector<int>> subsetRecursive(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> ans;
    subsets(nums, ans, result);
    return result;
}

// iterative approach
vector<vector<int>> subsetIterative(vector<int>& nums) {
    vector<vector<int>> subs = {{}};

    for(int num:nums){
        int n = subs.size();

        for(int i = 0; i < n; i++){
            subs.push_back(subs[i]);
            subs.back().push_back(num);
        }
    }

    return subs;
}

// bits manipulation
vector<vector<int>> subsetsBitTechnique(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> result({{}});      // empty set

    int totalPossibleWays = pow(2, n);

    for(int i = 0; i < totalPossibleWays; i++){
        vector<int> ans;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                ans.push_back(nums[j]);
            }
        }

        result.push_back(ans);
    }

    return result;
}

// Driver function
int main(){
    vector<int> arr({1, 2, 3});

    for(auto i:subsetsBitTechnique(arr)){
        for(auto j:i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
