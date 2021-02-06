/*
    4. Find Transition Point
    https://practice.geeksforgeeks.org/problems/find-transition-point-1587115620/0/?track=amazon-searching&batchId=192#
*/
#include <bits/stdc++.h>
using namespace std;

// O(log(N))
int transitionPoint(int arr[], int n) {
    if(n < 2){
        return arr[0]==0?-1:0;
    }

    int s = 0, e = n-1;
    int index = -1;
    while(s <= e){
        int mid = (s+e)/2;

        if(mid > s && arr[mid] && !arr[mid-1])
            return mid;

        if(arr[mid]){
            index = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }

    return index;
}

// Driver function
int main(){
    int arr[] = {0, 0, 0, 1};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << transitionPoint(arr, size) << endl;

    return 0;
}
