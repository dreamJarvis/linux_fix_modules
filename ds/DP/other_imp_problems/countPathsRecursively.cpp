// To count all the paths from (0,0) -> (m,n) in an given maze
#include <bits/stdc++.h>
using namespace std;

#define R 4
#define C 4

// return the total no. of paths from (0,0) to (m,n)
// Time Complexity : O(2^n)
int numberOfPaths(int maze[][C], int cr, int cc){
    // base condition: return 1 when we reach the R*C
    if(cr == R-1 and cc == C-1)
        return 1;

    // return 0, if we hit -1
    if(maze[cr][cc] == -1)
        return 0;

    // return 0, if we exceed the given limit
    if(cr > R || cc > C)
        return 0;

    // recur down, jb tk -1 hit nhi kr jate, ya ohit limit exceed nhi ho jata
    int down = numberOfPaths(maze, cr+1, cc);
    int right = numberOfPaths(maze, cr, cc+1);  // recur right, until we hit -1, or exceed the limit

    return (right + down);
}

// Driver function
int main(){
    int maze[R][C] = {
                    {0,  0, 0, 0},
                    {0, -1, 0, 0},
                    {-1, 0, 0, 0},
                    {0,  0, 0, 0}};

    cout << numberOfPaths(maze, 0, 0) << endl;

    return 0;
}