// leetcode : 1
#include <bits/stdc++.h>
using namespace std;

pair<int,int> twoSum(vector<int>& nums, int target) {
    pair<int, int> result;
    unordered_multimap<int, int> temp;

    for(int i = 0; i < nums.size(); i++)
        temp.insert(make_pair(nums[i], i));

    for(auto val:temp){
        if(temp.count(target - val.first)){
            if(temp.find(target - val.first)->second != val.second){
                result = make_pair(val.second, temp.find(target - val.first)->second);
                break;
            }
        }
    }

    return result;
}

// typedef pair<int, int> pairs;
int main(){
    vector<int> arr = {3,3};
    int target = 6;

    pair<int, int> result = twoSum(arr, target);
    cout << result.first << " " << result.second << endl;

    return 0;
}
