#include <bits/stdc++.h>
using namespace std;

int trappingWater(int arr[], int n){
    int leftArr[n];
    int rightArr[n];

    int maxTower = arr[0];
    int index = 0;
    leftArr[0] = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] > maxTower){
            maxTower = arr[i];
            index = i;
        }

        leftArr[i] = index;
    }

    maxTower = arr[n-1];
    index = n-1;
    rightArr[n-1] = n-1;
    for(int i = n-2; i >= 0; i--){
        if(arr[i] > maxTower){
            maxTower = arr[i];
            index = i;
        }

        rightArr[i] = index;
    }

    // for(int i = 0; i < n; i++)
    //     cout << arr[leftArr[i]] << " ";
    // cout << endl;
    //
    // for(int i = 0; i < n; i++)
    //     cout << arr[rightArr[i]] << " ";
    // cout << endl;

    int totalWaterTrapped = 0;
    int area = 0;
    for(int i = 0; i < n; i++){
        area = min(arr[leftArr[i]], arr[rightArr[i]]) - arr[i];
        totalWaterTrapped += area;
    }

    return totalWaterTrapped;
}

// Driver function
int main(){
    // int arr[] = {3,0,0,2,0,4};
    int arr[] = {7, 4, 0, 9};
    // int arr[] = {6, 9, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << trappingWater(arr, n) << endl;

    return 0;
}
