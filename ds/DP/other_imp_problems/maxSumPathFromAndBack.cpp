// Maximum sum path in a matrix from top to bottom and back
// also : Airport limosine problem (serviceNow 2nd coding round)
// link to the question : https://drive.google.com/open?id=1BeKHbOnfZddIq1JvsOLwL3aO7t8GrqMc
#include <bits/stdc++.h>
using namespace std;

// tabulation : top-down approach
// time  : O(n^2)
// space : O(n^2)
int maxSumPathDP(vector<vector<int>> &matrix, int rows, int cols){
    vector<vector<int>> storage(rows, vector<int>(cols, 0));

    // destination is blocked
    if(matrix[rows-1][cols-1] == -1)    return 0;

    storage[0][0] = matrix[0][0];

    // filling the first row and column
    for(int i = 1; i < rows; i++){
        // if(matrix[0][i] != -1)
            storage[0][i] += (storage[0][i-1] + matrix[0][i]);
        // else    storage[0][i] = 0;
    }

    for(int i = 1; i < cols; i++){
        // if(matrix[i][0] != -1)
            storage[i][0] += (storage[i-1][0] + matrix[i][0]);
        // else    storage[i][0] = 0;
    }

    for(int i = 1; i < rows; i++)
        for(int j = 1; j < cols; j++){
            // if(matrix[i][j] == -1)
                // storage[i][j] = 0;
            storage[i][j] = max(storage[i-1][j],storage[i][j-1] ) + matrix[i][j];
        }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++)
            cout << storage[i][j] << " ";
        cout << endl;
    }

    int temp = min(storage[rows-2][cols-1], storage[rows-1][cols-2]) + storage[rows-1][cols-1];

    return temp;
}

// driver function
int main(){
    vector<vector<int>> maze({
                    {0,  1,   1},
                    {1,  0,  -1},
                    {1,  1,  1}
    });

    int rows = maze.size();
    int cols = maze[0].size();

    cout << maxSumPathDP(maze, rows, cols) << endl;

    return 0;
}
