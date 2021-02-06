// To count all the paths to reach destination in a maze
#include <bits/stdc++.h>
using namespace std;

#define R 4
#define C 4

// counts all the paths that can be taken to reach the destination
int countPaths(int maze[][C]){
    // if the initial cell is blocked, there is no way of moving anywhere
    if(maze[0][0] == -1)
        return 0;

    // initializing the leftmost columns
    for(int i = 0; i < R; i++){
        if(maze[i][0] == 0)
            maze[i][0] = 1;

        // agr hme niche jate hue koi -1 mil jata h, usska mtlb hua ki ab ye wala path continue nhi ho skta, ya koi bhi path uss point ke badh nhi ho skta, kyuki usska link starting point se nhi hoga
        else    break;
    }

    // filling the topmost row
    for(int i = 1; i < C; i++){
        if(maze[0][i] == 0)
            maze[0][i] = 1;

        // agr hme side jate hue koi -1 mil jata h, usska mtlb hua ki ab ye wala path continue nhi ho skta, ya koi bhi path uss point ke badh nhi ho skta, kyuki usska link starting point se nhi hoga
        else    break;
    }

    // ab hm iss loop me, current pint tk jina bhi path bn rhe h ussme hm, usse pehle tk kitne path bn rhe them, ek upr aor ek side me, ab current point/index tk ka total path sub ka sum hoga
    // aor agr current index -1 h toh ignore krke aage bdh jao
    for(int i = 1; i < R; i++){
        for(int j = 1; j < C; j++){
            // if bockage is found, ignore this cell
            if(maze[i][j] == -1)
                continue;

            // upr wala index add kr denge current index ke count me
            if(maze[i-1][j] > 0)
                maze[i][j] += maze[i-1][j];

            // left wala index add kr denge current index ke count me
            if(maze[i][j-1] > 0)
                maze[i][j] += maze[i][j-1];
        }
    }

    return (maze[R-1][C-1] > 0) ? maze[R-1][C-1] : 0;
}

// Driver function
int main(){
    int maze[R][C] = {
                    {0,  0, 0, 0},
                    {0, -1, 0, 0},
                    {-1, 0, 0, 0},
                    {0,  0, 0, 0}};

    cout << countPaths(maze) << endl;
    return 0;
}
