// Given an array arr[] of N integers, the task is to find the count of subarrays with negative product.
#include <bits/stdc++.h>
using namespace std;

// counts all the sub-arrays with -ve product
int countNegativeProductSubArrays(vector<int> &arr, int n){
    int pos = 1, neg = 0;

    for(int i = 0; i < n; i++){
        // replace current element with 1 and -ve with -1
        if(arr[i] > 0)  arr[i] = 1;
        else            arr[i] = -1;

        if(i > 0)   arr[i] *= arr[i-1];

        // count +ve and -ve elements in the prefix product array
        if(arr[i] == 1) pos++;
        else            neg++;
    }

    return (pos * neg);
}

// Driver function
int main(){
    vector<int> arr({5, -4, -3, 2, -5});

    cout << countNegativeProductSubArrays(arr, arr.size()) << endl;

    return 0;
}
