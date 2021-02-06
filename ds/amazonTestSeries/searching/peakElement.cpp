/*
    5. Peak element
    https://practice.geeksforgeeks.org/problems/peak-element/0/?track=amazon-searching&batchId=192#

    162. Find Peak Element
    https://leetcode.com/problems/find-peak-element/

    https://www.youtube.com/watch?v=a7D77DdhlFc
*/
#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& arr) {
    int n = arr.size();

    if(n < 2)   return 0;

    int peak = -1;
    int s = 0, e = n-1;
    while(s <= e){
        int mid = (s+e)/2;

        if( (mid == 0 || arr[mid-1] <= arr[mid]) &&
            (mid == n-1 || arr[mid+1] <= arr[mid])
        ){
            peak = mid;
            break;
        }
        else if(mid > 0 && arr[mid-1] > arr[mid]){
            e = mid-1;
        }
        else {
            s = mid+1;
        }
    }

    return peak;
}

// Drive function
int main(){
    vector<int> arr({2,1,2});
    // vector<int> arr({1, 2, 3, 1});
    // vector<int> arr({1,2,1,3,5,6,4});

    cout << findPeakElement(arr) << endl;

    return 0;
}
