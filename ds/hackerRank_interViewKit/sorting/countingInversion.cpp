// hacker rank : count Inversions
// solution approach discussed here : https://www.youtube.com/watch?v=owZhw-A0yWE&t=986s
#include <bits/stdc++.h>
using namespace std;

// solution 1 : mergeSort approach
// tc : O(nlog(n))
long merge(int arr[], int temp[], int left, int mid, int right){
    long inv_count = 0;

    int i = left;
    int j = mid;
    int k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

long _mergeSort(int arr[], int temp[], int left, int right){
    long mid, inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;

        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);

        /*Merge the two parts*/
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

long mergeSort(int arr[], int array_size){
    int temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}

// solution 2 : binary search approach
// hackerRank gives TLE
// tc : O(nlog(n)) (upper_bound uses binary search i.e. tc : log(n))
long mergeSortBinary(int arr[], int n){
    long invCount = 0;
    multiset<int> map;
    for(int i = 0; i < n; i++){     // n
        map.insert(arr[i]);
        invCount += distance(upper_bound(map.begin(), map.end(), arr[i]), map.end());   // log(n)
    }

    return invCount;
}

// Driver code
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int *arr = new int[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        // cout << mergeSort(arr, n) << endl;
        cout << mergeSortBinary(arr, n) << endl;
    }

    return 0;
}
/*
1 1 1 2 2   = 0
2 4 1       = 2
2 1 3 1 2   = 4
*/
