// to count all the paths that can be taken to reach m*n using temporary array using dp.
#include <bits/stdc++.h>
using namespace std;

float numberOfPathsDP(vector<vector<int>> &matrix, int N){
    if(matrix[0][0] == -1)
        return 0;
    
    for(int i = 1; i < N; i++){
        matrix[i][0] += (matrix[i-1][0] + matrix[i][0]);
    }

    for(int i = 1; i < N; i++){
        matrix[0][i] += (matrix[0][i-1] + matrix[0][i]);
    }

    for(int i = 1; i < N; i++){
        for(int j = 1; j < N; j++){ 
            matrix[i][j] = max(matrix[i-1][j], matrix[i][j-1]) + matrix[i][j];
        }
    }

    return matrix[N-1][N-1]; 
}

// Driver function
int main(){
    int n;
    cin >> n;

    vector<vector<int>> matrix;
    // vector<vector<int>> solution;
    vector<int> row;
    int temp = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> temp;
            row.push_back(temp);
        }
        matrix.push_back(row);
    }

    // solution = matrix;
    printf("%1.1f \n", (float)numberOfPathsDP(matrix, n));
    return 0;
}