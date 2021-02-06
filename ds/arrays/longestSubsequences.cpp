// 1143. Longest Common Subsequence
#include <bits/stdc++.h>
using namespace std;

// Longest common Subsequence
// recursive approach
int lcs(string str1, string str2){
    if(str1.length()==0 || str2.length()==0)
        return 0;

    char s1 = str1[0];
    char s2 = str2[0];

    int maxLength = 0;
    if(s1 == s2)
        maxLength = lcs(str1.substr(1), str2.substr(1)) + 1;
    else
        maxLength = max(lcs(str1.substr(1), str2), lcs(str1, str2.substr(1)));

    return maxLength;
}

// memoisation
int lcsMemo(string str1, string str2, unordered_map<string, int> storage){
    string key = to_string(str1.length()) +"_"+ to_string(str2.length());

    if(str1.length()==0 || str2.length()==0)
        return 0;

    if(storage.count(key))
        return storage[key];

    char s1 = str1[0];
    char s2 = str2[0];

    int maxLength = 0;
    if(s1 == s2)
        maxLength = lcsMemo(str1.substr(1), str2.substr(1), storage) + 1;
    else
        maxLength = max(lcsMemo(str1.substr(1), str2, storage), lcsMemo(str1, str2.substr(1), storage));

    storage[key] = maxLength;
    return maxLength;
}

// memoisation
int lcsUTIL(string str1, string str2){
    unordered_map<string, int> storage;
    return lcsMemo(str1, str2, storage);
}

// Pure DP
int lcsPureDP(string str1, string str2){
    int n1 = str1.length();
    int n2 = str2.length();

    vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1)); // initializing 2d array

    for(int i = 0; i <= n1; i++)
        dp[i][0] = 0;

    for(int i = 0; i <= n2; i++)
        dp[0][i] = 0;

    for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= n2; j++){
            if(str1[i-1]==str2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    for(int i = 0; i <= n1; i++){
        for(int j = 0; j <= n2; j++)
            cout << dp[i][j] << "\t";
        cout << endl;
    }

    // cout << dp[n1][n2] << endl;

    return dp[n1][n2];
}

// Driver function
int main(){
    string str1=  "abcde";
    string str2 = "ace";
    // string str1 = "abc";
    // string str2 = "def";

    cout << lcsPureDP(str1, str2) << endl;

    return 0;
}
