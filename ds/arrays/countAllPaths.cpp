// to count all the paths from (0, 0) --> (n, n) in an given 2D matrix with obstructions in it
#include <bits/stdc++.h>
using namespace std;

// To count all the paths
// time = O(2^n)
// space : O(2^n)
int countAllPaths(vector<vector<int>> &matrix, int sr, int sc, int er, int ec){
    // basew case :
    if(sr == er && sc == ec)    return 1;

    int right = 0;
    int down = 0;

    // recursiev case
    if(sr != er && matrix[sr+1][sc] != -1)  right = countAllPaths(matrix, sr+1, sc, er, ec);
    if(sc != ec && matrix[sr][sc+1] != -1)  down = countAllPaths(matrix, sr, sc+1, er, ec);

    // returning the result
    return (right + down);
}

// Memoisation : bottom-up approach
// time :  O(n^2) + ?
// space : O(2^n)
int countAllPathsMemo(vector<vector<int>> &matrix, unordered_map<string, int> &dp, int sr,int sc, int er, int ec){
    // key
    string key = to_string(sr) + "," + to_string(sc);

    // base case:
    if(sr == er && sc == ec)    return 1;

    if(dp.count(key))   return dp[key];

    int right = 0;
    int down = 0;

    if(sr != er && matrix[sr+1][sc] != -1)
        right = countAllPathsMemo(matrix, dp, sr+1, sc, er, ec);
    if(sc != ec && matrix[sr][sc+1] != -1)
        down = countAllPathsMemo(matrix, dp, sr, sc+1, er, ec);

    dp[key] = right + down;
    return (right+down);
}

// tabulation : top-down approach
// time : O(n^2)
// space : O(rows*cols)
int countAllPathsDP(vector<vector<int>> &matrix){
    // initializing vector

    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> storage(rows, vector<int>(cols, -1));

    // setting up initials values
    for(int i = 0; i < rows; i++)   storage[0][i] = 0;
    for(int i = 0; i < cols; i++)   storage[i][0] = 0;

    for(int i = 1; i < rows; i++){
        for(int j = 1; j < cols; j++){
            if(matrix[i-1][j-1] != -1){
                storage[i][j] = max(storage[i-1][j], storage[i][j-1]) + 1;
            }
            else{
                storage[i][j] = max(storage[i-1][j], storage[i][j-1]);
            }
        }
    }

    return storage[rows-1][cols-1];
}

// Driver function
int main(){
    vector<vector<int>> matrix({
                                {1,   1,  1},
                                {1,   1,  1},
                                {1,  -1,  1}
    });

    int rows = matrix.size();
    int cols = matrix[0].size();

    // cout << countAllPaths(matrix, 0, 0, rows-1, cols-1) << endl;

    // Memoisation
    // unordered_map<string, int> dp;
    // cout << countAllPathsMemo(matrix, dp, 0, 0, rows-1, cols-1);

    // DP
    cout << countAllPathsDP(matrix) << endl;

    return 0;
}
