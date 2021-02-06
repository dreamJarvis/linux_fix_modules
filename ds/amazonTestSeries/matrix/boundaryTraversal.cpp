#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

vector<int> boundaryTraversal(vector<vector<int>> matrix, int n, int m) {
	vector<int> ans;

	if (n == 1) {
		for (int i = 0; i < m; i++)
			ans.push_back(matrix[0][i]);
		return ans;
	}
	else if (m == 1) {
		for (int i = 0; i < n; i++)
			ans.push_back(matrix[i][0]);
		return ans;
	}

	for (int i = 0; i < m; i++) {
		ans.push_back(matrix[0][i]);
	}

	for (int i = 1; i < n; i++) {
		ans.push_back(matrix[i][m - 1]);
	}

	for (int i = m - 2; i >= 0; i--) {
		ans.push_back(matrix[n - 1][i]);
	}

	for (int i = n - 2; i > 0; i--) {
		ans.push_back(matrix[i][0]);
	}

	return ans;
}

int main() {
	int r, c;
	cin >> r >> c;

	vector<vector<int>> matrix(r, vector<int>(c));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> matrix[i][j];
		}
	}

	// boundaryTraversal(matrix, r, c);

	for (auto i : boundaryTraversal(matrix, r, c))
		cout << i << " ";
	cout << endl;

	return 0;
}
/*
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

1 2
5 17

3 2
27 9 6 18 7 12

4 1
22 3 21 2
*/
