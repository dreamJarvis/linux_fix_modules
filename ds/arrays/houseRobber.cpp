// 198. House Robber
#include <bits/stdc++.h>
using namespace std;

// tc : O(n), sc : O(n)
int rob(vector<int>& nums) {
    int n = nums.size();

    // if the number of elements in the array < 3
    if(n == 0)  return 0;
    if(n == 1)  return nums[0];
    if(n == 2)  return max(nums[0], nums[1]);

    // dp table
    vector<int> dp=nums;

    // initializing the dp
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    /*  the current value will see, if the value upto index-1 > value at index i-2 + current index
        the current index will contain maximum of
        value at i'th index = max(value upto i-1'th index, value upto i-2'th index + value at i'th index )
    */
    for(int i = 2; i < n; i++){
        dp[i] = max(dp[i-1], dp[i]+dp[i-2]);
    }

    return max(dp[n-1], dp[n-2]);
}

// Driver function
int main(){
    vector<int> arr({2, 7, 9, 3, 1});

    cout << rob(arr) << endl;

    return 0;
}
