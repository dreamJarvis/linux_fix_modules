#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfTriangles(int arr[], int n) {
        sort(arr, arr + n);

        int count = 0;
        for (int i = n - 1; i >= 1; i--) {
            int l = 0, r = i - 1;
            while (l < r) {
                if (arr[l] + arr[r] > arr[i]) {
                    count += (r - l);
                    r--;
                }
                else
                    l++;
            }
        }

        return count;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // int arr[] = {3, 5, 4};
    int arr[] = {6, 4, 9, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    Solution ob;
    cout << ob.findNumberOfTriangles(arr, n) << endl;

    return 0;
}
/*
6
26 9 27 22 16 27

6 4 9 7 8
*/