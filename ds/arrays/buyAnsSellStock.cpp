// leetcode : 121
// Best Time to Buy and Sell Stock
#include <bits/stdc++.h>
using namespace std;

// TLE
// int maxProfit(vector<int> &prices) {
//     int n = prices.size();
//
//     int maxdiff = 0;
//     for(int i = 0; i < n; i++){
//         for(int j = i+1; j < n; j++){
//             maxdiff = max(maxdiff, -(prices[i] - prices[j]));
//         }
//     }
//
//     return maxdiff;
// }

// rt : 16ms
int maxProfit1(vector<int> &arr) {
    int n = arr.size();

    int small = arr[0], diff = INT_MIN;
    for(int i = 1; i < n; i++){
        int currDiff = arr[i] - small;
        if(currDiff > diff){
            diff = currDiff;
            small = min(small, arr[i]);
        }
    }

    return diff;
}

// rt : 4ms
int maxProfit2(vector<int>& prices) {
    if(prices.size() == 0 || prices.size() < 2) return 0;
    int maxProfit = 0, minPrice = prices[0];

    for(int i = 1; i < prices.size(); i++) {
        if(prices[i] > prices[i - 1]) {
            maxProfit = max(maxProfit, prices[i] - minPrice);
        } else {
            minPrice = min(minPrice, prices[i]);
        }
    }

    return maxProfit;
}

// leetcode : 122
// Best Time to Buy and Sell Stock II
int buyAndSellStockII(vector<int>& prices) {
    if(prices.size() <= 1) return 0;
    int sum = 0;

    for(size_t i = 1; i < prices.size(); i++) {
        if(prices[i] - prices[i - 1] > 0) {
            sum += prices[i] - prices[i-1];
        }
    }

    return sum;
}

// Driver function
int main(){
    vector<int> prices({7, 1, 5, 3, 6, 4});
    cout << maxProfit(prices) << endl;

    return 0;
}
