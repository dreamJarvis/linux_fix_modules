/*
    712. Minimum ASCII Delete Sum for Two Strings
    https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
*/
#include <bits/stdc++.h>
using namespace std;

int lcs(string a, string b)
{
    int n = a.length();
    int m = b.length();

    int dp[n+1][m+1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(!i || !j) dp[i][j] = 0;
            else if(a[i-1] == b[j-1])
                dp[i][j] = a[i-1] + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n][m];
}

int minimumDeleteSum(string s1, string s2)
{
    int temp = lcs(s1, s2);

    int sum1 = 0, sum2 = 0;
    for(auto &i:s1)
        sum1 += i;

    for(auto &i:s2)
        sum2 += i;

    int result = (sum1-temp) + (sum2-temp);
    return result;
}

// Driver function
int main(){
    // string a = "sea";
    // string b = "eat";

    string a = "delete";
    string b = "leet";

    cout << minimumDeleteSum(a, b) << endl;
    // cout << lcs(a, b) << endl;

    return 0;
}
