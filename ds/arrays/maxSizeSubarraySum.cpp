/*
    209. Minimum Size Subarray Sum
    https://leetcode.com/problems/minimum-size-subarray-sum/
*/
#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {
    int n = nums.size();
    if(!n)  return 0;

    int minLen = n+1;
    int st = 0, end = 0;
    int sum = 0;
    while(end < n){
        sum += nums[end];

        while(sum >= s && st <= end){
            minLen = min(minLen, abs(end-st));
            sum -= nums[st];
            st++;
        }

        end++;
    }

    while(sum >= s && st < n){
        minLen = min(minLen, abs(end-st));
        sum -= nums[st];
        st++;
    }

    return minLen+1 > n ? 0 : minLen+1;
}

// Driver Code
int main(){
    // vector<int> arr({2, 3, 1, 2, 4, 3});
    // int s = 7;

    // vector<int> arr({1, 4, 4});
    // int s = 4;

    // vector<int> arr({10, 2, 3});
    // int s = 6;

    vector<int> arr({1, 1});
    int s = 3;

    cout << minSubArrayLen(s, arr) << endl;

    return 0;
}
/*
ABCDGH
ACDGHR
*/
