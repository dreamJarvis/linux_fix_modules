#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int>& nums) {
    // check if its empty
    int size = nums.size();
    if(size == 0)   return -1;

    // issme me hm sum ikatta krke rakhenge from 0 -> size - 1 (leftwise)
    vector<int> arr;
    int i = 1;

    // add the first number
    arr.push_back(nums[0]);

    // hm shru hi 1st index se krenge kyuki, 1st se pehle akele no. ka kiss ke sth sum krega ?
    for(i; i < size; i++){
        // add the current number plus the last one
        arr.push_back(arr[i-1] + nums[i]);
    }

    // iss ka mtln h ki 0th index ke left me sbka sum and 0th index ke right pe sum same h
    // arr[size  1] hme pre arr ka sum dega
    if(arr[size - 1] - nums[0] == 0)    return 0;

    for(i = 1; i < size; i++){
        // check if the sum of the elements of the left of arr[i-1]th is same as that of sum of all the elements to its right
        if(arr[i-1] == (arr[size-1] - arr[i]))  return i;
    }

    // agr hmara code yaha tk poch gaya h toh mtlb hme pivot nhi mila h
    return -1;
}

int main(){
    vector<int> arr({-1,-1,-1, 0,-1,-1});
    cout << pivotIndex(arr) << endl;
    return 0;
}
