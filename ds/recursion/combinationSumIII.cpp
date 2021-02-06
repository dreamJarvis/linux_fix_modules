/*
    216. Combination Sum III
    https://leetcode.com/problems/combination-sum-iii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int size, int sum, vector<int> &list, vector<vector<int>> &result, int pos){
        if(list.size() == size && sum==0){
            result.push_back(list);
            return ;
        }

        if(sum < 0)
            return ;

        for(int i = pos; i <= 9; i++){
            list.push_back(i);
            helper(size, sum-i, list, result, i+1);
            list.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> temp;
        helper(k, n, temp, result, 1);
        return result;
    }
};

// Driver function
int main(){
    int k = 3, n = 9;

    Solution s;
    for(auto &i:s.combinationSum3(k, n)){
        for(auto &j:i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
