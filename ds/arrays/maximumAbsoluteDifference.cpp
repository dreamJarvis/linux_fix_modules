// Maximum absolute difference of value and index sums
// https://www.geeksforgeeks.org/maximum-absolute-difference-value-index-sums/
#include <bits/stdc++.h>
using namespace std;

// naive approach : brute force
// time complexity : O(n^2)
int maxAbsoluteDiff(vector<int> &arr, int n, int si){
    int maxDiff = INT_MIN;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int temp = abs(arr[i]-arr[j]) + abs(i-j);
            maxDiff = max(maxDiff, temp);
        }
    }

    int index = 0;
    for(int i = 1; i < n; i++){
        int temp = abs(arr[index] - arr[i]) + abs(index-i);
        maxDiff = max(maxDiff, temp);
        if(abs(arr[index] - arr[i]) > abs(index - i))
            index = i;
    }

    return maxDiff;
}

// by using the modulus algorithm
/*
    Case 1: A[i] > A[j] and i > j
    |A[i] - A[j]| = A[i] - A[j]
    |i -j| = i - j
    hence, f(i, j) = (A[i] + i) - (A[j] + j)

    Case 2: A[i] < A[j] and i < j
    |A[i] - A[j]| = -(A[i]) + A[j]
    |i -j| = -(i) + j
    hence, f(i, j) = -(A[i] + i) + (A[j] + j)

    Case 3: A[i] > A[j] and i < j
    |A[i] - A[j]| = A[i] - A[j]
    |i -j| = -(i) + j
    hence, f(i, j) = (A[i] - i) - (A[j] - j)

    Case 4: A[i] < A[j] and i > j
    |A[i] - A[j]| = -(A[i]) + A[j]
    |i -j| = i - j
    hence, f(i, j) = -(A[i] - i) + (A[j] - j)
*/
// time complexity : O(n)
int maxAbsoluteDiff2(vector<int> &arr, int n){
    // max and min values as described in algorithm
    int max1 = INT_MIN, min1 = INT_MAX;
    int max2 = INT_MIN, min2 = INT_MAX;

    for(int i = 0; i < n; i++){
        // updating max and min variables as described in the algorithm
        max1 = max(max1, arr[i]+i);
        min1 = min(min1, arr[i]+i);
        max2 = max(max2, arr[i]-i);
        min2 = min(min2, arr[i]-i);
    }

    // in order to make the variables in as the same order as that of the algorithm
    // hme jo bhi maximum value milegi, chahe wo -i krne se ho ya +i krne se, hme in dono me se maximum value send krnni h
    return max(max1 - min1, max2 - min2);
}

// Driver function
int main(){
    //  -70, -64, -6, -56, 64, 61, -57, 16, 48, -98
    // vector<int> arr({1, 3, -1});
    vector<int> arr({-70, -64, -6, -56, 64, 61, -57, 16, 48, -98});

    cout << maxAbsoluteDiff(arr, arr.size(), 0) << endl;
    return 0;
}
