// Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k
// leetcode : 560
#include <bits/stdc++.h>
using namespace std;

int subarraySumCount(vector<int> &arr, int k){
	unordered_map<int, int> storage;

	storage[0] = 1;

	int sum = 0;
	int count = 0;

	for(int i = 0; i < arr.size(); i++){
		sum += arr[i];
		
		if(storage.count(sum-k)){
			count += storage[sum-k];		
		}
		
		storage[sum] += 1;
	}

	return count;
}

// Driver function
int main(){
    vector<int> arr({1,1,1});
	int sum = 2;

	cout << subarraySumCount(arr, sum) << endl; 	

    return 0;
}
