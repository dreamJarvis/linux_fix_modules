/*
    560. Subarray Sum Equals K
    https://leetcode.com/problems/subarray-sum-equals-k/
*/
#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k){
    int n = nums.size();
    unordered_map<int, int> freq;
    int sum = 0;
    int count = 0;
    for(int i = 0; i < n; i++){
        sum += nums[i];

        if(sum == k)
            count++;

        if(freq.count(sum-k)){
            count += freq[sum-k];
        }

        freq[sum]++;
    }

    return count;
}

// Driver function
int main(){
    vector<int> arr({1, 1, 1});
    int k = 2;

    // vector<int> arr({1, 2, 3});
    // int k = 3;

    cout << subarraySum(arr, k) << endl;

    return 0;
}
