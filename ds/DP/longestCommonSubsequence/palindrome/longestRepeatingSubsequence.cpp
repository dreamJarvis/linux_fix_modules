/*
    Longest Repeating Subsequence
    https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence/0
*/
#include <bits/stdc++.h>
using namespace std;

// ============================== Memo ============================= //
int util(string a, string b, int n, int m, unordered_map<string, int> &dp){
    string key = to_string(n) + to_string(m);

    if(n == -1 || m == -1){
        return 0;
    }

    if(dp.count(key))
        return dp[key];

    if(a[n] == b[m] && n != m)
        return dp[key] = (1 + util(a, b, n-1, m-1, dp));

    return dp[key] =  max(
                        util(a, b, n-1, m, dp),
                        util(a, b, n, m-1, dp)
                    );
}

int lrs(string a){
    int n = a.length();
    unordered_map<string, int> dp;
    return util(a, a, n-1, n-1, dp);
}

// ================================= top Down ============================//
int lrsDP(string a){
    int n = a.length();

    int dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(!i || !j)    dp[i][j] = 0;
            else if(a[i-1] == a[j-1] && i != j){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n][n];
}

// ========================== print longest repeating subsequence ================================ //
string printLrsDP(string a){
    int n = a.length();

    int dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(!i || !j)    dp[i][j] = 0;
            else if(a[i-1] == a[j-1] && i != j){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    string result="";
    int i = n, j = n;
    while(i && j){
        if(a[i-1] == a[j-1] && i != j){
            result += a[i-1];
            i--;
            j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1])
                i--;
            else
                j--;
        }
    }

    reverse(result.begin(), result.end());
    return result;
}

// Driver function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a = "aabebcdd";
    // string a = "axxxy";
    // string a = "abc";

    cout << printLrsDP(a) << endl;

    return 0;
}
