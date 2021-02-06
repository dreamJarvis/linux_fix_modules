/*
    21. Overlapping Intervals
    https://practice.geeksforgeeks.org/problems/overlapping-intervals4919/0/?track=amazon-arrays&batchId=192
*/
#include <bits/stdc++.h>
using namespace std;

// O(nlog(n))
vector<pair<int,int>> overlappedInterval(vector<pair<int,int>> vec, int n) {
    sort(vec.begin(), vec.end());

    vector<pair<int, int>> res;
    res.push_back({vec[0].first, vec[0].second});

    for(int i = 1; i < n; i++){
        int st = vec[i].first;
        int ed = vec[i].second;

        int si = res.back().first;
        int ei = res.back().second;

        if(st <= ei){
            if(ed > ei)
                res.back().second= ed;
        }
        else{
            res.push_back({st, ed});
        }
    }

    return res;
}

// Driver function
int main(){
    // vector<pair<int, int>> vec({{1, 3}, {2, 4}, {6, 8}, {9, 10}});
    vector<pair<int, int>> vec({{6, 8}, {1, 9}, {2, 4}, {4, 7}});

    for(auto i:overlappedInterval(vec, vec.size()))
        cout << i.first << ", " << i.second << endl;

    return 0;
}
