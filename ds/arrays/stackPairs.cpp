// leetcode 11. Container With Most Water
#include <bits/stdc++.h>
using namespace std;

int stockPairs(vector<int> stocksProfit, long target){
    unordered_map<int, bool> visited;
    for(int i = 0; i < stocksProfit.size(); i++){
        visited[stocksProfit[i]] = true;
    }

    int count = 0;
    for(auto item:stocksProfit){
        int value = target - item;
        if(visited.count(value) && visited[value] && visited[item]){
            count++;
            visited[item] = false;
            visited[value] = false;
        }
    }

    return count;
}

// Driver function
int main(){
    vector<int> arr({5, 7, 9, 13, 6, 6, 3, 3});
    int target = 12;

    cout << stockPairs(arr, target) << endl;

    return 0;
}
