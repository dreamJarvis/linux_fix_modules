// 698. Partition to K Equal Sum Subsets
#include <bits/stdc++.h>
using namespace std;

// backtracking and recursion
// space complexity : O(n)
// time complexity : exponential
bool canPartition(int startingIndex, vector<int> &arr, vector<bool> visited, int sum, int k, int bucketSum){
    // if only 1 bucket is left then, all the other buckets are already filled, that is the equal sum subset buckets exist
    if(k == 1)
        return true;

    // if the sum is reaced the partion sum, then reset the sum == 0, and recurse to find other buckets
    if(sum == bucketSum){
        return canPartition(0, arr, visited, 0, k-1, bucketSum);
    }


    for(int i = startingIndex; i < arr.size(); i++){
        // we will recur to the next step only if, by adding the current item the sum doesn't exceed the bucketsum and the element has not been visited earlier
        if(!visited[i] && (sum + arr[i] <= bucketSum)){
            // mark this element true
            visited[i] = true;

            if(canPartition(i+1, arr, visited, sum+arr[i], k, bucketSum))
                return true;

            // if we do not get the sum, even after considering this element then exclude this element from the sum, .'. we backtrack it
            visited[i] = false;
        }
    }

    // because before reaching this point, we have tried all the possible condition
    return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sumOfAllElements = 0;
    for(auto value:nums)
        sumOfAllElements += value;

    if(k <= 0 || k > nums.size() || sumOfAllElements%k != 0){
        return false;
    }

    vector<bool> visited(nums.size(), false);   // keeps track of the elements useed
    return canPartition(0, nums, visited, 0, k, sumOfAllElements/k);
}

bool canPartitionDP()

// Driver function
int main(){
    vector<int> nums({4, 3, 2, 3, 1, 2, 5});
    int k = 4;
    // vector<int> nums({2,2,2,2,3,4,5});
    // int k = 4;

    cout << canPartitionKSubsets(nums, k) << endl;

    return 0;
}
