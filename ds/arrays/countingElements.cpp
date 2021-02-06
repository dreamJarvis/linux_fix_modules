#include <bits/stdc++.h>
using namespace std;

int countElements(vector<int>& arr){
    int n = arr.size();

    unordered_map<int, int> mp;
    for(auto item:arr){
        if(mp.count(item)){
            mp[item]++;
        }else
            mp[item] = 1;
    }

    int count = 0;
    for(auto item:arr){
        if(mp.count(item+1)){
            count++;
            mp[item]--;
        }
    }

    return count;
}

// Driver function
int main(){
    vector<int> arr({1,1,2,2});

    cout << countElements(arr) << endl;

    return 0;
}
