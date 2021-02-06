/*
    Shortest Common Supersequence
    https://www.geeksforgeeks.org/shortest-common-supersequence/
*/
#include <bits/stdc++.h>
using namespace std;


// ===================================== Memo =========================================== //
int util(string a, string b, int n, int m, unordered_map<string, int> &dp){
    string key = to_string(n) + '_' + to_string(m);

    if(!m)  return n;
    if(!n)  return m;

    if(dp.count(key))
        return dp[key];

    if(a[n-1] == b[m-1])
        return 1 + util(a, b, n-1, m-1, dp);

    dp[key] = 1 + min(util(a, b, n-1, m ,dp), util(a, b, n, m-1, dp));
    return dp[key];
}

int shortestSuperSequenceMemo(string a, string b){
    unordered_map<string, int> dp;
    return util(a, b, a.length(), b.length(), dp);
}

// ================================== top down ========================================//
int shortestSuperSequenceDP(string a, string b){
    int n = a.size();
    int m = b.size();

    int dp[n+1][m+1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(!i)
                dp[i][j] = j;
            else if(!j)
                dp[i][j] = i;
            else if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n][m];
}

// ==================================== Another method =============================== //
// tc : O(n^2)
// sc : O(n^2)
int shortestSuperSequenceIII(string a, string b){
    int n = a.length();
    int m = b.length();

    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return (n+m-dp[n][m]);
}

// Driver fucntion
int main(){
    string a = "abac";
    string b = "cab";

    cout << shortestSuperSequenceMemo(a, b) << endl;
    cout << shortestSuperSequenceDP(a, b) << endl;
    cout << shortestSuperSequenceIII(a, b) << endl;

    return 0;
}

/*
    // string a = "geek";
    // string b = "eke";

    // string a = "AGGTAB";
    // string b = "GXTXAYB";

    // string a = "baabaaabb";
    // string b = "bbabbbaab";

    // string a = "bbcbcaabc";
    // string b = "cacaabaaaa";
*/
