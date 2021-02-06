/*
    leetcode : 41. First Missing Positive
    https://leetcode.com/problems/first-missing-positive/

    gfg : 11. Smallest Positive missing number
    https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number3051/0/?track=amazon-searching&batchId=192

    reference :
        https://www.youtube.com/watch?v=-lfHWWMmXXM
*/
#include <bits/stdc++.h>
using namespace std;

// // tc : O(n)
// // sc : O(1)
// int findMissing(int arr[], int n) {
// 	int j = 0;
// 	int smallestNumber = INT_MAX;
// 	for(int i = 0; i < n; i++)
// 		smallestNumber = min(smallestNumber, arr[i]);
//
// 	if(smallestNumber > 1)
// 		return 1;
//
// 	for(int i = 0; i < n; i++){
// 		if(arr[i] < 0){
// 			swap(arr[i], arr[j]);
// 			j++;
// 		}
// 	}
//
// 	for(int i = j; i < n; i++){
// 		if(arr[i] >= n)
// 			continue;
//
// 		while(arr[i] != arr[arr[i]+j]){
// 			if(arr[i]+j >= n || arr[i] >= n)
// 				break;
// 			swap(arr[i], arr[arr[i]+j]);
// 		}
// 	}
//
// 	int ans = -1;
// 	for(int i = j+1; i < n; i++){
// 		if(abs(i-j) != arr[i]){
// 			ans = (i-j);
// 			break;
// 		}
// 	}
//
// 	return ans != -1 ? ans : n+1;
// }

// tc : O(n)
// sc : O(1)
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();

    for(int i = 0; i < n; i++){
        while((nums[i] >= 1 && nums[i] <= n) && nums[i] != nums[nums[i]-1]){
            swap(nums[i], nums[nums[i]-1 ]);
        }
    }

    for(int i = 0; i < n; i++){
        if(nums[i] != i+1)
            return i+1;
    }

    /* if we have reached till here, then it means
        all the nums exist's in array from 1 -> n,
        .'. the smallest possible number is n+1
    */
    return n+1;
}

// Driver function
int main(){
    // vector<int> arr({1, 2, 0});
    // vector<int> arr({7,8,9,11,12});
    vector<int> arr({3, 4, -1, 1});

    cout << firstMissingPositive(arr) << endl;
    // cout << firstMissingPositiveII(arr) << endl;

    return 0;
}
