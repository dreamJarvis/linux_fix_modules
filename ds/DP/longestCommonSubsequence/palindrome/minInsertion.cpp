/*
    1312. Minimum Insertion Steps to Make a String Palindrome
    https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
*/
#include <bits/stdc++.h>
using namespace std;

int minInsertions(string s) {
    int n = s.length();
    string t = s;
    reverse(t.begin(), t.end());

    int dp[n+1][n+1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(!i || !j)    dp[i][j] = 0;
            else if(s[i-1] == t[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return (n-dp[n][n]);
}

// Driver function
int main(){
    // string s = "leetcode";
    // string s = "zzazz";
    string s = "taomghqojrznrvowsyofqtjapmnucwdcrjbatvxznheunlshmkfuixvaqhqaiyurx";

    cout << minInsertions(s) << endl;

    return 0;
}
