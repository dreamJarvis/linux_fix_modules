// subset sum problem
#include <bits/stdc++.h>
using namespace std;

bool subsetSum(vector<int> &arr, int sum){
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(sum+1, false));

    for(int i = 0; i <  n; i++)
        dp[i][0] = true;

    for(int i = 1; i <= sum; i++){
        if(i == arr[0]) dp[0][i] = true;
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j <= sum; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= sum; j++){
            if(j > arr[i])
                dp[i][j] = dp[i-1][j - arr[i]] || dp[i-1][j] ;
            else if(j == arr[i])
                dp[i][j] = true;
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    // cout << "\n\n";
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j <= sum; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }

    return dp[n-1][sum];
}

// Driver Function
int main(){
    int sum = 11;
    vector<int> arr({2, 5, 7, 8, 10});
    cout << subsetSum(arr, sum) << endl;
    return 0;
}
