// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
#include <bits/stdc++.h>
using namespace std;

void spiralOrder(vector<vector<int>> &arr, int row, int col){
    int top = 0, bottom = row-1, left=0, right=col-1;
    int dir = 0;

    while(bottom >= top && left <= right){
        // moving from left --> right
        if(dir == 0){
            for(int i = left; i <= right; i++)
                cout << arr[top][i] << " ";
            top++;
        }

        // moving from top --> bottom
        else if(dir == 1){
            for(int i = top; i <= bottom; i++)
                cout << arr[i][right] << " ";
            right--;
        }

        // moving from right --> left
        else if(dir == 2){
            for(int i = right; i >= left; i--)
                cout << arr[bottom][i] << " ";
            bottom--;
        }

        // moving from bottom --> top
        else if(dir == 3){
            for(int i = bottom; i >= top; i--)
                cout << arr[i][left] << " ";
            left++;
        }

        dir = (dir+1)%4;
    }
}

// Driver function
int main(){
    vector<vector<int> > matrix {{ 1, 2, 3},
                                 { 4, 5, 6},
                                 { 7, 8, 9}
    };

    int row = matrix.size();
    int col = matrix[0].size();

    spiralOrder(matrix, row, col);

    return 0;
}
