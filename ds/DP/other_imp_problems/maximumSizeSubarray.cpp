// 209. Minimum Size Subarray Sum
#include <bits/stdc++.h>
using namespace std;

// time complexity : O(n^2)
// space complexity : O(n^2)
int minSubArrayLenI(int s, vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));       // dp table

    dp[0][0] = nums[0];
    int minSize = INT_MAX;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(i==j){
                dp[i][j] = nums[i];
            }
            else{
                dp[i][j] = dp[i][j-1] + nums[j];
            }

            if(dp[i][j] >= s){
                // cout << i<< ", " << j << "\t" << dp[i][j] << endl;
                minSize = min(minSize, j-i+1);
            }
        }
    }

    if(minSize == INT_MAX)  return 0;
    return minSize;
}

// TLE
// time complexity : O(n*m)
// space complexity : O(1)
int minSubArrayLenII(int s, vector<int>& nums){
    int n = nums.size();
    if(n == 0)  return 0;

    vector<int> temp(n);
    temp[0] = nums[0];

    for(int i = 1; i < n; i++)
        temp[i] = temp[i-1] + nums[i];

    int minLen = INT_MAX;
    for(int i = 0; i < n; i++){
        int st = 0;
        int sum = temp[i];
        while(sum >= s){
            minLen = min(minLen, i-st+1);
            sum = temp[i] - temp[st];
            st++;
        }
    }
    return minLen == INT_MAX ? 0 : minLen;
}

/*
    **article : resource for better explanation : https://leetcode.com/problems/minimum-size-subarray-sum/discuss/59090/C%2B%2B-O(n)-and-O(nlogn)
    **youtube vedio : https://www.youtube.com/watch?v=jKF9AcyBZ6E&t=353s
*/
// time complexity : O(nlong(n))
// space complexity : O(n)
// binary search approach
int minSubArrayLenIII(int s, vector<int>& nums) {
    int n = nums.size(), len = INT_MAX;

    vector<int> sums(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        sums[i] = sums[i - 1] + nums[i - 1];
    }

    for (int i = n; i >= 0 && sums[i] >= s; i--) {
        int j = upper_bound(sums.begin(), sums.end(), sums[i] - s) - sums.begin();
        len = min(len, i - j + 1);
    }

    return len == INT_MAX ? 0 : len;
}

// time complexity : O(n)
// space complexity : O(1)
// 2 pointer approach
int minSubArrayLenIV(int s, vector<int>& nums){
    int sum = 0;
    int left = 0;
    int result = INT_MAX;

    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];

        while(sum >= s){
            result = min(result, i-left+1);
            sum -= nums[left];
            left++;
        }
    }

    return result > nums.size() ? 0 : result;
}

// Driver function
int main(){
    // vector<int> arr({2, 3, 1, 2, 4, 3});
    // int s = 7;
    // vector<int> arr({1, 1});
    // int s = 3;
    // vector<int> arr({2, 16, 14, 15});
    // int s = 20;
    vector<int> arr({1, 2, 3, 4, 5});
    int s = 15;

    cout << minSubArrayLenIV(s, arr) << endl;

    return 0;
}
