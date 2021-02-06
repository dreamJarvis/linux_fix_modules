/*
    leetcode 77. Combinations
    https://leetcode.com/problems/combinations/
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> result;
public:
    void helper(int n, vector<int> list, int pos, int k){
        if(list.size() == k){
            result.push_back(list);
            return;
        }

        for(int i = pos; i <= n; i++){
            list.push_back(i);
            helper(n, list, pos+=1, k);
            list.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        helper(n, vector<int>(), 1, k);
        return result;
    }
};

// Driver function
int main(){
    int n = 4, k = 2;

    Solution s;
    for(auto i:s.combine(n, k)){
        for(auto j:i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
