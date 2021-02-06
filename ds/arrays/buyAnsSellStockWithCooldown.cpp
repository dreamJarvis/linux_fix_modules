// leetcode : 309
// Best Time to Buy and Sell Stock with Cooldown
#include <bits/stdc++.h>
using namespace std;

// int sellStockWithCooldown(vector<int> &arr){
//     int n = arr.size();
//     int dp[n][n-1];
//     memset(dp, -1, sizeof(dp));
//
//     // saving values
//     // pehli value chd ke bhi values add kr skte h
//     for(int i = 0; i < n; i++){
//         for(int j = i+1; j < n; j++){
//             dp[i][j-1] = (arr[j] - arr[i]);
//         }
//     }
//
//     // for(int i = 0; i < n; i++){
//     //     for(int j = 1; j < n; j++){
//     //         cout << dp[i][j-1] << "  ";
//     //     }
//     //     cout << endl;
//     // }
//
//     int maxProfit = 0;
//     for(int i = 0; i < n; i++){
//         for(int j = i+1; j < n; j++){
//             int tr = j+2;
//             int tc = tr+1;
//             if(tr < n && tc < n){
//                 int sum = dp[i][j-1] + dp[tr][tc-1];
//                 maxProfit = max(maxProfit, sum);
//             }
//         }
//     }
//
//     // cout << maxProfit << endl;
//     return maxProfit;
// }

int sellStockWithCooldown(vector<int> &arr){
    int n = arr.size();
    int dp[n][n];
    memset(dp, -1, sizeof(dp));

    // saving values
    // pehli value chd bhi toh skte h
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            dp[i][j] = (arr[j] - arr[i]);
        }
    }

    // display
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << dp[i][j] << "\t";
    //     }
    //     cout << endl;
    // }

    int maxProfit = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int sum = dp[i][j] ;

            int tr = j+2;
            int tc = tr+1;
            if(tr < n && tc < n){
                sum += dp[tr][tc];
                maxProfit = max(maxProfit, sum);
            }
        }
    }

    // cout << maxProfit << endl;
    return maxProfit;
}


int maxProfit(vector<int> &prices){
    if(prices.size() < 2)   return 0;

    int n = prices.size();

    vector<int> buy(n+1);
    vector<int> sell(n+1);

    // kyuki array 1 --> n tk chlega (not 0 --> n tk)
    buy[1] = -prices[0];

    for(int i = 2; i <= n; i++){
        int price = prices[i-1];
        buy[i] = max(buy[i-1], sell[i-2]-price);
        sell[i] = max(sell[i-1], buy[i-1]+price);
    }

    return sell[n];
}


// Driver function
int main(){
    vector<int> prices({1, 2, 3, 0, 2});
    // vector<int> prices({2,1,2,1,0,0,1});

    // cout << sellStockWithCooldown(prices) << endl;
    cout << maxProfit(prices) << endl;

    // sellStockWithCooldown(prices);


    return 0;
}
/*
    [2,1,2,1,0,0,1]
*/
