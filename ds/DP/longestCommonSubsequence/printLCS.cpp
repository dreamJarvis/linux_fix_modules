/*
    https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem?isFullScreen=true
*/
#include <bits/stdc++.h>
using namespace std;

// ====================================== Memo =============================== //
// tc : O(n*m)
// sc : O(n*m)
string helper(string text1, string text2, int n, int m, unordered_map<string, string> &dp)
{
    string key = to_string(n) + '_' + to_string(m);

    if(n >= text1.length() || m >= text2.length())
        return "";

    if(dp.count(key))
        return dp[key];

    if(text1[n] == text2[m]){
        dp[key] = (text1[n] + helper(text1, text2, n+1, m+1, dp));
    }
    else{
        string left = helper(text1, text2, n+1, m, dp);
        string right = helper(text1, text2, n, m+1, dp);

        if(left.length() > right.length())
            dp[key] = left;
        else
            dp[key] = right;
    }

    return dp[key];
}

string printLCS(string text1, string text2){
    unordered_map<string, string> dp;
    return helper(text1, text2, 0, 0, dp);
}


// ====================================== top down =============================== //
// tc : O(n*m)
// sc : O(n*m)
string printLcsDP(string text1, string text2){
    int n = text1.length();
    int m = text2.length();

    vector<vector<string>> dp(n+1, vector<string>(m+1, ""));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(text1[i-1] == text2[j-1]){
                dp[i][j] = text1[i-1] + dp[i-1][j-1];
            }
            else{
                if(dp[i-1][j].length() > dp[i][j-1].length())
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
    }

    reverse(dp[n][m].begin(), dp[n][m].end());
    return dp[n][m];
}


// ===== 2'nd tareeka ======//
string printLcsDPII(string text1, string text2){
    int n = text1.length();
    int m = text2.length();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(text1[i-1] == text2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    string result="";
    int i = n, j = m;
    while(i && j){
        if(text1[i-1] == text2[j-1]){
            result += text1[i-1];
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
    string str1 = "abcde";
    string str2 = "ace";

    // string str1 = "adcasdece";
    // string str2 = "aceasde";

    // string str1 = "abc";
    // string str2 = "abc";

    // string str1 = "abc";
    // string str2 = "def";

    cout << printLcsDPII(str1, str2) << endl;

    return 0;
}
