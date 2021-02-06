#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

// clockwise
vector<vector<int>> rotateClockwise(vector<vector<int>> &matrix) {
	int n = matrix.size();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++)
			swap(matrix[i][j], matrix[j][i]);
	}

	for (int i = 0; i < n; i++)
		reverse(matrix[i].begin(), matrix[i].end());

	return matrix;
}

// anti - clockwise
vector<vector<int>> rotateAntiClockwise(vector<vector<int>>& matrix) {
	int n = matrix.size();
	int m = matrix[0].size();

	// swapping it by the daigonal's
	for (int i = 0; i < n; i++) {
		int r1 = i, c1 = m - i - 2;
		int r2 = i + 1, c2 = m - i - 1;

		while (c1 >= 0 && r2 < n) {
			swap(matrix[r1][c1], matrix[r2][c2]);
			c1--;
			r2++;
		}
	}

	for (int i = 0; i < n; i++)
		reverse(matrix[i].begin(), matrix[i].end());

	return matrix;
}

int main() {
	int n;
	cin >> n;

	vector<vector<int>> matrix(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}

	vector<vector<int>> ans;
	cout << "clockwise rotation : \n";
	ans = rotateClockwise(matrix);
	for (auto i : matrix) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}

	cout << "Anti-Clockwise rotation : \n";
	ans = rotateAntiClockwise(matrix);
	for (auto i : matrix) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}

	return 0;
}