// rat in a maze
#include <bits/stdc++.h>
using namespace std;

#define N 4
void printMatrix(int arr[][N], int ,int);

// tells is there exists a path or not in this maze
// sr : current row
// sc : current col
bool ratInMaze(int arr[][N], int sr, int sc, int er, int ec){
    if(sr == er and sc == ec)
        return true;

    if(sr > er or sc > ec)
        return false;

    return (ratInMaze(arr, sr, sc+1, er, ec) or ratInMaze(arr, sr+1, sc, er, ec));
}

// utility function
void printMatrix(int sol[][N], int er, int ec){
    for(int i = 0; i < er; i++){
        for(int j = 0; j < ec; j++){
            cout << sol[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "\n ************************************ \n";
}

// Driver function
int main(){
    // the initial matrix
    int maze[][N] = {
                    {0,  0,  0,  0},
                    {0,  0,  0,  0},
                    {0,  0,  0,  0},
                    {0,  0, -1,  0},
                    {0, -1,  0,  0}
                };
    if(ratInMaze(maze, 0, 0, N, N))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
