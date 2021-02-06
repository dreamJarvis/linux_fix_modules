#include <bits/stdc++.h>
using namespace std;

// O(n^2)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> results;

        sort(arr.begin(), arr.end());

        for (int i = 0; i < (int)arr.size() - 3; i++) {
            // if condition to skip duplicates x 1's
            if (i == 0 || arr[i] != arr[i - 1]) {
                for (int j = i + 1; j < (int)arr.size() - 2; j++) {
                    // if condition to skip duplicates x2's
                    if (j == i + 1 || arr[j] != arr[j - 1]) {
                        int twoSumTar = target - arr[i] - arr[j];
                        int low = j + 1;
                        int high = (int)arr.size() - 1;

                        while (low < high) {
                            if (arr[low] + arr[high] == twoSumTar) {
                                results.push_back({arr[i], arr[j], arr[low], arr[high]});

                                while (low < high and arr[low] == arr[low + 1])    low++;
                                while (low < high and arr[high] == arr[high - 1])  high--;

                                low++;
                                high--;
                            } else if (arr[low] + arr[high] > twoSumTar)  high--;
                            else    low++;
                        }
                    }
                }
            }
        }

        return results;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif

    vector<int> arr({1, 0, -1, 0, -2, 2});
    int target = 0;

    // vector<int> arr({ -2, -1, -1, 1, 1, 2, 2});
    // int target = 0;

    Solution s;

    for (auto &i : s.fourSum(arr, target)) {
        for (auto &j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
/*
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

[-2,-1,-1,1,1,2,2]
*/