/*
    713. Subarray Product Less Than K
    https://leetcode.com/problems/subarray-product-less-than-k/
*/
#include <bits/stdc++.h>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k){
    int n = nums.size();

    if(k < 1)  return 0;

    int prod = 1, ans = 0, left = 0;
    for(int right = 0; right < n; right++){
        prod *= nums[right];

        while(prod >= k)    prod /= nums[left++];

        ans += (right-left+1);
    }

    return ans < 0 ? 0 : ans;
}

// Driver function
int main(){
    // vector<int> arr({10, 5, 2, 6});
    // int k = 100;

    // vector<int> arr({10,9,10,4,3,8,3,3,6,2,10,10,9,3});
    // int k = 19;

    // vector<int> arr({10,2,2,5,4,4,4,3,7,7});
    // int k = 289;

    vector<int> arr({1, 1, 1, 1, 1});
    int k = 5;

    cout << numSubarrayProductLessThanK(arr, k) << endl;
    // numSubarrayProductLessThanK(arr, k);

    return 0;
}
/*
[10,9,10,4,3,8,3,3,6,2,10,10,9,3]
19
[10,2,2,5,4,4,4,3,7,7]
289
*/
