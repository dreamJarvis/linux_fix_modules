/*
    3. Missing number in array
    https://practice.geeksforgeeks.org/problems/missing-number-in-array1416/0/?track=amazon-searching&batchId=192#
*/
#include <bits/stdc++.h>
using namespace std;

int MissingNumber(vector<int>& arr, int n) {
    int totalSum = n*(n+1)/2;
    int arrSum = 0;

    for(int i = 0; i < arr.size(); i++)
        arrSum += arr[i];

    return abs(totalSum - arrSum);
}

int main(){
    // vector<int> arr({1,2,3,5});
    // int n = 5;

    vector<int> arr({1,2,3,4,5,6,7,8,10});
    int n = 10;

    cout << MissingNumber(arr, n) << endl;

    return 0;
}
