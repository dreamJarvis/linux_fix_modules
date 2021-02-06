// 219. Contains Duplicate II
#include <bits/stdc++.h>
using namespace std;

// bool containsNearbyDuplicate(vector<int>& nums, int k) {
//     int n = nums.size();
//     if(n==0)    return false;
//     if(k==1 && n==1)  return false;
//
//     unordered_map<int, int> freq;
//     int i = 0;
//     if(k >= n){
//         for(i = 0; i < n; i++){
//             if(freq.count(nums[i]))
//                 return true;
//             freq[nums[i]]++;
//         }
//     }
//     else{
//         for(i = 0; i < k; i++){
//             if(freq.count(nums[i]))
//                 return true;
//             freq[nums[i]]++;
//         }
//
//         for(int j = 0; j < n-k; j++, i++){
//             freq[nums[i]]++;
//
//             if(freq.count(nums[i]) && freq[nums[i]]>1)
//                 return true;
//
//             freq[nums[j]]--;
//         }
//     }
//
//     return false;
// }

// bool containsNearbyDuplicate(vector<int>& nums, int k) {
//     unordered_map<int,int> a;
//
//     for(int i=0; i < nums.size(); i++){
//         if(a.find(nums[i]) != a.end())
//             if(i-a[nums[i]]<=k)
//                 return true;
//
//         a[nums[i]]=i;
//     }
//     return false;
// }

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> freq;
    int n = nums.size();
    if(k <= 0)  return false;
    if(k >= n)   k = n-1;

    for(int i=0; i < n; i++){
        if(i>k) freq.erase(nums[i-k-1]);
        if(freq.find(nums[i]) != freq.end()) return true;
        freq.insert(nums[i]);
    }

    return false;
}

// Driver function
int main(){
    // vector<int> nums({1, 2, 3, 1});
    // int k = 3;
    // vector<int> nums({1, 0, 1, 1});
    // int k = 1;
    vector<int> nums({1, 2, 3, 1, 2, 3});
    int k = 2;
    // vector<int> nums({1});
    // int k = 1;
    // vector<int> nums({-1, -1});
    // int k = 1;
    // vector<int> nums({1,2,3,4,5,6,7,8,9,10});
    // int k = 15;


    cout << containsNearbyDuplicate(nums, k) << endl;

    return 0;
}
/*
[1,2,3,4,5,6,7,8,9,10]
15
*/
