/*
    60. Permutation Sequence
    https://leetcode.com/problems/permutation-sequence/
*/
#include <bits/stdc++.h>
using namespace std;


// O(n) solutions
class Solution {
public:
    void helper(vector<int> &nums, int n, int k, string &result){
        if(k == 0)  return;

        int permute = 1;
        for(int i = 1; i < n; i++)
            permute *= i;

        int pos = k/permute;
        k = k%permute;

        result += to_string(nums[pos]);
        nums.erase(nums.begin()+pos);

        helper(nums, n-=1, k, result);
    }

    string getPermutation(int n, int k) {
        string result ="";
        vector<int> nums(n);

        for(int i = 1; i <= n; i++)
            nums[i-1] = i;

        k--;
        helper(nums, n, k, result);

        for(auto &i:nums)
            result += to_string(i);

        return result;
    }

    // iterative
    string getPermutationIterative(int n, int k) {
        string result ="";
        vector<int> nums(n);

        for(int i = 1; i <= n; i++)
            nums[i-1] = i;

        k--;
        while(k){
            int permute = 1;
            for(int i = 1; i < n; i++)
                permute *= i;

            int pos = k/permute;
            k = k%permute;

            result += to_string(nums[pos]);
            nums.erase(nums.begin()+pos);
            n -= 1;
        }

        for(auto &i:nums)
            result += to_string(i);

        return result;
    }
};

// Driver function
int main(){
    // int n = 3, k = 3;
    // int n = 4, k = 9;
    // int n = 3, k = 5;
    // int n = 2, k = 2;
    // int n = 1, k = 1;
    int n = 9, k = 206490;

    Solution s;
    cout << s.getPermutationRecursive(n, k) << endl;

    return 0;
}
