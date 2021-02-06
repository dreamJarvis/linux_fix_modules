#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

// vector<int> TopK(vector<int>& a, int k){
//     sort(a.begin(), a.end());
//     unordered_map<int, int> freq;
//     for(auto&i:a){
//         freq[i]++;
//     }
//
//     set<pair<int, int>> st;
//     for(auto &i:freq){
//         st.insert({i.second, i.first});
//     }
//
//     auto it = st.end();
//     it--;
//
//     vector<int> ans;
//     for(int i = 0; i < k; i++){
//         ans.push_back(it->second);
//         it--;
//     }
//
//     return ans;
// }

vector<int> TopK(vector<int>& a, int k){
    unordered_map<int, int> mp;
    priority_queue<pair<int, int>> pq;
    vector<int> res;

    for(int i = 0;i < a.size(); i++)
        mp[a[i]]++;

    for(auto &i:mp)
        pq.push({i.second, i.first});

    while(k--){
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;
}

// Driver function
int main(){
    // vector<int> arr({1,1,1,2,2,3});
    // int k = 2;

    vector<int> arr({1,1,2,2,3,3,3,4});
    int k = 2;

    for(auto &i:TopK(arr, k)){
        cout << i << " ";
    }
    cout << endl;

    cin.get();
    return 0;
}
/*
1,1,2,2,3,3,3,4
*/
