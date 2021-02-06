/*
    Minimum Deletions
    https://practice.geeksforgeeks.org/problems/minimum-deletitions/0
*/
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cstring>
using namespace std;

// unordered_map<string, int> dp;
// int util(string a, string b, int n, int m){
//     string key = to_string(n) + '_' + to_string(m);
//
//     if(n == -1 || m == -1)
//         return 0;
//
//     if(dp.count(key))
//         return dp[key];
//
//     if(a[n] == b[m]){
//         dp[key] = 1 + util(a, b, n-1, m-1);
//     }
//     else {
//         dp[key] = max(
//                     util(a, b, n-1, m),
//                     util(a, b, n, m-1)
//                 );
//     }
//
//     return dp[key];
// }
//
// int minDeletions(string s){
//     int n = s.size();
//
//     string t = s;
//     reverse(t.begin(), t.end());
//
//     int pl = util(s, t, n-1, n-1);
//     return (n-pl);
// }

int minDeletions(string s){
    int n = s.size();

    string t = s;
    reverse(t.begin(), t.end());

    int dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(s[i-1] == t[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(
                            dp[i-1][j],
                            dp[i][j-1]
                        );
        }
    }

    return (n-dp[n][n]);
}

// Driver function
int main(){
    string str = "aebcbda";
    // string str = "geeksforgeeks";

    cout << minDeletions(str) << endl;

    return 0;
}
