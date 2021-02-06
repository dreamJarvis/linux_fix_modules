// rat in a maze
// search a path for the rat in the maze
#include <bits/stdc++.h>
using namespace std;

// can move only forward and down
// searches if there is a path in a maze that leads to solution
// Naive solution : DFS approach
bool searchPath(vector<vector<int>> &matrix, int r, int c, int R, int C){
    // base condition
    if(r > R-1 || c > C-1)
        return false;

    if(r == R-1 && c == C-1 && matrix[r][c])
        return true;

    if(matrix[r][c]==0)
        return false;

    bool forward = searchPath(matrix, r+1, c, R, C);   // forard
    bool down = searchPath(matrix, r, c+1, R, C);   // down

    return (forward||down);
}

// Driver function
int main(){
    vector<vector<int>> matrix({
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    });

    int r = matrix.size();
    int c = matrix[0].size();
    cout << searchPath(matrix, 0, 0, r, c) << endl;
    return 0;
}
