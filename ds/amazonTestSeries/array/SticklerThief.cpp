/*
    14. Stickler Thief
    https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/0/?track=amazon-arrays&batchId=192
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

// memo
ll util(ll arr[], ll n, ll dp[]){
    if(n < 0)
        return 0;

    if(dp[n] != -1)
        return dp[n];

    dp[n] =  max(
                util(arr, n-2, dp) + arr[n],
                util(arr, n-1, dp)
            );

    return dp[n];
}

ll FindMaxSum(ll arr[], ll n){
    ll dp[n];
    memset(dp, -1, sizeof(dp));
    return util(arr, n-1, dp);
}

// tabultion
ll FindMaxSumDP(ll arr[], ll n){
    ll dp[n+1];

    dp[0] = 0;
    dp[1] = arr[0];
    dp[2] = arr[1];

    for(int i = 2; i <= n; i++){
        dp[i] = max(dp[i-1], (dp[i-2] + arr[i-1]));
    }

    return dp[n];
}

// Driver function
int main(){
    ll arr[] = {5, 5, 10, 100, 10, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    // ll arr[] = {1, 2, 3};
    // int n = sizeof(arr)/sizeof(arr[0]);

    cout << FindMaxSum(arr, n) << endl;

    return 0;
}
