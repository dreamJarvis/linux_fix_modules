#include <bits/stdc++.h>
using namespace std;


// ========================== Method 1 (Merge-sort) ========================= //
// // tc : O(nlog(n))
// // sc : O(n)
// int merge(long long arr[], int left, int mid, int right) {
//     int i, j, k;
//     int invCount = 0;

//     i = left;
//     j = mid;
//     k = left;
//     long long temp[right - left];
//     while ((i <= (mid - 1)) && (j <= right)) {
//         if (arr[i] <= arr[j]) {
//             temp[k++] = arr[i++];
//         }
//         else {
//             temp[k++] = arr[j++];
//             invCount += (mid - i);
//         }
//     }

//     while (i <= (mid - 1))
//         temp[k++] = arr[i++];

//     while (j <= right)
//         temp[k++] = arr[j++];

//     for (i = left; i <= right; i++)
//         arr[i] = temp[i];

//     return invCount;
// }

// int mergeSort(long long arr[], int s, int e) {
//     int mid, invCount = 0;
//     if (e > s) {
//         mid = (s + e) / 2;
//         invCount += mergeSort(arr, s, mid);
//         invCount += mergeSort(arr, mid + 1, e);

//         invCount += merge(arr, s, mid + 1, e);
//     }

//     return invCount;
// }


// long long int inversionCount(long long arr[], long long n) {
//     return mergeSort(arr, 0, n - 1);
// }


// ========================== Method 2 (Using Mutliset) ========================= //
// tc : O(nlog(n))
// sc : O(n)
long long int inversionCount(long long arr[], long long n) {
    int invCount = 0;
    multiset<int> st;
    st.insert(arr[0]);

    for (int i = 1; i < n; i++) {
        st.insert(arr[i]);

        auto it = st.upper_bound(arr[i]);
        invCount += distance(it, st.end());
    }

    return invCount;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // long long arr[] = {2, 4, 1, 3, 5};
    long long arr[] = {1, 20, 6, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << inversionCount(arr, n) << endl;

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
