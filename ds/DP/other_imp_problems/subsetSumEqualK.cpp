// Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
#include <bits/stdc++.h>
using namespace std;

// a recursive approach
bool isSubsetSum(vector<int> &arr, int n, int sum){
    // base cases :
    if(sum == 0)            return true;
    if(n == 0 && sum != 0)  return false;

    // if the last element is > sum, then ignore it
    if(arr[n-1] > sum)      return isSubsetSum(arr, n-1, sum);

    /* else, check if sum can be obtained by any of the following
        1) including the last element
        2) excluding the last element
    */
    bool include = isSubsetSum(arr, n-1, sum);
    bool exclude = isSubsetSum(arr, n-1, sum - arr[n-1]);

    // if any of the one will be true it will return true
    return (left || right);
}

// to count total number of subsets with sum == k
int countSubsetSumEqualK(vector<int> &arr, int n,  int sum){
    // base cases :
    if(sum == 0)            return 1;
    if(sum != 0 && n==0)    return 0;
    if(arr[n-1] > sum)      return countSubsetSumEqualK(arr, n-1, sum);

    // recursive cases :
    int include = countSubsetSumEqualK(arr, n-1, sum);
    int exclude = countSubsetSumEqualK(arr, n-1, sum - arr[n-1]);

    return (include + exclude);
}

// Driver function
int main(){
    vector<int> arr({3, 24, 4, 12, 5, 2, 3});
    int sum = 9;

    cout << isSubsetSum(arr, arr.size(), sum) << endl;

    cout << countSubsetSumEqualK(arr, arr.size(), sum) << endl;

    return 0;
}
