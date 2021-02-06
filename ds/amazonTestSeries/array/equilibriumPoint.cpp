/*
    13. Equilibrium Point
    https://practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/0/?track=amazon-arrays&batchId=192
*/
#include <bits/stdc++.h>
using namespace std;

int equilibriumPoint(long long a[], int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];

    int temp = a[0];
    for (int i = 1; i < n; i++) {
        if (temp == (sum - temp - a[i]))
            return i;
        temp += a[i];
    }

    return -1;
}


// Driver function
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    convertToWave(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
