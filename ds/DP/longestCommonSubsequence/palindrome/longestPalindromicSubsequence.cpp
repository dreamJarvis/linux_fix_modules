/*
    516. Longest Palindromic Subsequence
    https://leetcode.com/problems/longest-palindromic-subsequence/
*/
#include <bits/stdc++.h>
using namespace std;

// unordered_map<string, int> dp;
// int util(string s, int n, int m){
//     string key = to_string(n) + '_' + to_string(m);
//
//     if(n > m)   return 0;
//     if(n == m)  return 1;
//
//     if(dp.count(key))
//         return dp[key];
//
//     if(s[n] == s[m]){
//         dp[key] = (2 + util(s, n+1, m-1));
//     }
//     else{
//         dp[key] =   max (
//                         util(s, n+1, m),
//                         util(s, n, m-1)
//                     );
//     }
//
//     return dp[key];
// }
//
// int longestPalindromeSubseqMemo(string a){
//     return util(a, 0, a.length()-1);
// }
//
// int longestPalindromeSubseq(string s) {
//     int n = s.length();
//
//     int dp[n][n];
//     memset(dp, 0, sizeof dp);
//
//     for(int i = 0; i < n; i++)
//         dp[i][i] = 1;
//
//     for(int l = 2; l <= n; l++){
//         for(int i = 0; i < n-l+1; i++){
//             int j = i+l-1;
//
//             if(l == 2 && s[i] == s[j])
//                 dp[i][j] = 2;
//             else if(s[i] == s[j])
//                 dp[i][j] = dp[i+1][j-1] + 2;
//             else
//                 dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
//         }
//     }
//
//     return dp[0][n-1];
// }

int longestPalindromeSubseq(string s) {
    int n = s.length();

    if(n == 0)
        return 0;

    string t = s;
    reverse(t.begin(), t.end());

    int dp[n+1][n+1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(!i || !j)  dp[i][j] = 0;
            else if(s[i-1] == t[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n][n];
}

int longestPalindromeSubseqII(string a){
    int n = a.length();

    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    for(int i = 0; i < n; i++)
        dp[i][i] = 1;

    for(int l = 2; l <= n; l++){
        for(int i = 0; i < n-l+1; i++){
            int j = i+l-1;
            if(l == 2 && a[i] == a[j])
                dp[i][j] = 2;
            else if(a[i] == a[j])
                dp[i][j] = dp[i+1][j-1] + 2;
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }

    return dp[0][n-1];
}

// Driver function
int main(){
    // string a = "bbbab";
    string a = "cbbd";

    // cout << longestPalindromeSubseqMemo(a) << endl;
    cout << longestPalindromeSubseq(a) << endl;

    return 0;
}
