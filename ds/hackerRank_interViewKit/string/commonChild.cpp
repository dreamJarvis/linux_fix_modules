#include <bits/stdc++.h>
using namespace std;

// recursive way
// tc : O(n + 2^n)
// TLE
int commonChildUtil(string s1, string s2, int m, int n){
    if(m == 0 || n == 0)
        return 0;

    if(s1[m - 1] == s2[n - 1])
        return (1 + commonChildUtil(s1, s2, m-1, n-1));
    else
        return max(commonChildUtil(s1, s2, m-1, n), commonChildUtil(s1, s2, m, n-1));
}

int commonChild(string s1, string s2){
    return commonChildUtil(s1, s2, s1.size(), s2.size());
}

// memoisation
// tc : O(n^2 + n)  (i guess)
// TLE
int commonChildMemoUtil(string s1, string s2, int m, int n, unordered_map<string, int> &dp){
    string key = to_string(m) + '_' + to_string(n);

    if(m == 0 || n == 0)    return 0;

    if(dp.count(key))
        return dp[key];

    if(s1[m - 1] == s2[n - 1]){
        dp[key] = 1 + commonChildMemoUtil(s1, s2, m-1, n-1, dp);
        return dp[key];
    }
    else{
        dp[key] =  max(commonChildMemoUtil(s1, s2, m-1, n, dp), commonChildMemoUtil(s1, s2, m, n-1, dp));
        return dp[key];
    }
}

int commonChildMemo(string s1, string s2){
    unordered_map<string, int> dp;
    return commonChildMemoUtil(s1, s2, s1.size(), s2.size(), dp);
}

// Tabulation
// tc : O(n^2)
// accepted
int commonChildDP(string s1, string s2){
    int n = s1.size();

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    // filling initial values
    for(int row = 0; row <= n; row++)
        dp[row][0] = 0;

    for(int col = 0; col <= n; col++)
        dp[0][col] = 0;

    for(int row = 1; row <= n; row++){
        for(int col = 1; col <= n; col++){
            if(s1[row-1] == s2[col - 1]){
                dp[row][col] = dp[row-1][col-1] + 1;
            }
            else{
                dp[row][col] = max(dp[row-1][col], dp[row][col-1]);
            }
        }
    }

    return dp[n][n];
}

// Driver function
int main(){
    string s1 = "ABCD";
    string s2 = "ABDC";
    // string s1 = "HARRY";
    // string s2 = "SALLY";
    // string s1 = "ABCDEF";
    // string s2 = "FBDAMN";
    // string s1 = "AA";
    // string s2 = "BB";

    cout << commonChild(s1, s2) << endl;
    // cout << commonChildMemo(s1, s2) << endl;
    // cout << commonChildDP(s1, s2) << endl;

    return 0;
}
/*
HARRY
SALLY

AA
BB

ABCDEF
FBDAMN
*/
