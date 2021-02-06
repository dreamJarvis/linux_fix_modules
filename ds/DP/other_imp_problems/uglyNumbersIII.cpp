/*
    1201. Ugly Number III
    https://leetcode.com/problems/ugly-number-iii/
*/
#include <bits/stdc++.h>
using namespace std;

#define lli long long int
int nthUglyNumber(int n, int a, int b, int c) {
    vector<lli> dp(n);

    int la = 1, lb = 1, lc = 1;
    for(int i = 0; i < n; i++){
        dp[i] = min(a*la, min(b*lb, c*lc));

        if(dp[i] == a*la)
            la++;
        if(dp[i] == b*lb)
            lb++;
        if(dp[i] == c*lc)
            lc++;
    }

    return dp[n-1];
}

// Driver function
int main(){
    // int n = 4;
    // int a = 2, b = 3, c = 4;

    // int n = 5;
    // int a = 2, b = 11, c = 13;

    int n = 1000000000;
    int a = 2, b = 217983653, c = 336916467;
    cout << nthUglyNumber(n, a, b, c) << endl;
    return 0;
}
/*
Input: n = 1000000000, a = 2, b = 217983653, c = 336916467
Output: 1999999984

*/
