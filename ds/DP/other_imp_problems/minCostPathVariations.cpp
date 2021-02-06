#include <bits/stdc++.h>
using namespace std;

// you can only traverse down, right and diagonally lower cells from a given cell
int minPathSumI(vector<vector<int>> &arr){
	int rows = arr.size();
	int cols = arr[0].size();

	vector<vector<int>> dp(rows, vector<int>(cols, 0));

	// setting up initial values
	// setting up values of row
	dp[0][0] = arr[0][0];
	for(int i = 1; i < rows; i++)
		dp[i][0] = arr[i][0] + dp[i-1][0];

	// setting up values of row
	for(int i = 1; i < cols; i++)
		dp[0][i] = arr[0][i] + dp[0][i-1];

	for(int i = 1; i < rows; i++){
		for(int j = 1; j < cols; j++){
			int diagonally = min(dp[i-1][j-1], dp[i-1][j+1]);
			if(j+1 >= cols)
				diagonally = dp[i-1][j-1];

			dp[i][j] = min(dp[i][j-1], min(diagonally, dp[i-1][j])) + arr[i][j];
		}
	}

	return dp[rows-1][cols-1];
}

// leetcode : 64
// You can only move either down or right at any point in time.
// time complexity : O(n^2)
// space complexity : O(n^2)
int minPathSumII(vector<vector<int>> &arr){
	int rows = arr.size();
	int cols = arr[0].size();

	vector<vector<int>> dp(rows, vector<int>(cols, 0));

	// setting up initial values
	// setting up values of row
	dp[0][0] = arr[0][0];
	for(int i = 1; i < rows; i++)
		dp[i][0] = arr[i][0] + dp[i-1][0];

	// setting up values of row
	for(int i = 1; i < cols; i++)
		dp[0][i] = arr[0][i] + dp[0][i-1];

	for(int i = 1; i < rows; i++){
		for(int j = 1; j < cols; j++){
			dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + arr[i][j];
		}
	}

	return dp[rows-1][cols-1];
}

// time complexity : O(n^2)
// space complexity : O(1)
int minPathSumIIOptimised(vector<vector<int>> &arr){
	for(int i = 0; i < arr.size(); i++){
		for(int j = 0; j < arr[0].size(); j++){
			if(i == 0 && j == 0)	continue;
			else if(i == 0)	arr[0][j] += arr[i][j-1];
			else if(j == 0)	arr[i][0] += arr[i-1][j];
			else arr[i][j] += min(arr[i][j-1], arr[i-1][j]);
		}
	}

	return arr[arr.size()-1][arr[0].size()-1];
}

// Driver functions
int main(){
	// vector<vector<int>> arr({
	// 	{1, 2, 3},
	// 	{9, 8, 7},
	// 	{4, 5, 6}
	// });

	// vector<vector<int>> arr({
	// 	{10, 10, 2, 0, 20, 4},
	// 	{1, 0, 0, 30, 2, 5},
	// 	{0, 10, 4, 0, 2, 0},
	// 	{1, 0, 20, 0, 0, 4},
	// });

	// vector<vector<int>> arr({
	// 	{1, 2, 3},
	// 	{4, 8, 2},
	// 	{1, 5, 3}
	// });

	vector<vector<int>> arr({
			{1, 3, 1},
			{1, 5, 1},
			{4, 2, 1}
	});

	cout << minPathSumIIOptimised(arr) << endl;

	return 0;
}
/*
	[[1,3,1],[1,5,1],[4,2,1]]
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
