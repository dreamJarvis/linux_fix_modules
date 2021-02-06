#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

// O(nlog(n))
// O(n)
// using multiset
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    multiset<pair<int, pair<int, int>>> st;
    for (int i = 0; i < points.size(); i++) {
        int x = points[i][0];
        int y = points[i][1];

        int dist = (x * x + y * y);
        st.insert({dist, {x, y}});

        if (st.size() > k) {
            auto it = st.end();
            it--;
            st.erase(it);
        }
    }

    vector<vector<int>> ans;
    for (auto &it : st) {
        ans.push_back({it.second.first, it.second.second});
    }

    return ans;
}

// multimap
// vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
// multimap<int, int> mp;
// for(int i = 0; i < points.size(); i++){
//     int dist = (points[i][0]*points[i][0] + points[i][1]*points[i][1]);
//     mp.insert({(points[i][0]*points[i][0] + points[i][1]*points[i][1]), i});

//     if(mp.size() > k){
//         auto it = mp.end();
//         it--;
//         mp.erase(it);
//     }
// }

// vector<vector<int>> ans;
// for(auto &i:mp){
//     ans.push_back({points[i.second][0], points[i.second][1]});
// }

// return ans;
// }

// Driver function
signed main() {
    FIO;

    int n, k;
    cin >> n >> k;

    vector<vector<int>> points;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        points.push_back({x, y});
    }

    for (auto &i : kClosest(points, k)) {
        for (auto &j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
/*
13 2
-2 -9 8 10 3 1 -3 4 8 6 10 -3 -3 9 10 8 4 7 -2 3 10 -4 2 10 -5 8
*/