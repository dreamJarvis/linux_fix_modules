/*
    1092. Shortest Common Supersequence
    https://leetcode.com/problems/shortest-common-supersequence/
*/
#include <bits/stdc++.h>
using namespace std;

string scc(string a, string b){
    int n = a.length();
    int m = b.length();

    int dp[n+1][m+1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(!i)  dp[i][j] = j;
            else if(!j)  dp[i][j] = i;
            else if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(
                                dp[i-1][j],
                                dp[i][j-1]
                            );
        }
    }

    string result="";
    int i = n, j = m;
    while(i && j){
        if(a[i-1] == b[j-1]){
            result += a[i-1];
            i--; j--;
        }
        else{
            if(dp[i-1][j] < dp[i][j-1]){
                result += a[i-1];
                i--;
            }
            else{
                result += b[j-1];
                j--;
            }
        }
    }

    while(i){
        result += a[i-1];
        i--;
    }

    while(j > 0){
        result += b[j-1];
        j--;
    }

    reverse(result.begin(), result.end());
    return result;
}

// Driver function
int main(){
    string a = "abcd";
    string b = "xycd";

    // string a = "efgh";
    // string b = "jghi";

    cout << scc(a, b) << endl;

    return 0;
}
