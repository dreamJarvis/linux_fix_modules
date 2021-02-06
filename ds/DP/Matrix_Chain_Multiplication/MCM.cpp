/*
    https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
    Matrix Chain Multiplication | DP-8
*/
#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;

// recursive solution
// tc : O(2^n)
int mcm(vector<int> &arr, int i, int j){
    if(i >= j)
        return 0;

    int minVal = INT_MAX;
    int count;

    for(int k = i; k < j; k++){
        count = mcm(arr, i, k) +
                mcm(arr, k+1, j) +
                (arr[i-1] * arr[k] * arr[j]);

        minVal = min(minVal, count);
    }

    return minVal;
}

// Memoisation : bottom up approach
// tc : O(n^3)
unordered_map<string, int> dp;
int mcmMemo(vector<int> &arr, int i, int j){
    string key = to_string(i) + to_string(j);

    if(i >= j)  return 0;

    if(dp.count(key))
        return dp[key];

    dp[key] = INT_MAX;
    for(int k = i; k < j; k++){
        dp[key] = min(
                    dp[key],
                    (mcmMemo(arr, i, k) + mcm(arr, k+1, j) + (arr[i-1]*arr[k]*arr[j]))
                );
    }

    return dp[key];
}

// top down approach
// tc : O(n^3)
// sc : O(n^2)
int mcmDP(vector<int> &arr){
    int n = arr.size();
    int dp[n][n];

    for(int i = 1; i < n; i++)
        dp[i][i] = 0;

    for(int l = 2; l < n; l++){
        for(int i = 1; i < n-l+1; i++){
            int j = i+l-1;
            dp[i][j] = INT_MAX;

            for(int k = i; k <= j-1; k++){
                dp[i][j] = min(
                                dp[i][j],
                                (dp[i][k] + dp[k+1][j] + (arr[i-1]*arr[k]*arr[j]))
                            );
            }
        }
    }

    return dp[1][n-1];
}

// Driver fcuntion
int main(){
    vector<int> arr({1, 2, 3, 4, 3});
    int n = arr.size();

    cout << "Minimum number of multiplication is : " << mcm(arr, 1, n-1) << endl;
    // cout << "Minimum number of multiplication is : " << mcmMemo(arr, 1, n-1) << endl;
    cout << "Minimum number of multiplication is : " << mcmDP(arr) << endl;

    return 0;
}
