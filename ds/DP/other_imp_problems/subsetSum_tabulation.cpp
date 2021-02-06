// Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
#include <bits/stdc++.h>
using namespace std;

bool isSubset(vector<int> &arr, int n, int sum){
    bool dp[n+1][sum+1];

    // if sum  = 0, then the ans is true
    for(int i = 0; i <= n; i++)
        dp[i][0] = true;

    // when the array is empty, then the answer for every sum is false
    for(int i = 1; i <= sum; i++)
        dp[0][i] = false;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            if(j < arr[i-1])                dp[i][j] = dp[i-1][j];
            else if(j >= arr[i-1])          dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
        }
    }

    //------ print the table ----------//
    // cout << "    ";
    // for(int i = 0; i <= sum; i++)
    //     cout << i << "   ";
    // cout << endl;
    //
    // for(int i = 0; i <= n; i++){
    //     if(i > 0)
    //         cout << arr[i-1] << "   ";
    //     else
    //         cout << 0 << "   ";
    //     for(int j = 0; j <= sum; j++)
    //         cout << dp[i][j] << "   ";
    //     cout << endl;
    // }

    return dp[n][sum];
}

// Driver function
int main(){
    vector<int> num({2, 3, 7, 8, 10});
    int sum = 11;

    cout << isSubset(num, num.size(), sum) << endl;

    return 0;
}
