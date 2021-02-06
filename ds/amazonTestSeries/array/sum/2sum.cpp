#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++)
            index[nums[i]] = i;

        for (int i = 0; i < n; i++) {
            if (index.count(target - nums[i]) && index[target - nums[i]] != i) {
                return vector<int>({i, index[target - nums[i]]});
            }
        }

        return vector<int>({});
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Solution s;
    std::vector<int> v({2, 7, 11, 15});
    int target = 9;

    for (auto &i : s.twoSum(v, target))
        cout << i << ", ";
    cout << endl;

    return 0;
}