/*
    583. Delete Operation for Two Strings
    https://leetcode.com/problems/delete-operation-for-two-strings/
*/
#include <bits/stdc++.h>
using namespace std;

int lcs(string word1, string word2){
    int n = word1.length();
    int m = word2.length();

    int dp[n+1][m+1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(!i || !j)  dp[i][j] = 0;
            else if(word1[i-1] == word2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n][m];
}

int minDistance(string word1, string word2) {
    int t = lcs(word1, word2);
    int sum = (word1.length()-t) + (word2.length()-t);
    return sum;
}

// Driver function
int main(){
    string a = "sea";
    string b = "eat";

    cout << minDistance(a, b) << endl;

    return 0;
}
