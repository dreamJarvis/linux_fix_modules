/*
    72. Edit Distance
    https://leetcode.com/problems/edit-distance/
*/
#include <bits/stdc++.h>
using namespace std;

// ================================== Memo ================================== //
// tc : O(n*m)
// sc : O(n*m)
unordered_map<string, int> dp;
int util(string a, string b, int n, int m){
    string key = to_string(n) + '_' + to_string(m);

    if(!n && !m)    return 0;
    if(!m) return n;
    if(!n) return m;

    if(dp.count(key))
        return dp[key];

    if(a[n-1] == b[m-1]){
        dp[key] = util(a, b, n-1, m-1);
    }
    else{
        int replace = util(a, b, n-1, m-1);
        int del = util(a, b, n, m-1);
        int insert = util(a, b, n-1, m);

        dp[key] = 1 + min(replace, min(del, insert));
    }

    return dp[key];
}

int minDistanceMemo(string word1, string word2){
    int n = word1.length();
    int m = word2.length();
    return util(word1, word2, n, m);
}

//  ============================== top Down ====================================== //
// tc : O(n*m)
// sc : O(n*m)
int minDistance(string word1, string word2){
    int n = word1.length();
    int m = word2.length();

    int dp[n+1][m+1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(!i && !j)    dp[i][j] = 0;
            else if(!i)     dp[i][j] = j;
            else if(!j)     dp[i][j] = i;
            else if(word1[i-1] == word2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = 1 + min(
                                dp[i-1][j-1],
                                min(
                                    dp[i][j-1],
                                    dp[i-1][j]
                                )
                            );
            }
        }
    }

    return dp[n][m];
}

// Driver function
int main(){
    // string a = "horse";
    // string b = "ros";

    string a = "intention";
    string b = "execution";

    // cout << minDistanceMemo(a, b) << endl;
    cout << minDistance(a, b) << endl;
    return 0;
}
