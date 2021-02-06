#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int n1 = m + 1, n2 = r + 1;
    int i = l, j = m + 1, k = 0;

    int tempArr[r - l];
    while (i < n1 && j < n2) {
        if (arr[i] < arr[j]) {
            tempArr[k] = arr[i];
            i++; k++;
        }
        else if (arr[i] >= arr[j]) {
            tempArr[k] = arr[j];
            j++; k++;
        }
    }

    while (i < n1) {
        tempArr[k] = arr[i];
        i++; k++;
    }

    while (j < n2) {
        tempArr[k] = arr[j];
        j++; k++;
    }

    for (int i = l; i <= r; i++) {
        arr[i] = tempArr[i - l];
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}