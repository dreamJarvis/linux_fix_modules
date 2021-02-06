// 1365. How Many Numbers Are Smaller Than the Current Number
#include <bits/stdc++.h>
using namespace std;

// 12ms
// using hashmap
vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> result = nums;
    sort(result.begin(), result.end());

    unordered_map<int, int> order;
    int count=0;
    order[result[0]] = 0;
    for(int i = 1; i < result.size(); i++){
        if(result[i] != result[i-1])
            count = i;
        order[result[i]] = count;
    }

    for(int i = 0; i < nums.size(); i++){
        nums[i] = order[nums[i]];
    }

    return nums;
}

// 8ms
// binary search
vector<int> smallerNumbersThanCurrentII(vector<int>& nums) {
    vector<int> temp = nums;
    sort(nums.begin(), nums.end());

    vector<int> result;
    for(int i = 0; i < nums.size(); i++){
        auto index = lower_bound(nums.begin(), nums.end(), temp[i]);
        result.push_back(index - nums.begin());
    }

    return result;
}

// Driver function
int main(){
    vector<int> arr({8,1,2,2,3});

    for(auto i:smallerNumbersThanCurrent(arr))
        cout << i << "\t";
    cout << endl;

    return 0;
}
