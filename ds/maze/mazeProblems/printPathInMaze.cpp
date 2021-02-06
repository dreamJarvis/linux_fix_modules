// given a maze, print the path from [0][0] --> [n-1][m-1]
#include <bits/stdc++.h>
using namespace std;

// checks whether it is safe or not to traverse that path
bool isSafe(vector<vector<int>> &matrix, int r, int c, int R, int C){
    if(r >=0 && r < R && c >= 0 && c < C && matrix[r][c])
        return true;
    return false;
}

// prints the path
void printSol(vector<vector<int>> &sol, int R, int C){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
}

// check the path to destination
// recursion and Backtracking
bool printPathUtil(vector<vector<int>> &matrix, vector<vector<int>> &sol, int r, int c, int R, int C){
    // reaching the destination
    if(r == R-1 && c == C-1 && matrix[r][c]==1){
        sol[r][c] = 1;  // put the path true
        return true;
    }

    // is it safe to put the rat here
    if(isSafe(matrix, r, c, R, C)){
        sol[r][c] = 1;  // marks true, if we get a path from this position

        // moving forward
        if(printPathUtil(matrix, sol, r+1, c, R, C))
            return true;

        // moving downward
        if(printPathUtil(matrix, sol, r, c+1, R, C))
            return true;

        // if there is no path in forward and downward dir^n then mark this position false i.e. = 0
        sol[r][c] = 0;      // Backtracking
    }
    return false;
}

void printPath(vector<vector<int>> &matrix){
    int r = matrix.size();
    int c = matrix[0].size();
    vector<vector<int>> solution(r, vector<int>(c, 0));

    printPathUtil(matrix, solution, 0, 0, r, c);
    printSol(solution, r, c);
}

// Driver function
int main(){
    vector<vector<int>> matrix({
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {1, 1, 1, 1}
    });

    printPath(matrix);
    return 0;
}
