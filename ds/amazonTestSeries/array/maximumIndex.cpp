#include <bits/stdc++.h>
using namespace std;

// tc : O(n)
// sc : 2*O(n)
int maxIndexDiff(int arr[], int n) {
    int leftArr[n];
    int rightArr[n];

    leftArr[0] = arr[0];
    for(int i = 1; i < n; i++){
        leftArr[i] = min(arr[i], leftArr[i-1]);
    }

    rightArr[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--){
        rightArr[i] = max(rightArr[i+1], arr[i]);
    }

    // for(int  i = 0; i < n; i++){
    //     cout << leftArr[i] << " ";
    // }
    // cout << endl;
    //
    // for(int  i = n-1; i >= 0; i--){
    //     cout << rightArr[i] << " ";
    // }
    // cout << endl;

    int maxDiff = -1;
    int i = 0, j = 0;
    while(i < n && j < n){
        if(leftArr[i] <= rightArr[j]){
            maxDiff = max(maxDiff, (j-i));
            j++;
        }
        else
            i++;
    }

    return maxDiff;
}

// Driver function
int main(){
    int arr[] = {34,8,10,3,2,80,30,33,1};                    // 6
    // int arr[] = {34,85, 100, 3, 2, 80, 75, 33, 11};       // 6
    // int arr[] = {1,10};
    // int arr[] = {65, 6, 74, 94, 56, 89, 9, 63, 75, 25, 34, 68, 93, 48, 16};
    // int arr[] = {92, 71, 39, 88, 3, 24, 33, 46, 24, 6, 31, 54, 65};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout << maxIndexDiff(arr, n) << endl;

    return 0;
}
