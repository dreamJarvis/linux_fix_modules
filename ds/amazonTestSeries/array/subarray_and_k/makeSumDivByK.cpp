/*
    1590. Make Sum Divisible by P
    https://leetcode.com/problems/make-sum-divisible-by-p/
*/
#include <bits/stdc++.h>
using namespace std;

int minSubarray(vector<int>& nums, int p){
    int n = nums.size();
    int rem=0;
    for(int i = 0; i < n; i++){
        rem = (rem+nums[i])%p;
    }

    if(rem == 0)
        return 0;

    unordered_map<int, int> freq;
    freq[0] = -1;
    int minRange = n;
    int sum=0;
    for(int i = 0; i < n; i++){
        sum = (sum + nums[i])%p;
        int k = (sum-rem)%p;

        if(k < 0)
            k += p;

        if(freq.count(k)){
            minRange = min(minRange, (i-freq[k]));
        }

        freq[sum] = i;
    }

    return minRange == n ? -1 : minRange;
}

// Driver function
int main(){
    // vector<int> arr({3, 1, 4, 2});
    // int p = 6;

    // vector<int> arr({6, 3, 5, 2});
    // int p = 9;

    vector<int> arr({26,19,11,14,18,4,7,1,30,23,19,8,10,6,26,3});
    int p = 26;

    // vector<int> arr({4, 4, 2});
    // int p = 7;

    cout << minSubarray(arr, p) << endl;

    return 0;
}
/*
[26,19,11,14,18,4,7,1,30,23,19,8,10,6,26,3]
26

// vector<int> arr({1, 2, 3});
// int p = 3;

// vector<int> arr({1, 2, 3});
// int p = 7;

// vector<int> arr({1000000000,1000000000,1000000000});
// int p = 3;

// vector<int> arr({4, 5, 8, 5, 4});
// int p = 7;

*/
