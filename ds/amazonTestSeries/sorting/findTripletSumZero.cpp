#include <bits/stdc++.h>
using namespace std;

bool findTriplets(int arr[], int n) {
    sort(arr, arr + n);
    for (int i = 0; i < n - 2; i++) {
        int s = i + 1, e = n - 1;
        while (s < e) {
            if (arr[i] + arr[s] + arr[e] == 0)
                return true;
            if (arr[i] + arr[s] + arr[e] > 0)
                e--;
            else
                s++;
        }
    }

    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int arr[] = {0, -1, 2, -3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << findTriplets(arr, n) << endl;

    return 0;
}
