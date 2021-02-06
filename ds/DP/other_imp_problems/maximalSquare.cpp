// 221. Maximal Square
#include <bits/stdc++.h>
using namespace std;

// dfs approach
int maximumSquareDFS(vector<vector<int>> &matrix, int i, int j, int &maxSize){
    // base condition
    if(i==0||j==0){
        maxSize = max(maxSize, matrix[i][j]);
        return matrix[i][j];
    }

    // find the largest square matrix ending at mat[i][j-1]
    int left = maximumSquareDFS(matrix, i, j-1, maxSize);

    // find the largest square matrix ending at mat[i-1][j]
    int top = maximumSquareDFS(matrix, i-1, j, maxSize);

    // find the largest matrix ending at mat[i-1][j-1]
    int diag = maximumSquareDFS(matrix, i-1, j-1, maxSize);

    // largest square matrix ending at matrix[i][j] will be + 1 of
    // minimum of largest square matrix ending at matrix[i][j-1], matrix[i-1][j] and matrix[i-1][j-1]
    int size = 0;
    if(matrix[i][j])
        size = 1 + min(min(left, top), diag);

    // update the maximum size found so far
    maxSize = max(maxSize, size);

    // return the size of largest square matrix ending at matrix[i][j]
    return size;
}

int maximumSquareUTIL(vector<vector<int>> &matrix){
    int row = matrix.size();
    int col = matrix[0].size();
    int maxSize = 0;
    maximumSquareDFS(matrix, row-1, col-1, maxSize);
    return maxSize*maxSize;
}

// memoisation
int maximumSquareMemo(vector<vector<int>> &matrix, int i, int j, int &maxSize, unordered_map<string , int> &dp){
    string key = to_string(i) + "_" + to_string(j);

    // base condition
    if(i==0||j==0){
        maxSize = max(maxSize, matrix[i][j]);
        return matrix[i][j];
    }

    if(dp.count(key))
        return dp[key];

    // find the largest square matrix ending at mat[i][j-1]
    int left = maximumSquareMemo(matrix, i, j-1, maxSize, dp);

    // find the largest square matrix ending at mat[i-1][j]
    int top = maximumSquareMemo(matrix, i-1, j, maxSize, dp);

    // find the largest matrix ending at mat[i-1][j-1]
    int diag = maximumSquareMemo(matrix, i-1, j-1, maxSize, dp);

    // largest square matrix ending at matrix[i][j] will be + 1 of
    // minimum of largest square matrix ending at matrix[i][j-1], matrix[i-1][j] and matrix[i-1][j-1]
    int size = 0;
    if(matrix[i][j]){
        size = 1 + min(min(left, top), diag);
    }

    // i, j tk jitna max squzre ka size aaya h, ussko save kr lenge, taki jb badh me hm iss point pr wapis aayenge, toh hme isske aage dobara recurse na krna pde, we do it inorder to save time on repeating sub-problems
    dp[key] = size;

    // update the maximum size found so far
    maxSize = max(maxSize, size);

    // return the size of largest square matrix ending at matrix[i][j]
    return size;
}

// ye bhi memoisation he h, but instead of using an external memory storage, hm yaha pr diye hue matrix ka he upyog krte h
// that is inplace storage kr rhe h, kyuki jb hm recuirse krte h, then we always need the next values, and only use the max sqaure till previous value
// toh matrix[i][j]'th index pr jb hm max square ki value nikal lenge tb hm use whi store kr denge, taki next time jb yhi sub-problem repeat ho toh hmare paas already usski value stored hogi, hme unnecessary recursion nhi krna pdega.
int maximumSquareInPlaceMemo(vector<vector<int>> &matrix, int i, int j, int &maxSize){
    // base condition
    if(i==0||j==0){
        maxSize = max(maxSize, matrix[i][j]);
        return matrix[i][j];
    }

    if(matrix[i][j]>1)
        return matrix[i][j];

    int left = maximumSquareInPlaceMemo(matrix, i, j-1, maxSize);
    int top = maximumSquareInPlaceMemo(matrix, i-1, j, maxSize);
    int diag = maximumSquareInPlaceMemo(matrix, i-1, j-1, maxSize);

    int size = 0;
    if(matrix[i][j]){
        size = 1 + min(min(left, top), diag);
    }

    maxSize = max(maxSize, size);
    matrix[i][j] = size;

    return size;
}

