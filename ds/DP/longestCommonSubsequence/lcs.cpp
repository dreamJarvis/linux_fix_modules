/*
    1143. Longest Common Subsequence
*/
#include <iostream>
#include <unordered_map>
using namespace std;


// ============================== Recursive ==================================== //
int helper(string text1, string text2, int n, int m) {
    if(n == -1 || m == -1)
        return 0;

    if(text1[n] == text2[m]){
        return (1 + helper(text1, text2, n-1, m-1));
    }
    else{
        return  max(
                        helper(text1, text2, n-1, m),
                        helper(text1, text2, n, m-1)
                    );
    }
}

int longestCommonSubsequence(string text1, string text2){
    return helper(text1, text2, text1.length()-1, text2.length()-1);
}

// ================================ Memo ============================== //
int helper(string text1, string text2, int n, int m, unordered_map<string, int> &dp) {
    string key = to_string(n) + '_' + to_string(m);

    if(n == -1 || m == -1)
        return 0;

    if(dp.count(key))
        return dp[key];

    if(text1[n] == text2[m]){
        dp[key] =  1 + helper(text1, text2, n-1, m-1, dp);
    }
    else{
        dp[key] =  max(
                        helper(text1, text2, n-1, m, dp),
                        helper(text1, text2, n, m-1, dp)
                    );
    }

    return dp[key];
}

int lcsMemo(string text1, string text2){
    unordered_map<string, int> dp;
    return helper(text1, text2, text1.length()-1, text2.length()-1, dp);
}

int lcsDP(string text1, string text2){
    int len1 = text1.length();
    int len2 = text2.length();

    int dp[len1+1][len2+1];
    for(int i = 0; i <= len1; i++){
        for(int j = 0; j <= len2; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(text1[i-1] == text2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[len1][len2];
}

// Driver function
int main(){
    string str1 = "abcde";
    string str2 = "ace";

    // string str1 = "abc";
    // string str2 = "abc";

    // string str1 = "abc";
    // string str2 = "def";

    // string str1 = "adcasdece";
    // string str2 = "aceasde";

    cout << longestCommonSubsequence(str1, str2) << endl;
    // cout << lcsDP(str1, str2) << endl;

    return 0;
}
