#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) {
	int rs(0), re(r - 1);
	int cs(0), ce(c - 1);
	int dir(1);

	vector<int> ans;
	while (cs <= ce && rs <= re) {
		switch (dir) {
		case 1:
			for (int i = cs; i <= ce; i++) {
				ans.push_back(matrix[rs][i]);
			}
			rs++;
			dir = 2;
			break;

		case 2:
			for (int i = rs; i <= re; i++) {
				ans.push_back(matrix[i][ce]);
			}
			ce--;
			dir = 3;
			break;

		case 3:
			for (int i = ce; i >= cs; i--) {
				ans.push_back(matrix[re][i]);
			}
			re--;
			dir = 4;
			break;

		case 4:
			for (int i = re; i >= rs; i--) {
				ans.push_back(matrix[i][cs]);
			}
			cs++;
			dir = 1;
			break;
		}
	}

	return ans;
}

// Driver function
int main() {
	int r, c;
	cin >> r >> c;

	vector<vector<int>> matrix(r, vector<int>(c));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> matrix[i][j];
		}
	}

	// spirallyTraverse(matrix, r, c);

	for (auto i : spirallyTraverse(matrix, r, c))
		cout << i << " ";
	cout << endl;

	return 0;
}
