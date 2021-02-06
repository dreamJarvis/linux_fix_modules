/*
    https://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/0/?track=amazon-arrays&batchId=192
*/
#include <iostream>
using namespace std;

void rotateArr(int arr[], int d, int n){
    int result[n];
    for(int i = 0; i < n-d; i++)
        result[i] = arr[i+d];

    int l = n-d;
    for(int i = 0; i < d; i++)
        result[l+i] = arr[i];

    for(int i = 0; i <n; i++)
        arr[i] = result[i];
}

// Driver function
int main(){
    int arr[] = {1, 2, 3, 4, 5};
    // int arr[] = {2,4,6,8,10,12,14,16,18,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int d = 2;

    rotateArr(arr, d, n);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
