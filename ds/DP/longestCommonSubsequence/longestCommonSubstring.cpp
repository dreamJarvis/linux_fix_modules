/*
    Longest Common Substring
    https://practice.geeksforgeeks.org/problems/longest-common-substring/0
*/
#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

// ============================= Memo ================================= //
// tc : O(n*m)
// sc : O(n*m)
unordered_map<string, int> dp;
int util(string x, string y, int n, int m, int count){
    string key = to_string(n) + '_' + to_string(m) + '_' + to_string(count);

    if(n == -1 || m == -1)
        return count;

    if(dp.count(key))
        return dp[key];

    int lcsCount1 = count;
    if(x[n] == y[m])
        lcsCount1 = util(x, y, n-1, m-1, count+1);
    dp[key] = max(
                lcsCount1,
                max(
                    util(x, y, n-1, m, 0),
                    util(x, y, n, m-1, 0)
                )
            );

    return dp[key];
}

int lcsMemo(string x, string y){
    return util(x, y, x.length()-1, y.length()-1, 0);
}

// =================================== top down =======================================//
// tc : O(n*m)
// sc : O(n*m)
int lcsDP(string str1, string str2){
    int n = str1.length();
    int m = str2.length();

    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));

    int maxLen = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] =  dp[i-1][j-1]+1;
                maxLen = max(maxLen, dp[i][j]);
            }
        }
    }

    return maxLen;
}


// Driver function
int main(){
    string str1 = "ABCDGH";
    string str2 = "ACDGHR";

    // string str1 = "ABC";
    // string str2 = "AC";

    // string str1 = "KXCGMTMVVGFQQWSPD";
    // string str2 = "JXZADDUKVLQPKUZJZHWSUTPCAFSYAIBJHAMMEGWBTPQELRNKBLDXGUZGCSEC";

    cout << lcsMemo(str1, str2) << endl;
    cout << lcsDP(str1, str2) << endl;

    return 0;
}

/*
KXCGMTMVVGFQQWSPD
JXZADDUKVLQPKUZJZHWSUTPCAFSYAIBJHAMMEGWBTPQELRNKBLDXGUZGCSEC

// string str1 = "ABCDGH";
// string str2 = "ACDGHR";

// string str1 = "ABC";
// string str2 = "AC";

// string str1 = "KXCGMTMVVGFQQWSPD";
// string str2 = "JXZADDUKVLQPKUZJZHWSUTPCAFSYAIBJHAMMEGWBTPQELRNKBLDXGUZGCSEC";
*/
