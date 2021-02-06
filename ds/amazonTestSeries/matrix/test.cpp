#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int maxLen(int arr[], int n) {
	int ans = 0;
	unordered_map<int, int> freq;
	freq[0] = -1;
	int count(0);
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0)
			count--;
		if (arr[i] == 1)
			count++;

		if (freq.count(count)) {
			ans = max(ans, i - freq[count]);
			continue;
		}

		freq[count] = i;
	}

	return ans;
}

int main() {
	// int a[] = {0, 1, 0, 1};
	int a[] = {0, 0, 1, 0, 0};
	int n = sizeof(a) / sizeof(a[0]);

	cout << maxLen(a, n) << "\n";

	return 0;
}