int maximumSquareMemoUtil(vector<vector<int>> &matrix){
    int row = matrix.size();
    int col = matrix[0].size();
    int maxSize = 0;

    for(int i = 0; i < row; i++){
        if(matrix[i][0]){
            maxSize = 1;
            break;
        }
    }

    for(int i = 1; i < col; i++){
        if(matrix[0][i]){
            maxSize = 1;
            break;
        }
    }

    //** memoisation with external storage
    // unordered_map<string , int> dp;
    // maximumSquareMemo(matrix, row-1, col-1, maxSize, dp);

    // in-place memoisation ke liye
    maximumSquareInPlaceMemo(matrix, row-1, col-1, maxSize);
    return (maxSize*maxSize);
}

// ** DP

// time complexity : O(n^2)
// space complexity : O(n*m)
int maximumSquare(vector<vector<int>> &matrix){
    int row = matrix.size();
    int col = matrix[0].size();

    vector<vector<int>> dp(row, vector<int>(col, 0));
    int largestSq = 0;

    for(int i = 0; i < col; i++){
        dp[0][i] = matrix[0][i];
        largestSq = max(largestSq, matrix[0][i]);
    }

    for(int i = 1; i < row; i++){
        dp[i][0] = matrix[i][0];
        largestSq = max(largestSq, matrix[i][0]);
    }

    for(int i = 1; i < row; i++){
        for(int j = 1; j < col; j++){
            if(matrix[i][j] == 1){
                dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]))+1;
                largestSq = max(largestSq, dp[i][j]);
            }
        }
    }

    // for(int i = 0; i < row; i++){
    //     for(int j = 0; j < col; j++){
    //         cout << dp[i][j] << "  ";
    //     }
    //     cout << endl;
    // }

    return (largestSq*largestSq);
}

// space optimied : O(m+n)
int maximumSquareOptimised(vector<vector<int>> &matrix){
    int row = matrix.size();
    int col = matrix[0].size();

    // kyuki hm col wise traverse kr rhe h
    vector<int> prev(col, 0);
    vector<int> curr(col, 0);
    int largestSq = 0;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(!i || !j || !matrix[i][j])
                curr[j] = matrix[i][j];
            else {
                curr[j] = min(prev[j-1], min(prev[j], curr[j-1])) + 1;
            }

            largestSq = max(largestSq, curr[j]);
        }
        fill(prev.begin(), prev.end(), 0);
        swap(prev, curr);
    }

    return (largestSq*largestSq);
}

// space optimied : O(n)
int maximumSquareOptimisedII(vector<vector<int>> &matrix){
    if(matrix.empty())
        return 0;

    int row = matrix.size();
    int col = matrix[0].size();
    int maxSize = 0;

    for(int j=0; j < col; j++){
        if(matrix[0][j]){
            maxSize = 1;
            break;
        }
    }

    for(int i = 1; i < row; i++){
        maxSize = max(maxSize, matrix[i][0]);
        for(int j = 1; j < col; j++){
            if(matrix[i][j]){
                matrix[i][j] = min(matrix[i-1][j-1], min(matrix[i-1][j], matrix[i][j-1])) + 1;
                maxSize = max(maxSize, matrix[i][j]);
            }
        }
    }

    return (maxSize*maxSize);
}

// Driver function
int main(){
    // vector<vector<int>> matrix({
    //     {1, 0, 1, 0, 0},
    //     {1, 0, 1, 1, 1},
    //     {1, 1, 1, 1, 1},
    //     {1, 0, 0, 1, 0}
    // });

    // vector<vector<int>> matrix({
    //     {0, 0, 0, 1},
    //     {1, 1, 0, 1},
    //     {1, 1, 1, 1},
    //     {0, 1, 1, 1},
    //     {0, 1, 1, 1}
    // });

    // vector<vector<int>> matrix({
    //     // {{1}, {1}}
    //     // {{1, 0},{1,1}}
    // });

    vector<vector<int>> matrix({
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 1, 1, 0, 0, 0}
    });

    // vector<vector<int>> matrix({{0}});

    cout << maximumSquareOptimisedII(matrix) << endl;

    return 0;
}
/*
[["0","0","0","0","0"],
["0","0","0","0","0"],
["0","0","0","0","1"],
["0","0","0","0","0"]]

0	0	0	1
1	1	1	1
1	2	2	2
0	2	3	3
0	2	3	4

[
["1","1","1","1","1","1","1","1"],
["1","1","1","1","1","1","1","0"],
["1","1","1","1","1","1","1","0"],
["1","1","1","1","1","0","0","0"],
["0","1","1","1","1","0","0","0"]
]

*/
