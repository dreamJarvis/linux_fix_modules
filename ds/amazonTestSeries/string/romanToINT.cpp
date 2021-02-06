#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int romanToInt(string s) {
	int res(0);
	for (int i = 0; i < s.length(); i++) {
		char ch = s[i];

		switch (ch) {
		case 'I':
			if (s[i + 1] == 'V') {
				res += 4;
				i++;
			} else if (s[i + 1] == 'X') {
				res += 9;
				i++;
			} else
				res += 1;
			break;

		case 'V':
			res += 5;
			break;

		case 'X':
			if (s[i + 1] == 'L') {
				res += 40;
				i++;
			} else if (s[i + 1] == 'C') {
				res += 90;
				i++;
			} else
				res += 10;
			break;

		case 'L':
			res += 50;
			break;

		case 'C':
			if (s[i + 1] == 'D') {
				res += 400;
				i++;
			} else if (s[i + 1] == 'M') {
				res += 900;
				i++;
			} else
				res += 100;
			break;

		case 'D':
			res += 500;
			break;

		case 'M':
			res += 1000;
			break;
		}
	}

	return res;
}

int main() {
	// string str = "MCMXCIV";
	string str = "LVIII";
	cout << romanToInt(str) << "\n";

	return 0;
}
/*
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/