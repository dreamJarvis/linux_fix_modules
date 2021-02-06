// Maximum Sum path
#include <bits/stdc++.h>
using namespace std;

// max sum of the path if allowed to move right or down
int maxPathSumDownAndRight(vector<vector<int>> &arr){
	int rows = arr.size();
	int cols = arr[0].size();

	// if allowed to move right or down
	vector<vector<int>> dp(rows+1, vector<int>(cols+1, 0));
	for(int i = 1; i < rows+1; i++)
		for(int j = 1; j < cols+1; j++)
			dp[i][j] = max(dp[i][j-1], dp[i-1][j]) + arr[i-1][j-1];

	return dp1[rows][cols];
}

// max sum of the path if you are allowed to move only down or diagonally to left or right
// for reference question : https://www.geeksforgeeks.org/maximum-path-sum-matrix/
int maxPathSumDownAndDiagonally(vector<vector<int>> &arr){
	int rows = arr.size();
	int cols = arr[0].size();

	// if you are allowed to move only down or diagonally to left or right
	vector<vector<int>> dp2(rows+1, vector<int>(cols+1, 0));
	for(int i = 1; i < rows+1; i++){
		for(int j = 1; j < cols+1; j++){
			int diagonally = 0;
			if(j+1 < cols+1)	diagonally = max(dp2[i-1][j-1], dp2[i-1][j+1]);
			else				diagonally = dp2[i-1][j-1];

			dp2[i][j] = max(dp2[i-1][j], diagonally) + arr[i-1][j-1];
		}
	}

	return dp2[rows][cols];
}

// Driver functions
int main(){
	// vector<vector<int>> arr({
	// 	{1, 2, 3},
	// 	{9, 8, 7},
	// 	{4, 5, 6}
	// });

	vector<vector<int>> arr({
		{10, 10, 2, 0, 20, 4},
		{1, 0, 0, 30, 2, 5},
		{0, 10, 4, 0, 2, 0},
		{1, 0, 20, 0, 0, 4},
	});

	cout << maxPathSumDownAndDiagonally(arr) << endl;
    cout << maxPathSumDownAndDiagonally(arr) << endl;

	return 0;
}
/*
	Input : mat[][] = 10 10  2  0 20  4
                   1  0  0 30  2  5
                   0 10  4  0  2  0
                   1  0  2 20  0  4
	Output : 74
	The maximum sum path is 20-30-4-20.

	Input : mat[][] = 1 2 3
	                  9 8 7
	                  4 5 6
	Output : 17
	The maximum sum path is 3-8-6.
*/
