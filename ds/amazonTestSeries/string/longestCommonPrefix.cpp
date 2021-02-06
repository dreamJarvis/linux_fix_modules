#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

string longestCommonPrefix (string arr[], int n) {
    string res = arr[0];
    for (int i = 1; i < n; i++) {
        string tmp = "";
        int j = 0;
        while (j < min(res.length(), arr[i].length()) && res[j] == arr[i][j]) {
            tmp += res[j];
            j++;
        }

        res = tmp;
    }

    return res.length() == 0 ? "-1" : res;
}

int main() {
    // string arr[] = {
    //     "d", "d", "d", "d"
    // };

    // string arr[] = {
    //     "geeksforgeeks", "geeks", "geek", "geezer"
    // };

    string arr[] = {
        "ab", "abcdefg", "ab"
    };

    int n = sizeof(arr) / sizeof(arr[0]);
    cout << longestCommonPrefix(arr, n) << "\n";

    return 0;
}