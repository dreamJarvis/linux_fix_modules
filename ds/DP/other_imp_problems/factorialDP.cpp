// to find the factorial of a number using bottom up approach : tabulation method
#include <bits/stdc++.h>
using namespace std;

// tabulation : bottom up
// because we sart fom the bottom, i.e. the base value
int factorial1(int n){
    int dp[n+1];

    // definin the base states
    dp[0] = 1;
    dp[1] = 1;

    // using the information of base states to build up to the n'th state
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] * i;
    }

    return dp[n];
}

// memoisation : top down
// here we start from the top (let's suppose n), and take the remaining input from n-1'th element, which infact takes the input from n-2'th input.. aor ye silsila chlta rehta h, jb tk hm base case nhi hit kr jate, phit uss base case se value return honi wapis hobgi, n'th case tk.
int factorial2(int n, vector<int> &dp){
    // base case:
    if(n == 0)      return 1;

    // if the value for dp[n] already exists in the dp[], then return it
    //** we call it memoization as we are storing the most recent state values.
    // **** here, we never use cache value, it is only shown here to represent the common layout used while using memoisation ****//
    if(dp[n] != -1) return dp[n];

    // it gives the sub-problem to the recursion to solve it further
    dp[n] = n * factorial2(n-1, dp);

    // return the factorial upto this number
    return dp[n];
}

// Driver function
int main(){
    int n = 8;
    // cout << factorial1(n) << endl;

    vector<int> dp(n+1, -1);
    cout << factorial2(n, dp) << endl;
    return 0;
}
