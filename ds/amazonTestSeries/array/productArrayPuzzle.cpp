/*
    15. Product array puzzle
    https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/0/?track=amazon-arrays&batchId=192#
*/
#include <bits/stdc++.h>
using namespace std;

#define lli long long int

// tc : O(n)
// sc : O(n)
vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
    vector<int> leftPr(n, 1);
    int pr = nums[0];
    leftPr[0] = 1;

    for(int i = 1; i < n; i++){
        leftPr[i] = pr;
        pr *= nums[i];
    }

    int rightPr = 1;
    for(int i = n-1; i >= 0; i--){
        int temp = nums[i];
        nums[i] = leftPr[i]*rightPr;
        rightPr *= temp;
    }

    return nums;
}

#define EPS 1e-9

// tc : O(n)
// sc : O(1)
// using log property
vector<long long int> productExceptSelfII(vector<long long int>& nums, int n){
    long double sum = 0;
    for(int i = 0; i < n; i++)
        sum += (long double)log10(nums[i]);

    for(int i = 0; i < n; i++){
        nums[i] = (lli)(EPS + pow((long double)10.00, (sum-log10(nums[i])) ));
    }

    return nums;
}

int main(){
    vector<long long int> arr({10, 3, 5, 6, 2});
    // vector<long long> arr({12, 0});

    for(auto &i:productExceptSelf(arr, arr.size()))
        cout << i << " ";
    cout << endl;

    // for(auto &i:productExceptSelfII(arr, arr.size()))
    //     cout << i << " ";
    // cout << endl;

    return 0;
}
