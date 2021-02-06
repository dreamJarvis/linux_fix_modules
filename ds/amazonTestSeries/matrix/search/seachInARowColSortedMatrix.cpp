#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int n = matrix.size();
	int m = matrix[0].size();

	int r = 0, c = m - 1;
	while (r < n && c >= 0) {
		if (matrix[r][c] == target) {
			return true;
		}

		if (matrix[r][c] > target) {
			c--;
		}
		else {
			r++;
		}
	}

	return false;
}

int main() {
	int r, c , target;
	cin >> r >> c >> target;

	vector<vector<int>> matrix(r, vector<int>(c));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> matrix[i][j];
		}
	}

	for (auto &i : matrix) {
		for (auto &j : i)
			cout << j << " ";
		cout << endl;
	}

	cout << searchMatrix(matrix, target) << endl;

	return 0;
}
/*
5 5 5
1 4 7 11 15
2 5 8 12 19
3 6 9 16 22
10 13 14 17 24
18 21 23 26 30



*/