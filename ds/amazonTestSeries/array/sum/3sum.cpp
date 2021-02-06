#include <bits/stdc++.h>
using namespace std;

// O(n^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            int s = i + 1, e = n - 1;
            while (s < e) {
                if ((nums[i] + nums[s] + nums[e]) == 0) {
                    bool flag = true;
                    if (ans.size() > 0) {
                        if (ans.back() == vector<int>({nums[i], nums[s], nums[e]})) flag = false;
                    }

                    if (flag)
                        ans.push_back({nums[i], nums[s], nums[e]});
                }

                if ((nums[i] + nums[s] + nums[e]) > 0) {
                    while (e > s && nums[e] == nums[e - 1]) e--;
                    e--;
                }
                else {
                    while (s < e && nums[s] == nums[s + 1]) s++;
                    s++;
                }

            }
        }
        return ans;
    }
};

// Driver function
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Solution s;
    std::vector<int> v({ -1, 0, 1, 2, -1, -4});
    // std::vector<int> v({ -1, 0, 1, 0});
    // std::vector<int> v({ 1, 2, -2, -1});
    // std::vector<int> v({3, 0, -2, -1, 1, 2});
    // std::vector<int> v({ -1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4});
    // std::vector<int> v({ -4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6});

    for (auto &i : s.threeSum(v)) {
        for (auto &j : i)
            cout << j << ", ";
        cout << endl;
    }

    return 0;
}
/*
[-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6]
*/