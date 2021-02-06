#include <bits/stdc++.h>
using namespace std;

// O(n)
int pairs(int k, vector<int> arr) {
    unordered_map<int, int> map;

    for(auto i:arr){
        map[i]++;
    }

    int totalPairs = 0;
    for(auto i:map){
        int temp2 = i.first + k;
        if(map.count(temp2)){
            totalPairs++;
        }
    }

    return totalPairs;
}

int main(){
    vector<int> arr({1, 5, 3, 4, 2});
    int diff = 2;

    cout << pairs(diff, arr) << endl;

    return 0;
}
