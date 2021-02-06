/*
    gfg :
        23. Max Circular Subarray Sum
        https://practice.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/0/?track=amazon-arrays&batchId=192

    leetcode :
        918. Maximum Sum Circular Subarray
        https://leetcode.com/problems/maximum-sum-circular-subarray/
*/
#include <bits/stdc++.h>
using namespace std;

// O(n)
int maxSubarraySumCircular(vector<int>& arr) {
    int n = arr.size();

    int totalSum = arr[0];
    int currMax = arr[0], maxSum = arr[0];
    int currMin = arr[0], minSum = arr[0];
    for(int i = 1; i < n; i++){
        currMax = max(currMax+arr[i], arr[i]);
        maxSum = max(maxSum, currMax);

        totalSum += arr[i];

        currMin = min(currMin+arr[i], arr[i]);
        minSum = min(minSum, currMin);
    }

    if(minSum == totalSum)
        return maxSum;
    return max(maxSum, totalSum-minSum);
}

int main(){
    // vector<int> nums({10,-3,-4,7,6,5,-4,-1});
    // vector<int> nums({1,-2,3,-2});
    // vector<int> nums({3, -1, 2, -1});
    // vector<int> nums({3, -2, 2, -3});
    // vector<int> nums({-2, -3, -1});
    // vector<int> nums({5, -3, 5});
    vector<int> nums({8,-8,9,-9,10,-11,12});

    cout << maxSubarraySumCircular(nums) << endl;

    return 0;
}
