// Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.
#include <bits/stdc++.h>
using namespace std;

// time complexity : O(n^2)
// space complexity : O(1)
void setMatrixToZero3(vector<vector<int>> &matrix){
    int row = matrix.size();
    int col = matrix[0].size();

    // yaha pe, hm check krenge ki first row me koi 0 h ki nhi, agr h toh firstRowZero ki value true
    bool firstRowZero = false;
    for(int i = 0; i < col; i++)
        if(matrix[0][i] == 0)
            firstRowZero = true;


    // hm first row ko as a container use krenge jo btayega ki i'column me koi value 0 h ya nhi
    // pure matrix me jaha pe bhi 0 milegi toh uss index ke corresponding 0th row ke i'th columns 0 mark ho jayega, matrix[0][i] = 0
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(matrix[i][j] == 0){
                matrix[0][j] = 0;
            }
        }
    }

    for(int i = 1; i < row; i++){

        // yaha check krenge ki iss row me zero h ya nhi
        bool containsZero = false;
        for(int j = 0; j < col; j++)
            if(matrix[i][j]==0){
                containsZero = true;
                break;
            }

        // ab matrix[i][j] pe 0 bhi hoga jb usske row or usske col me 0 value ho
        for(int j = 0; j < col; j++){
            if(matrix[0][j]==0 || containsZero){
                matrix[i][j] = 0;
            }
        }
    }

    if(firstRowZero)
        for(int i = 0; i < col; i++)
            matrix[0][i] = 0;
}


// time complexity : O(n^2)
// space complexity : O(col)
void setMatrixToZero2(vector<vector<int>> &matrix){
    int row = matrix.size();
    int col = matrix[0].size();

    // tells if there is a 0 in that row or col
    vector<bool> colFlag(col, false);

    // setting the value for rowFlag and colFlag
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(matrix[i][j] == 0){
                colFlag[j] = true;
            }
        }
    }

    for(int i = 0; i < row; i++){
        bool containsZero = false;
        for(int j = 0; j < col; j++)
            if(matrix[i][j]==0){
                containsZero = true;
                break;
            }

        for(int j = 0; j < col; j++){
            if(containsZero || colFlag[j]){
                matrix[i][j] = 0;
            }
        }
    }
}

// time complexity : O(n^2)
// space complexity : O(row + col)
void setMatrixToZero(vector<vector<int>> &matrix){
    int row = matrix.size();
    int col = matrix[0].size();

    // tells if there is a 0 in that row or col
    vector<bool> rowFlag(row, false);
    vector<bool> colFlag(col, false);

    // setting the value for rowFlag and colFlag
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(matrix[i][j] == 0){
                rowFlag[i] = true;
                colFlag[j] = true;
            }
        }
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(rowFlag[i] || colFlag[j]){
                matrix[i][j] = 0;
            }
        }
    }
}

// Driver function
int main(){
    vector<vector<int>> matrix({{1, 1, 0, 1},
                               {1, 1, 1, 1},
                               {0, 1, 1, 1}
                            });

    // // method : 1
    // setMatrixToZero(matrix);

    // // method 2
    // setMatrixToZero2(matrix);

    // method 3
    setMatrixToZero3(matrix);

    int row = matrix.size();
    int col = matrix[0].size();
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++)
            cout << matrix[i][j] << "  ";
        cout << endl;
    }

    return 0;
}
