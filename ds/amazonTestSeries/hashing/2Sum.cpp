#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

bool keypair(vector<int> A, int n, int X) {
	unordered_map<int, int> f;
	for (auto i : A)
		f[i]++;

	for (auto i : f) {
		f[i.first]--;
		if (f.count(X - i.first) && f[X - i.first]) {
			return true;
		}
	}

	return false;
}

int main() {
	// vector<int> a({1, 4, 45, 6, 10, 8});
	// vector<int> a({1, 2, 4, 3, 6});
	vector<int> a({1, 2, 5, 6, 7});
	int n = sizeof(a) / sizeof(a[0]);
	int X = 4;

	cout << keypair(a, n, X) << "\n";

	return 0;
}