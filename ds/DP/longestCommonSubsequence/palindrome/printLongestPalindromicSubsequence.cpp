#include <bits/stdc++.h>
using namespace std;

string printLPS(string s){
    int n = s.length();

    if(n == 0)
        return 0;

    string t = s;
    reverse(t.begin(), t.end());

    int dp[n+1][n+1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(!i || !j)  dp[i][j] = 0;
            else if(s[i-1] == t[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    string res="";
    int i = n, j = n;
    while(i && j){
        if(s[i-1] == t[j-1]){
            res += s[i-1];
            i--;
            j--;
        }
        else{
            if(dp[i][j-1] < dp[i-1][j])
                i--;
            else
                j--;
        }
    }

    reverse(res.begin(), res.end());
    return res;
}

// Driver function
int main(){
    // string a = "bbbab";
    string a = "cbbd";

    cout << printLPS(a) << endl;

    return 0;
}
