#include<bits/stdc++.h>
using namespace std;

// dfs wake tareeke se kr skte h
int countNoOfIslands(Vector<int> &arr, int r, int c, int R, int C){

    int count = 0;
    int top = countNoOfIslands(arr, r+1, c, R, C);      // top
    int left = countNoOfIslands(arr, r, c+1, R, C);      // left
    int right = countNoOfIslands(arr, r, c-1, R, C);      // right
    int bottom = countNoOfIslands(arr, r-1, c, R, C);      // bottom

    return (top || left || right || bottom);
}

// Driver function
int main() {
    vector<vector<int>> arr({
        {1, 1, 0},
        {0, 1, 0},
        {1, 0, 0}
    });

    int r = arr.size();
    int c = arr[0].size();
    cout << countNoOfIslands(arr, r, c) << endl;

    return 0;
}
