#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int maxLen(int a[], int n) {
	int ans = 0;
	unordered_map<int, int> freq;
	freq[0] = -1;
	int count(0);
	for (int i = 0; i < n; i++) {
		count += a[i];

		if (freq.count(count)) {
			ans = max(ans, i - freq[count]);
			continue;
		}

		freq[count] = i;
	}

	return ans;
}

int main() {
	int a[] = {15, -2, 2, -8, 1, 7, 10, 23};
	int n = sizeof(a) / sizeof(a[0]);

	cout << maxLen(a, n) << "\n";

	return 0;
}