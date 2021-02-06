// leetocode 289
#include <bits/stdc++.h>
using namespace std;

// space : O(1)
// time complexity : (n^2)
// count live neighbours
void countLiveNeighbours(vector<vector<int>> &matrix, int r, int c, int rows, int cols){
    int neighbours[] = {0, 1, -1};
    int totalNeighbours = 0;

    for(int i = 0; i < 3; i++){
        for(int j=0; j < 3; j++){
            // except the origin
            if(!(neighbours[i]==0 && neighbours[j]==0)){
                int tempRow = (r + neighbours[i]);
                int tempCol = (c + neighbours[j]);

                // check the validity of the neighbouring cell. and whether it was originally a live cell
                if((tempRow < rows && tempRow >= 0) && (tempCol < cols && tempCol >= 0)
                    && abs(matrix[tempRow][tempCol])==1)
                    totalNeighbours++;
            }
        }
    }

    // -1: the cell was originally alive, but now is dead
    if((matrix[r][c]==1) && (totalNeighbours < 2 || totalNeighbours > 3))
        matrix[r][c] = -1;

    // 2 : cell was originally dead, but now it is alive
    if(matrix[r][c] == 0 && totalNeighbours == 3)
        matrix[r][c] = 2;
}

// UTIL function
void gameOfLife(vector<vector<int>> &matrix){
    int row = matrix.size();
    int col = matrix[0].size();

    for(int r = 0; r < row; r++)
        for(int c = 0; c < col; c++)
            countLiveNeighbours(matrix, r, c, row, col);


    // -1 --> represents the previous alive value
    // 2  --> represents previously dead value
    for(int r = 0; r < row; r++)
        for(int c = 0; c < col; c++)
            if(matrix[r][c] > 0) matrix[r][c] = 1;
            else    matrix[r][c] = 0;
}

// diplay matrix
void display(vector<vector<int>> &arr){
    for(int r = 0; r < arr.size(); r++){
        for(int c = 0; c < arr[0].size(); c++)
            cout << arr[r][c] << "  ";
        cout << endl;
    }
}

// Driver function
int main(){
    vector<vector<int>> arr({{0, 1, 0},
                             {0, 0, 1},
                             {1, 1, 1},
                             {0, 0, 0}
                        });

    gameOfLife(arr);
    display(arr);

    return 0;
}
