// leetcode 494. Target Sum
#include <bits/stdc++.h>
using namespace std;

// to find if by assinging '+', '-' we can get the required sum
// recursive method
// tc : ~ O(2^n)
int targetSum(vector<int> &arr, int sum, int requiredSum, int index){
    if(index == arr.size()){
        if(sum == requiredSum){
            return 1;
        }
        return 0;
    }

    int element = arr[index];
    int left = targetSum(arr, sum+arr[index], requiredSum, index+1);
    int right = targetSum(arr, sum-arr[index], requiredSum, index+1);

    return (left + right);
}

int findTargetSumWays(vector<int>& nums, int S) {
    return targetSum(nums, 0, S, 0);
}

// -------------------  memoisation -------------------------- //
int targetSumMemoUTIL(vector<int> &arr, int sum, int requiredSum, int index, unordered_map<string, int> &memo){
    string key = to_string(index) + "_" + to_string(sum);     // key

    if(index == arr.size()){
        if(sum == requiredSum){
            return 1;
        }
        return 0;
    }

    if(memo.count(key))
        return memo[key];

    int element = arr[index];
    int left = targetSumMemoUTIL(arr, sum+arr[index], requiredSum, index+1, memo);
    int right = targetSumMemoUTIL(arr, sum-arr[index], requiredSum, index+1, memo);

    memo[key] = left+right;

    return (left + right);
}

int targetSumMemo(vector<int>&arr, int S){
    unordered_map<string, int> memo;
    return targetSumMemoUTIL(arr, 0, S, 0, memo);
}


// to find the no. of ways to achieve the target sum
// int count = 0;
int findTargetSumWays(vector<int>& nums, int S, int k, int d, int index) {
    // base condition
    if(index > nums.size())
        return 0;

    if(S - d == k)
        return 1;

    int sum=0, count = 0;
    for(int i = index; i < nums.size();i++){
        sum += arr[i];
        count = findTargetSumWays(nums, S, k, sum, i+1);
    }

    return count;
}

// Driver function
int main(){
    vector<int> arr({1, 1, 1, 1});
    int k = 3;
    int sum = 0;
    for(auto item:arr)
        sum+=item;

    cout << findTargetSumWays(arr, sum, k, 0, 0) << endl;

    return 0;
}
