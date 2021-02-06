/*
    print LCS
    https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem?isFullScreen=true
*/
#include <bits/stdc++.h>
using namespace std;

// list<int> helper(  vector<int> a, vector<int> b, int n, int m,
//                 unordered_map<string, list<int>> &dp)
// {
//     string key = to_string(n) + '_' + to_string(m);
//
//     if(n >= a.size() || m >= b.size())
//         return list<int>();
//
//     if(dp.count(key))
//         return dp[key];
//
//     if(a[n] == b[m]){
//         dp[key].push_back(a[n]);
//         dp[key].merge(helper(a, b, n+1, m+1, dp));
//     }
//     else{
//         list<int> left = helper(a, b, n+1, m, dp);
//         list<int> right = helper(a, b, n, m+1, dp);
//
//         if(left.size() > right.size())
//             dp[key] = left;
//         else
//             dp[key] = right;
//     }
//
//     return dp[key];
// }
//
// vector<int> printLCS(vector<int> a, vector<int> b){
//     unordered_map<string, list<int>> dp;
//     list<int> result = helper(a, b, 0, 0, dp);
//
//     vector<int> ans;
//     for(auto &i:result)
//         ans.push_back(i);
//     return ans;
// }

vector<int> printLcsDP(vector<int> a, vector<int> b) {
    int n = a.size();
    int m = b.size();

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>()));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1];
                dp[i][j].push_back(a[i-1]);
            }
            else{
                if(dp[i-1][j].size() > dp[i][j-1].size())
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
    }


    return dp[n][m];
}


// Driver function
int main(){
    // vector<int> a({1, 2, 3, 4, 1});
    // vector<int> b({3, 4, 1, 2, 1, 3});

    vector<int> a({16, 27, 89, 79, 60, 76, 24, 88, 55, 94, 57, 42, 56, 74, 24, 95, 55, 33,  69, 29, 14, 7, 94, 41, 8, 71, 12, 15, 43, 3, 23, 49, 84, 78, 73, 63, 5, 46, 98, 26, 40, 76, 41, 89, 24, 20, 68, 14, 88, 26});

    vector<int> b({27, 76, 88, 0, 55, 99, 94, 70, 34, 42, 31, 47, 56, 74, 69, 46, 93, 88, 89, 7, 94, 41, 68, 37, 8, 71, 57, 15, 43, 89, 43, 3, 23, 35, 49, 38, 84, 98, 47, 89, 73, 24, 20, 14, 88, 75});

    for(auto i:printLCS(a, b))
        cout << i << " ";
    cout << endl;

    return 0;
}
/*
16 27 89 79 60 76 24 88 55 94 57 42 56 74 24 95 55 33 69 29 14 7 94 41 8 71 12 15 43 3 23 49 84 78 73 63 5 46 98 26 40 76 41 89 24 20 68 14 88 26
27 76 88 0 55 99 94 70 34 42 31 47 56 74 69 46 93 88 89 7 94 41 68 37 8 71 57 15 43 89 43 3 23 35 49 38 84 98 47 89 73 24 20 14 88 75

27 76 88 55 94 42 56 74 69 7 94 41 8 71 15 43 3 23 49 84 98 89 24 20 14 88

*/
