#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define MAX 10000

int findK(vector<vector<int>> &matrix, int n, int m, int k) {
	int rs(0), re(n - 1);
	int cs(0), ce(m - 1);

	int dir(1), count(0);
	while (cs <= ce && rs <= re) {
		switch (dir) {
		case 1:
			for (int i = cs; i <= ce; i++) {
				count++;
				if (count == k) {
					// cout << matrix[rs][i] << endl;
					return matrix[rs][i];
				}
			}
			rs++;
			dir = 2;
			break;

		case 2:
			for (int i = rs; i <= re; i++) {
				count++;
				if (count == k) {
					// cout << matrix[i][ce] << endl;
					return matrix[i][ce];
				}
			}
			ce--;
			dir = 3;
			break;

		case 3:
			for (int i = ce; i >= cs; i--) {
				count++;
				if (count == k) {
					// cout << matrix[re][i] << endl;
					return matrix[re][i];
				}
			}
			re--;
			dir = 4;
			break;

		case 4:
			for (int i = re; i >= rs; i--) {
				count++;
				if (count == k) {
					// cout << matrix[i][cs] << endl;
					return matrix[i][cs];
				}
			}
			cs++;
			dir = 1;
			break;
		}
	}

	return -1;
}

int main() {
	int r, c, k;
	cin >> r >> c >> k;

	vector<vector<int>> matrix(r, vector<int>(c));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> matrix[i][j];
		}
	}

	cout << findK(matrix, r, c, k) << endl;

	return 0;
}
