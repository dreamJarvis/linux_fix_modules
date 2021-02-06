// longest common substring
#include <bits/stdc++.h>
using namespace std;

// DP solution
// time complexity : O(n^2)
// space complexity : O(n^2)
int longestCommonSubstring(string &A, string &B) {
    int aLen = A.length();
    int bLen = B.length();

    vector<vector<int>> dp(bLen, vector<int>(aLen, 0));     // o(n^2)

    if(A[0] == B[0])    dp[0][0] = 1;

    for(int i = 1; i < bLen; i++){
        if(B[0] == A[i]){
            dp[0][i] = 1;
        }
    }

    for(int i = 1; i < aLen; i++){
        if(A[0] == B[i]){
            dp[i][0] = 1;
        }
    }

    int maxLen = 0;
    for(int i = 1; i < bLen; i++){
        for(int j = 1; j < aLen; j++){
            if(A[j] == B[i]){
                dp[i][j] = dp[i-1][j-1] + 1;
                maxLen = max(maxLen, dp[i][j]);
            }
        }
    }

    // display 2d matrix
    // for(int i = 0; i < bLen; i++){
    //     for(int j = 0; j < aLen; j++)
    //         cout << dp[i][j] << "\t";
    //     cout << endl;
    // }

    return maxLen;
}

// Driver function
int main(){
    // string a = "abcdef";
    // string b = "hfcdle";
    string a = "cde";//3
    string b = "hfcdelf";//7

    cout << longestCommonSubstring(a, b) << endl;

    return 0;
}
