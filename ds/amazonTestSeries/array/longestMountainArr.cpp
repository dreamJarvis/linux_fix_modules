/*
    845. Longest Mountain in Array
    https://leetcode.com/problems/longest-mountain-in-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // tc : O(N)
    // sc : 2*O(N)
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        /*
            the left most index after i'th index, where the array stop's decreasing
            or,
            the point after i'th index where the array was still in decreasing order, or
            the first increasing point from the current index
        */
        vector<int> right(n, -1);
        int index = -1;
        right[n - 1] = n - 1;
        index = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] <= arr[i + 1])
                index = i;
            right[i] = index;
        }

        /*
            the right most index where the array stops increasing ,
            or
            the right most index before the i'th index where the array was still in increasing order, or
            the last decreasing index from the current index
        */
        vector<int> left(n, -1);
        index = 0;
        left[0] = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] <= arr[i - 1])
                index = i;
            left[i] = index;
        }

        int maxLen = 0;
        for (int i = 1; i < n - 1; i++) {
            // if the all the element's in the array are same
            if (left[i] == 0 && right[i] == n - 1 && (arr[i] <= arr[0] || arr[i] <= arr[n - 1]))
                continue;

            // if the array is all increasing or all decreasing
            if ((left[i] >= 0 && right[i] == i) || (left[i] == i && right[i] >= 0))
                continue;

            if (left[i] < right[i]) {
                maxLen = max(maxLen, right[i] - left[i] + 1);
            }
        }

        return maxLen;
    }


    // tc : O(N)
    // sc : O(1)
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int maxLen = 0;

        int i = 0;
        while (i < n - 1) {
            if (arr[i] == arr[i + 1]) {
                i++;
                continue;
            }

            // the array is considered a mountian if both are true, order-wise
            bool isInc = false;
            bool isDec = false;

            int st = i;
            while (i < n - 1 && arr[i] < arr[i + 1]) {
                isInc = true;
                i++;
            }

            int pivot = i;
            while (i < n - 1 && arr[i] > arr[i + 1]) {
                isDec = true;
                i++;
            }

            if (pivot != i && st < i && isInc && isDec) {
                maxLen = max(maxLen, i - st + 1);
            }
        }

        return maxLen;
    }
};

// Driver function
int main() {
    // vector<int> arr({2,1,4,7,3,2,5});
    // vector<int> arr({2,3,2,4,4,6,3,2});
    // vector<int> arr({2, 2, 2});
    // vector<int> arr({0, 1, 2, 3, 4, 5, 4, 3, 2, 1, 0});
    // vector<int> arr({0,1,2,3,4,5,6,7,8,9});
    // vector<int> arr({5, 4, 3, 2, 1, 0});
    // vector<int> arr({2,3,1,2,3,4,5,6});
    // vector<int> arr({0,2,0,2,1,2,3,4,4,1});

    Solution s;
    cout << s.longestMountain(arr) << endl;

    return 0;
}
