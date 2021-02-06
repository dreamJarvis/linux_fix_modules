/*
    Minimum sum partition
    https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1
*/
#include <bits/stdc++.h>
using namespace std;

// =============================== recursion ==============================//
int util(int *arr, int n, int s1, int s2){
    if(n < 0)
        return abs(s1-s2);

    return (
        min(
            util(arr, n-1, s1+arr[n], s2),
            util(arr, n-1, s1, s2+arr[n])
        )
    );
}

int minDiff(int arr[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];

    return util(arr, n-1, 0, 0);
}

// ================================ Memo ========================= //
// tc : O(n * |sum of elements in array|)
// sc : O(n * |sum of elements in array|)
unordered_map<string, int> dp;
int utilMemo(int *arr, int n, int s1, int s2){
    if(n < 0)
        return abs(s1-s2);

    string key = to_string(n) + '_' + to_string(s1);

    if(!dp.count(key)){
        int inc = utilMemo(arr, n-1, s1+arr[n], s2);
        int exc = utilMemo(arr, n-1, s1, s2+arr[n]);

        dp[key] = min(inc, exc);
    }

    return dp[key];
}

int minDiffernceMemo(int arr[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];

    return utilMemo(arr, n-1, 0, 0);
}

// ================================= top down =============================== //
// tc : O(n * |sum of elements in array|/2)
// sc : O(n * |sum of elements in array|/2)
int minDiffII(int arr[], int n){
    if(n < 2){
        return arr[0];
    }

    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];

    bool dp[n+1][sum/2+1];
    memset(dp, false, sizeof dp);

    // initialization
    for(int i = 0; i <= n; i++)
        dp[i][0] = true;

    for(int i = 1; i <= sum/2; i++)
        dp[0][i] = false;

    int minDiff = INT_MAX;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum/2; j++){
            if(j >= arr[i-1]){
                dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
                if(dp[i][j])
                    minDiff = min(minDiff, abs(abs(sum-j)-j));
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return minDiff;
}

// Driver function
int main(){
    // int arr[] = {1, 6, 11, 5};
    // int n = sizeof(arr)/sizeof(arr[0]);

    int arr[] = {1, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    // int arr[] = {11, 4, 9, 11};
    // int n = sizeof(arr)/sizeof(arr[0]);

    // int arr[] = {10000};
    // int n = sizeof(arr)/sizeof(arr[0]);

    // cout << minDiff(arr, n) << endl;
    // cout << minDiffernceMemo(arr, n) << endl;
    cout << minDiffII(arr, n) << endl;

    return 0;
}
