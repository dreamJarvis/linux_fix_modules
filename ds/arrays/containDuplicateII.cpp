// 220. Contains Duplicate III
#include <bits/stdc++.h>
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    unordered_set<int> freq;
    int n = nums.size();

    if(k <= 0) return 0;
    if(k >= n) k = n-1;

    for(int i = 0; i < n; i++){
        if(i > k){

        }

        for()
    }

    return false;
}

// Driver function
int main(){
    // vector<int> arr({1, 2, 3, 1});
    // int k=3, t=0;
    // vector<int> arr({1, 0, 1, 1});
    // int k=1, t=2;
    vector<int> arr({1, 5, 9, 1, 5, 9});
    int k=2, t=3;

    cout << containsNearbyAlmostDuplicate(arr, k, t) << endl;

    return 0;
}
