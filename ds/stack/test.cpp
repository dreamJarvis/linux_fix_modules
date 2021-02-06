#include <bits/stdc++.h>
using namespace std;

int main(){
    set<pair<int, int>, greater<pair<int,int>>> s;

    s.insert(make_pair(10, 0));
    s.insert(make_pair(9, 2));
    s.insert(make_pair(12, 1));
    s.insert(make_pair(12, 3));

    s.erase(make_pair(12, 3));

    // for(auto i:s)
    //     cout << i.first << " -- " << i.second << endl;
    // cout << endl;

    // auto i = s.begin() ;
    // int x = i->first;
    cout << (s.begin()->first) << endl;

    return 0;
}
/*
0,0,1,1,1,2,2,3,3,4
*/
