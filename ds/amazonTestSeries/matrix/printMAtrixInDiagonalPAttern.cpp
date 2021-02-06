#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

// vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
// 	int m = matrix.size();
// 	if (m == 0) return vector<int>();
// 	int n = matrix[0].size();

// 	vector<vector<int>> tmp (m + n - 1);
// 	for (int i = 0; i < m + n - 1 ; i++) {
// 		int row = max(0, i - n + 1);				// row will start incrementing only after all the col's are finished
// 		int col = min(i, n - 1);					// col will get fixed when it reaches n-1

// 		for (; col >= 0 && row < m; row++, col--) {
// 			tmp[i].push_back(matrix[row][col]);
// 		}
// 	}

// 	vector<int> res;
// 	for (int i = 0; i < tmp.size(); i++) {
// 		if (i % 2) res.insert(res.end(), tmp[i].begin(), tmp[i].end());
// 		else res.insert(res.end(), tmp[i].rbegin(), tmp[i].rend());			// reverese the diagonal for odd occurences
// 	}
// 	return res;
// }

vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
	if (matrix.size() == 0 || matrix[0].size() == 0)	return vector<int>();

	int n = matrix.size();
	int m = matrix[0].size();

	vector<int> res;
	for (int i = 0; i < (m + n - 1); i++) {
		int begin_pos = res.size();
		int row = max(0, (i - m + 1));
		int col = min(i, (m - 1));

		for (; row < n && col >= 0; row++, col--)
			res.push_back(matrix[row][col]);

		if (i % 2 == 0)	reverse(res.begin() + begin_pos, res.end());
	}

	return res;
}

int main() {
	// vector<vector<int>> matrix({
	// 	{1, 2, 3},
	// 	{4, 5, 6},
	// 	{7, 8, 9}
	// });

	vector<vector<int>> matrix({
		{1},
		{2},
		{3}
	});

	// vector<vector<int>> matrix({
	// 	{1, 2, 3, 12, 21, 123},
	// 	{4, 5, 6, 13, 22, 124},
	// 	{7, 8, 9, 14, 23, 125},
	// 	{10, 11, 12, 14, 23, 126}
	// });

	// printDaigonally(matrix);

	for (auto i : printDaigonally(matrix))
		cout << i << " ";
	cout << "\n";

	return 0;
}