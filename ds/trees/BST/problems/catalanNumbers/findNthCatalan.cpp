/*
    To find n'th catalan number
*/
#include <bits/stdc++.h>
using namespace std;

// recursive solution
// O(e^x)
int catalan(int n){
    if(n == 0 || n == 1)
        return 1;

    int res = 0;
    for(int i = 0; i < n; i++)
        res += catalan(i)*catalan(n-i-1);

    return res;
}

// memoise
// O(n^2)
int catalanUtil(int n,  vector<int> &dp){
    if(n == 0 || n == 1){
        dp[n] = 1;
        return dp[n];
    }

    if(dp[n])
        return dp[n];

    int res = 0;
    for(int i = 0; i < n; i++){
        res += catalanUtil(i, dp)*catalanUtil(n-i-1, dp);
    }

    dp[n] = res;
    return dp[n];
}

int catalanMemo(int n){
    vector<int> dp(n+1, 0);
    return catalanUtil(n, dp);
}

// Tabulation method
// O(n^2)
unsigned long int catalanDP(int n){
    // dp container
    unsigned long int dp[n+1] = {0};

    // initials values
    dp[0] = dp[1] = 1;

    for(int i = 2; i <= n; i++)
        for(int j = 0; j < i; j++)
            dp[i] += dp[j]*dp[i-j-1];

    return dp[n];
}

// Driver function
int main(){
    int n = 123;
    // cout << catalan(n) << endl;
    cout << catalanMemo(n) << endl;
    // cout << catalanDP(n) << endl;
    return 0;
}
