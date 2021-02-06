#include <bits/stdc++.h>
using namespace std;

string longestCommonSubstring(string a, string b){
    int n = a.length();
    int m = b.length();

    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));

    int end = 0;
    int maxLen = 0;
    for(int i = 1 ; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];

                if(dp[i][j] > maxLen){
                    end = i;
                    maxLen = dp[i][j];
                }
            }
        }
    }

    return a.substr(end-maxLen, maxLen);
}

// Driver Code
int main(){
    string str1 = "GeeksforGeeks";
    string str2 = "GeeksQuiz";

    // string str1 = "abcdxyz";
    // string str2 = "xyzabcd";

    // string str1 = "ABCDGH";
    // string str2 = "ACDGHR";


    cout << longestCommonSubstring(str1, str2) << endl;

    return 0;
}
/*
ABCDGH
ACDGHR
*/
