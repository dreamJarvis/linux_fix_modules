#include <bits/stdc++.h>
using namespace std;

int maxSubarraySumCircular(vector<int>& arr) {
    int n = arr.size();
    int currSum = arr[0], maxSum = arr[0];

    for(int i = 1; i < n; i++){
        currSum = max(currSum+arr[i], arr[i]);
        maxSum = max(maxSum, currSum);
    }
    maxSum = max(maxSum, currSum);

    return maxSum;
}

int main(){
    // vector<int> nums({10,-3,-4,7,6,5,-4,-1});
    // vector<int> nums({1,-2,3,-2});
    // vector<int> nums({3, -1, 2, -1});
    // vector<int> nums({3, -2, 2, -3});
    // vector<int> nums({-2, -3, -1});
    // vector<int> nums({5, -3, 5});
    vector<int> nums({8,-8,9,-9,10,-11,12});

    cout << maxSubarraySumCircular(nums) << endl;

    return 0;
}
