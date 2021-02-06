#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

vector<string> findMatchedWords(vector<string> dict, string pattern) {
    unordered_map<char, int> mp;
    for (auto i : pattern) {
        mp[i]++;
    }

    vector<int> f;
    for (auto i : pattern) {
        if (mp[i] != -1)
            f.push_back(mp[i]);
        mp[i] = -1;
    }

    vector<string> res;
    for (int i = 0; i < dict.size(); i++) {
        unordered_map<char, int> fq;
        for (auto j : dict[i]) {
            fq[j]++;
        }

        vector<int> tmp;
        for (auto j : dict[i]) {
            if (fq[j] != -1)
                tmp.push_back(fq[j]);
            fq[j] = -1;
        }

        bool flag(true);
        for (int j = 0; j < f.size(); j++)
            if (tmp[j] != f[j]) {
                flag = false;
                break;
            }

        if (flag) {
            res.push_back(dict[i]);
        }
    }

    return res;
}

int main() {
    vector<string> dict({"abb", "abc", "xyz", "xyy"});
    string pattern = "foo";

    for (auto i : findMatchedWords(dict, pattern))
        cout << i << " ";
    cout << "\n";

    return 0;
}
