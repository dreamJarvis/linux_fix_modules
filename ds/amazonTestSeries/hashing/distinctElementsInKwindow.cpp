#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

vector <int> countDistinct (vector<int> &a, int n, int k) {
    vector<int> res;
    unordered_map<int, int> mp;

    int count(0);
    for (int i = 0; i < k; i++) {
        if (!mp.count(a[i]))
            count++;
        mp[a[i]]++;
    }

    res.push_back(count);
    for (int i = k; i < n; i++) {
        if (mp[a[i - k]] == 1)
            count--;
        mp[a[i - k]]--;

        if (mp[a[i]] == 0)
            count++;
        mp[a[i]]++;

        res.push_back(count);
    }

    return res;
}

int main() {
    // vector<int> a({1, 2, 1, 3, 4, 2, 3});
    // int  K = 4;

    vector<int> a({4, 1, 1});
    int  K = 2;

    for (auto i : countDistinct(a, a.size(), K))
        cout << i << " ";
    cout << "\n";

    return 0;
}
