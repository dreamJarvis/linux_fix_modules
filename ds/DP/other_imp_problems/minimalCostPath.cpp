// Given a cost matrix cost[][] and a position (m, n) in cost[][], write a function that returns cost of minimum cost path to reach (m, n) from (0, 0). Each cell of the matrix represents a cost to traverse through that cell. Total cost of a path to reach (m, n) is sum of all the costs on that path (including both source and destination). You can only traverse down, right and diagonally lower cells from a given cell, i.e., from a given cell (i, j), cells (i+1, j), (i, j+1) and (i+1, j+1) can be traversed. You may assume that all costs are positive integers.
#include <bits/stdc++.h>
using namespace std;

// min cost path
int minCostPath(vector<vector<int>> &matrix, int rows, int cols){
    // dp storage
    vector<vector<int>> dp(rows, vector<int>(cols, 0));

    dp[0][0] = matrix[0][0];

    // filling the initial values
    for(int i = 1; i < rows; i++)   storage[0][i] = (storage[0][i-1] + matrix[0][i]);
    for(int i = 1; i < cols; i++)   storage[i][0] = (storage[i-1][0] + matrix[i][0]);

    for(int i = 1; i < rows; i++){
        
    }
}

// Driver function
int main(){
    vector<vector<int>> matrix({
                    {1, 2, 3},
                    {4, 8, 2},
                    {1, 5, 3}
    });

    int rows = maze.size();
    int cols = maze[0].size();

    cout << minCostPath(matrix, rows, cols) << endl;

    return 0;
}
