/*
    https://practice.geeksforgeeks.org/problems/search-in-a-matrix17201720/1
    Search in a matrix
*/
#include <bits/stdc++.h>
using namespace std;

int matSearch(vector <vector <int>> &matrix, int N, int M, int targetValue){
    if(N == 0 || M == 0)    return 0;

    int smallest = matrix[0][0], largest = matrix[N-1][M-1];
    if(targetValue < smallest || targetValue > largest)
        return 0;

    int i = 0, j = M-1;
    while(i < N && j >= 0){
        if(matrix[i][j] == targetValue)
            return 1;
        if(matrix[i][j] > targetValue)
            j--;
        else
            i++;
    }

    return 0;
}

// Driver function
int main(){
    vector<vector<int>> matrix({
        {-3, 1, 31, 40},
        {10, 33, 40, 660},
        {22, 43, 161, 702}
    });

    int rowCount = matrix.size();
    int columnCount = matrix[0].size();
    int targetValue =22;

    cout << matSearch(matrix, rowCount, columnCount, targetValue) << endl;

    return 0;
}
