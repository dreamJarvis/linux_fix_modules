// leetcode 137. Single Number II
#include <bits/stdc++.h>
using namespace std;

// solution 1
// time complexity : 2O(n)
// space complexity : O(m)
int singleNumber(vector<int> &nums) {
    int n = nums.size();
    unordered_map<int, int> visited;

    for(auto item:nums)
        if(visited.count(item))
            visited[item]++;
        else
            visited[item] = 1;

    for(auto item:visited){
        if(item.second == 1)
            return item.first;
    }

    return -1;
}

// solution 2
// time complexity : O(n)
// space complexity : O(1);
// youtube link : https://www.youtube.com/watch?v=XPFp9Ct_-ek
int singleNumberII(vector<int> &nums){
    int res = 0;
    int sum;
    for(int i=0;i<32;i++){
        int x = 1<<i;
        sum = 0;
        for(int j=0;j<nums.size();j++){
            if(x&nums[j])
                sum++;
        }
        if(sum%3)
            res |= x;
    }
    return res;
}

// solution 3
int singleNumberIII(vector<int> &nums){
    int a = 0, b = 0;
    for(int num:nums){
        b = ~a & (b ^ num);
        a = ~b & (a ^ num);
    }

    return b;
}

// Driver function
int main(){
    // vector<int> nums({2, 2, 3, 2});
    vector<int> nums({0, 1, 0, 1, 0, 1, 99});

    cout << singleNumberIII(nums) << endl;

    return 0;
}
// 0,1,0,1,0,1,99
