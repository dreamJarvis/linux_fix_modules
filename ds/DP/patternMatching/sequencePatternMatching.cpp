/*
    44. Wildcard Matching
    https://leetcode.com/problems/wildcard-matching/
*/
#include <bits/stdc++.h>
using namespace std;

// // tc : O(n^2)
unordered_map<string, bool> dp;
bool util(string s, string p, int n, int m){
    string key = to_string(n) + to_string(m) + to_string(n+m);

    if(n <= -1 && m <= -1)
        return true;

    if(n <= -1 && m != -1){
        if(p[m] == '*'){
            return util(s, p, n, m-1);
        }
        return false;
    }

    if(dp.count(key))
        return dp[key];

    if(s[n] == p[m]){
        dp[key] = util(s, p, n-1, m-1);
    }
    else{
        if(p[m] == '*'){
            dp[key] =   util(s, p, n, m-1)   ||
                        util(s, p, n-1, m);
        }
        else if(p[m] == '?'){
            dp[key] = util(s, p, n-1, m-1) ;
        }
        else
            dp[key] = false;
    }

    return dp[key];
}

bool isMatchMemo(string s, string p) {
    int n = s.length();
    int m = p.length();
    return util(s, p, n-1, m-1);
}

// tc : O(n^2)
// sc : O(n^2)
bool isMatch(string s, string p) {
    int n = s.length();
    int m = p.length();

    bool dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(!i && !j)    dp[i][j] = true;
            else if(!i && j){
                if(p[j-1] == '*')
                    dp[i][j] = dp[i][j-1];
            }
            else if(!j)   dp[i][j] = false;
            else if(s[i-1] == p[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                if(p[j-1] == '*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else if(p[j-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = false;
            }
        }
    }

    return dp[n][m];
}

// Driver function
int main(){
    // string s = "mississippi";
    // string p = "m*iss*iss*";

    // string s = "abcabczzzde";
    // string p = "*abc???de*";

    // string s = "aa";
    // string p = "a";

    // string s = "a";
    // string p = "?*";

    // string s = "cb";
    // string p = "?a";

    // string s = "adceb";
    // string p = "*a*b";

    string s = "acdcb";
    string p = "a*c?b";

    // string s = "aab";
    // string p = "c*a*b";

    // string s = "aa";
    // string p = "a*";

    // string s = "aabbbbaaaaaaaabbbabbaabbbbbbaabaaabbbabbaabaaabababbaabababbaaaaababbbbbbababaaabbbbbabbbaabaaaaaaabbbbbbababbaaaabbababbbbabbabbabababbaabbbabbabbaabababbaaabbaabaabbbbaabaaaabbbbbbabaabaabbabaaabbbbab";
    // string p = "a**abaaa******a*b*ba**aba***b*bbbab*bb*aab**a*bba*b*abab**aabbb***a*a**b**a*abab*ba**aa**b***aba*b****a*";

    // string s = "ab";
    // string p = "?*";

    // string s = "";
    // string p = "******";

    cout << isMatch(s, p) << endl;

    return 0;
}
/*
"acdcb"
"a*c?b"

"aab"
"c*a*b"

"aa"
"a*"

"ab"
"?*"

""
"******"

"abcabczzzde"
"*abc???de*"

"mississippi"
"m*iss*iss*"

"aabbbbaaaaaaaabbbabbaabbbbbbaabaaabbbabbaabaaabababbaabababbaaaaababbbbbbababaaabbbbbabbbaabaaaaaaabbbbbbababbaaaabbababbbbabbabbabababbaabbbabbabbaabababbaaabbaabaabbbbaabaaaabbbbbbabaabaabbabaaabbbbab"
"a**abaaa******a*b*ba**aba***b*bbbab*bb*aab**a*bba*b*abab**aabbb***a*a**b**a*abab*ba**aa**b***aba*b****a*"
*/
