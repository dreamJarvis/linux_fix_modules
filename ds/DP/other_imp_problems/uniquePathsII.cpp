// leetcode 63. Unique Paths
#include <bits/stdc++.h>
using namespace std;

int uniquePathsII(vector<vector<int>> &matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    if(matrix[0][0]==1) return 0;

    // dp[0][0] = 0;
    bool flag = false;
    for(int i = 0; i < m; i++){
        if(matrix[i][0]==1){
            dp[i][0] = 0;
            flag = true;
        }
        else if(flag)
            dp[i][0] = 0;
        else
            dp[i][0] = 1;
    }

    flag = false;
    for(int j = 1; j < n; j++){
        if(matrix[0][j]==1){
            dp[0][j] = 0;
            flag = true;
        }
        else if(flag)
            dp[0][j] = 0;
        else
            dp[0][j] = 1;
    }

    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(matrix[i][j] == 1)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[m-1][n-1];
}

// Driver function
int main(){
    // vector<vector<int>> matrix({
    //     {0, 0, 0},
    //     {0, 1, 0},
    //     {0, 0, 0}
    // });

    vector<vector<int>> matrix({
        {{1}, {0}}
    });

    cout << uniquePathsII(matrix) << endl;

    return 0;
}
