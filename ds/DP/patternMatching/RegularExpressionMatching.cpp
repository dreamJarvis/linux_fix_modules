/*
    10. Regular Expression Matching
    https://leetcode.com/problems/regular-expression-matching/
*/
#include <bits/stdc++.h>
using namespace std;

// ==================================== Memoisation ================================== //
// tc : O(n*m)
unordered_map<string, int> dp;
bool util(string s, string p, int n, int m){
    string key = to_string(n) + to_string(m);

    if(n <= -1 && m <= -1)
        return true;

    if(n == -1 && p[m] == '*')
        return util(s, p, n, m-2);

    if(n == -1 || m == -1)
        return false;

    if(dp.count(key))
        return dp[key];

    if(s[n] == p[m]){
        dp[key] = util(s, p, n-1, m-1);
    }
    else{
        if(p[m] == '*'){
            if(s[n] == p[m-1] || p[m-1] == '.'){
                dp[key] = (util(s, p, n-1, m) || util(s, p, n, m-2));
            }
            else{
                dp[key] = util(s, p, n, m-2);
            }
        }
        else if(p[m] == '.'){
            dp[key] = util(s, p, n-1, m-1);
        }
        else
            dp[key] = false;
    }

    return dp[key];
}

bool isMatchMemo(string s, string p) {
    return util(s, p, s.length()-1, p.length()-1);
}

// ==================================== Top Down ===================================== //
// tc : O(n*m)
// sc : O(n*m)
bool isMatch(string s, string p) {
    int n = s.length();
    int m = p.length();

    bool dp[n+1][m+1];
    memset(dp, false, sizeof(dp));

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(!i && !j)    dp[i][j] = true;
            else if(!i && p[j-1] == '*')
                dp[i][j] = dp[i][j-2];
            else if(!i || !j) dp[i][j] = false;

            else{
                if(s[i-1] == p[j-1])
                    dp[i][j] = dp[i-1][j-1];

                else if(p[j-1] == '*'){
                    if(s[i-1] == p[j-2] || p[j-2] == '.')
                        dp[i][j] = dp[i-1][j] || dp[i][j-2];
                    else
                        dp[i][j] = dp[i][j-2];
                }
                else if(p[j-1] == '.')
                    dp[i][j] = dp[i-1][j-1];
            }
        }
    }

    return dp[n][m];
}

// Driver function
int main(){
    string str = "aasdfasdfasdfasdfas";
    string p = "aasdf.*asdf.*asdf.*asdf.*s";

    // string str = "a";
    // string p = "ab*a";

    // string str = "aa";
    // string p = "a";

    // string str = "aa";
    // string p = "a*";

    // string str = "ab";
    // string p = ".*";

    // string str = "aab";
    // string p = "c*a*b";

    // string str = "mississippi";
    // string p = "mis*is*p*.";

    // string str = "mississippi";
    // string p = "mis*is*ip*.";

    // string str = "aaa";
    // string p = "ab*a*c*a";

    cout << isMatch(str, p) << endl;

    return 0;
}
/*
"mississippi"
"mis*is*ip*."

"a"
"ab*a"

"aaa"
"ab*a*c*a"

"aasdfasdfasdfasdfas"
"aasdf.*asdf.*asdf.*asdf.*s"
*/
