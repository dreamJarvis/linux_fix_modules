// Partition to k equal subset sum
#include <bits/stdc++.h>
using namespace std;

// defination
bool canPartition(int iterationStart, vector<int> &arr, unordered_map<int, bool> taken, int k, int inProgressBucketSum, int targetBucketSum);

bool canPartitionKSubsets(vector<int> &arr, int k){
    // get the sum of all the items in the array, we will use this to divide by k to get the sum that each bucket needs to hit
    int sumOfAllArrayItems = 0;
    for(auto num:arr)
        sumOfAllArrayItems += num;

    /*
        1.) k cannot be -ve or 0, cause we cannot fill 0 or -ve buckets

        2.) k cannot be > then the length of array, we can't partition more buckets than there are elements

        3.) sumOfAllArrayItems % k must be 0. if it is not 0 then we would have to fill buckets to a floating point sum which would be impossible with only integers
    */

    if(k <= 0 || k > arr.size() || sumOfAllArrayItems%k != 0)
        return false;

    unordered_map<int, bool> taken;
    return canPartition(0, arr, taken, k, 0, sumOfAllArrayItems/k);
}

bool canPartition(int iterationStart, vector<int> &arr, unordered_map<int, bool> taken, int k, int inProgressBucketSum, int targetBucketSum){

    // If we have filled all k-1 buvkets up to this point and we are now on our last bucket, we can stop and be finished

    if(k==1)    return true;

    // if the bucket is full, then continue with the next bucket i.e., recursion with k-1 as the new k value, but the targetBucketSum stays the same, We just have 1 less bucket to fill

    if(inProgressBucketSum == targetBucketSum)
        return canPartition(0, arr, taken, k-1, 0, targetBucketSum);

    /*
        try all values from 'iterationStart' to the end of the array only if:
            1) they have not been visited up to this point in the recursion's path
            2) they do not overflow the current bucket we are filling
    */

    for(int i = iterationStart; i < arr.size(); i++){
        if(!taken[i] && inProgressBucketSum + arr[i] <= targetBucketSum){
            taken[i] = true;

            // see if we can partition from this point with the item added to the current bucket progress
            if(canPartition(i+1, arr, taken, k, inProgressBucketSum+arr[i], targetBucketSum)) {
                return true;
            }

            taken[i] = false;
        }
    }

    // partitioning from this point is impossible. whether we are at the top level of the recursion or deeper into it
    return false;
}

// Driver function
int main(){
    vector<int> arr{4, 3, 2, 3, 5, 2, 1};
    int k = 4;

    cout << canPartitionKSubsets(arr, 4) << endl;

    return 0;
}
