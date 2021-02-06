/*
    60. Permutation Sequence
    https://leetcode.com/problems/permutation-sequence/
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsetsWithDup(vector<int> &nums){
    unordered_map<int, int> map;
    for(auto &i:nums)
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

// Driver function
int main(){
    vector<int> arr({1, 2, 2});

    for(auto &i:subsetsWithDup(arr)){
        for(auto &j:i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
