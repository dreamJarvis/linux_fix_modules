// leetcode 53
// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
#include <bits/stdc++.h>
using namespace std;

// kadanes algo
// t : O(n)
// s : O(1)
int kadanesAlgo(vector<int> &arr){
    int maxSum = arr[0];
    int currSum = arr[0];

    for(int i = 1; i < arr.size(); i++){
        currSum = max(currSum + arr[i], arr[i]);
        maxSum = max(currSum, maxSum);
    }

    return max(maxSum, currSum);
}

// divide & conquer technique
int maxSubArraySum(int arr[], int n){
    // base case : when size of array is 1, i.e. only single element is left
    if(n==1){
        return arr[0];
    }

    // divide the array into half
    int m = n/2;

    int left_mss = maxSubArraySum(arr, m);          //  count the max sub-array from the left side
    int right_mss = maxSubArraySum(arr+m, n-m);     //  count the max sub-array from the right side
    int leftSum = INT_MIN, rightSum = INT_MIN, sum = 0;

    // right sub-array : left-->right
    for(int i=m; i<n; i++){
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }
    sum = 0;

    // left sub-array : left <-- right
    for(int i = (m-1); i >= 0; i--){
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }

    // ya toh left sub-array me lie krega max sub-array, ya phir right wale me lie krega
    // ya toh left + right dono ka mila ke exist krta hoga
    // inn teeno cond^n meses hme jonsi bhi max sub-array sum dega, hm usse rkh lenge
    return (max(leftSum+rightSum, max(left_mss, right_mss)));
}

// Driver Code
int main() {
    // ** inputs
    // vector<int> arr({-2,1,-3,4,-1,2,1,-5,4});
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};

    // cout << kadanesAlgo(arr) << endl;

    // divide & conquer
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << maxSubArraySum(arr, n) << endl;

	return 0;
}
