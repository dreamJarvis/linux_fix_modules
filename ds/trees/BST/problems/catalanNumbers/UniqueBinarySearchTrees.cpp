/*
    Total number of possible Binary Search Trees using Catalan Number
    https://www.geeksforgeeks.org/total-number-of-possible-binary-search-trees-using-catalan-number/?ref=rp

    leetcode 96. Unique Binary Search Trees
*/
#include <bits/stdc++.h>
using namespace std;

// O(2^n)
int countBSTRecursive(int n){
    if(n == 0)  return 1;

    int ans = 0;

    // forming the left and right sub-trees bst's
    for(int i = 1; i <= n; i++){
        int leftBST = countBSTRecursive(i-1);
        int rightBST = countBSTRecursive(n-i);

        ans += leftBST*rightBST;
    }
    return ans;
}

// memo
// O(n^2)
int countBSTMemo(int n, unordered_map<int, int> &dp){
    if(n == 0 || n == 1){
        dp[n] = 1;
        return dp[n];
    }

    if(dp.count(n))
        return dp[n];

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += countBSTMemo(i, dp)*countBSTMemo(n-i-1, dp);
    }

    dp[n] = ans;
    return dp[n];
}

int countBST(int n){
    unordered_map<int, int> dp;
    return (countBSTMemo(n, dp));
}

// O(n^2)
int countBSTDP(int n){
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;

    for(int i = 2; i <= n; i++)
        for(int j = 0; j < i; j++)
            dp[i] += dp[j]*dp[i-j-1];

    return dp[n];
}

// Driver function
int main(){
    int n = 4;
    // cout << countBSTRecursive(n) << endl;
    // cout << countBST(n) << endl;
    cout << countBSTDP(n) << endl;

    return 0;
}
