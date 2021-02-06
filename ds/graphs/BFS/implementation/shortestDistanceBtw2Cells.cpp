/*
    Shortest distance between two cells in a matrix or grid
    https://www.geeksforgeeks.org/shortest-distance-two-cells-matrix-grid/
*/
#include<bits/stdc++.h>
using namespace std;

// check's the validiy of the move
bool isValid(int r, int c, int R, int C){
    if(r >= 0 && c >= 0 && r < R && c < C)  return true;
    return false;
}

// we are using BFS to find the shortest possible path btw given source --> destination
// tc : O(V+E)
int shortestPath(vector<vector<char>> &maze, int startX, int startY, int goalX, int goalY){
    int n = maze.size();
    int m = maze[0].size();
    char obstacle = 'X';

    set<pair<int, int>> visited;                    // keeps count of the visited node

    // we are storing row, col seperately for each move we make
    // in-order to avoid little complexity
    queue<int> rows;    // keeps the row's count
    queue<int> cols;    // keeps the col's count
    queue<int> count;   // keeps the count of the number of steps

    // gives us the total number of moves a we can move in the given dir'n
    /*
                    ^(i-1,j)
                    |
        (i, j-1)<-- s(i, j) --> (i, j+1)
                    |
                    v(i+1,j)
    */
    int rDir[] = { 0, 1, 0, -1 };
    int cDir[] = { 1, 0, -1, 0 };

    int r = startX,  c = startY;
    rows.push(r);
    cols.push(c);
    count.push(1);

    // agr queue's empty ho gye , mtlb destination nhi mila
    while(!rows.empty() || !cols.empty()){
        int tempRow = rows.front();
        int tempCol = cols.front();
        int tempCount = count.front();

        rows.pop();
        cols.pop();
        count.pop();

        // if the current position is not marked , mark it visited
        if(visited.find({tempRow, tempCol}) == visited.end())
            visited.insert({tempRow, tempCol});

        // if we have arrived at the destination
        if(isValid(tempRow, tempCol, n, m)){
            if(tempRow == goalX && tempCol == goalY){
                return tempCount;
            }
        }

        // ṃoving in all the possible 4 dir'n
        for(int i = 0; i < 4; i++){
            r = tempRow + rDir[i];
            c = tempCol + cDir[i];

            // we only insert the possible value , if it is feasibel/possible to mive in that dir'n
            if( isValid(r, c, n, m) &&                           // coordinated should be valid
                (visited.find({r, c}) == visited.end()) &&       // shouldn't be already visited
                maze[r][c] != obstacle                           // shouldn't be an obstacle
            ){
                if(r == goalX && c == goalY){     // if goal reached, return
                    return tempCount;
                }

                rows.push(r);
                cols.push(c);
                count.push(tempCount+1);

                visited.insert({r, c});     // because we have already checked it's validity, and we know that it is not destination, .'. we mark is visited
            }
        }
    }

    return -1;
}

// Driver function
int main(){
    vector<vector<char>> arr{
        { '0', '*', '0', 's' },
        { '*', '0', '*', '*' },
        { '0', '*', '*', '*' },
        { 'd', '*', '*', '*' }
    };

    int sr = 0, sc = 3;
    int er = 3, ec = 0;
    cout << shortestPath(arr, sr, sc, er, ec) << endl;

    return 0;
}
