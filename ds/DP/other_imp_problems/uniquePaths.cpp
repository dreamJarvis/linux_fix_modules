// leetcode 62. Unique Paths
#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n){
    vector<vector<int>> arr(m, vector<int>(n, 0));

    arr[0][0] = 0;
    for(int i = 1; i < m; i++)
        arr[i][0] = 1;

    for(int j = 1; j < n; j++)
        arr[0][j] = 1;

    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            arr[i][j] = arr[i-1][j] + arr[i][j-1];
        }
    }

    return arr[m-1][n-1];
}

// Driver function
int main(){
    int m = 7;
    int n = 3;

    cout << uniquePaths(m, n) << endl;

    return 0;
}
