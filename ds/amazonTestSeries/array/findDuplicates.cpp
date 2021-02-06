/*
    https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/0/?track=amazon-arrays&batchId=192
    10. Find duplicates in an array
*/
#include <bits/stdc++.h>
using namespace std;

// O(N)
// O(N)
vector<int> duplicates(vector<int> &arr) {
    int n = arr.size();
    int freq[n];
    memset(freq, 0, sizeof(freq));

    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (freq[i] > 1)
            res.push_back(i);
    }

    arr = res;
}

// O(N)
// O(1)
void duplicatesII(vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        while (a[i] >= 0 && a[i] != a[a[i]]) {
            swap(a[i], a[a[i]]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[a[i]] == a[i] && i != a[i])
            a[a[i]] = -1;
    }

    int i = 0, j = 0;
    while (j < n) {
        if (a[j] == -1) {
            a[i] = j;
            i++;
        }
        j++;
    }

    a.erase(a.begin() + i, a.end());
}

// O(N)
// O(1)
void duplicatesIII(vector<int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        int index = arr[i] % n;
        arr[index] += n;
    }

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] / n >= 2) {
            arr[j++] = i;
        }
    }

    arr.erase(arr.begin() + j, arr.end());
}

// Driver function
int main() {
    vector<int> arr({2, 3, 1, 2, 3});
    // vector<int> arr ({0, 3, 1, 2});
    // vector<int> arr({13, 9, 25, 1, 1, 0, 22, 13, 22, 20, 3, 8, 11, 25, 10, 3, 15, 11, 19, 20, 2, 4, 25, 14, 23, 14});

    // duplicates(arr);
    // duplicatesII(arr);
    duplicatesIII(arr);
    for (auto &i : arr)
        cout << i << " ";
    cout << endl;

    return 0;
}
