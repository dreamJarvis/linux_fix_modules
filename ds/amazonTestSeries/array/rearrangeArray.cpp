/*
    24. Rearrange an array with O(1) extra space
    https://practice.geeksforgeeks.org/problems/rearrange-an-array-with-o1-extra-space3142/0/?track=amazon-arrays&batchId=192

    sol^n : https://www.youtube.com/watch?v=Zq208EIYTu8
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

void arrange(long long arr[], int n) {
    for(int i = 0; i < n; i++)
        arr[i] += (arr[arr[i]]%n)*n;

    for(int i = 0; i < n; i++)
        arr[i] /= n;
}

// Driver function
int main(){
    // ll arr[] = {1, 0};
    ll arr[] = {4, 0, 2, 1, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    arrange(arr, n);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
