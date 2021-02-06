/*
    Minimum number of deletions and insertions
    https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1
*/
#include <bits/stdc++.h>
using namespace std;

int lcs(string a, string b){
    int n = a.length();
    int m = b.length();

    int dp[n+1][m+1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(!i || !j)    dp[i][j] = 0;
            else if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n][m];
}

int minOperations(string word1, string word2){
    int lcsLen = lcs(word1, word2);
    int numberOfDeletions = word2.length() - lcsLen;
    int numOfinsertions =    word1.length() - lcsLen;
    int totalSum = numOfAdditions + numberOfDeletions;
    return (totalSum);
}

// Driver function
int main(){
    string a = "heap";
    string b = "pea";

    // string a = "geeksforgeeks";
    // string b = "geeks";

    cout << minOperations(a, b) << endl;

    return 0;
}
