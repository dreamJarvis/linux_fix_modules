#include <bits/stdc++.h>
using namespace std;

// O(n^2)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int minDiff = INT_MAX, maxSum = INT_MIN;
        for (int i = 0; i < n - 2; i++) {
            if (i && nums[i] == nums[i - 1]) continue;

            int s = i + 1, e = n - 1;
            while (s < e) {
                int sum = nums[i] + nums[s] + nums[e];
                int diff = abs(target - sum);

                if (sum == target) {
                    return sum;
                }
                else if (minDiff > diff) {
                    minDiff = diff;
                    maxSum = sum;
                } else if (minDiff == diff) {
                    maxSum = max(maxSum, sum);
                }

                if (sum > target) {
                    while (e - 1 > s && nums[e] == nums[e - 1])e--;
                    e--;
                }
                else {
                    while (s + 1 < e && nums[s] == nums[s + 1])s++;
                    s++;
                }
            }
        }

        return maxSum;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif

    vector<int> arr({ -1, 2, 1, -4});
    int target = 1;

    // vector<int> arr({ 1, 1, -1, -1, 3});
    // int target = -1;

    Solution s;

    cout << s.threeSumClosest(arr, target) << endl;

    return 0;
}
/*
Input
[1,1,-1,-1,3]
-1
Output
1
Expected
-1
*/