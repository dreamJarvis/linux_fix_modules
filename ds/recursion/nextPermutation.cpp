/*
    31. Next Permutation
    https://leetcode.com/problems/next-permutation/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // O(n^2) Solution
    /* we have 2 loops here,
    1st loop will go away from the end, 0 <-- (n-2)
    i.e. i will iterate from 0 <--- (n-2),( where i >= 0 & i < n)
    and in the 2'nd loop we iterate toward end, i.e.
    j will iterate from i --> (n-1)

    why are we doing this ?
    because we just the next greater permutation, i.e. the next greater number
    and here i have assumed the decimal position of the number of (n-i)
    i.e. if a number is having index i, then its decimal position will be (n-i)
    ex :        1, 2, 3
    index:      0, 1, 2
    decimal:    2, 1, 0

    so we want just greater element, now what we ill do is,we will take every
    i'th element going from (n-2) --> 0, and find a just greater number,
    ans we will swap it, with the current i'th number,
    now we want just greater number,
    so now we will sort all the numbers after i'th index

    as in the above ex:
    ex :        1, 3, 2
    index:      0, 1, 2
    decimal:    2, 1, 0

    we wil swap 1, with 2, with 1 at index, 0
    num :       2, 3, 1
    now we sort all the number after i'th index, i.e. after 0, we get
    num :       2, 1, 3
    */
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        /*
        first we check if our given instance is the final permutation
        we can have for the given numbers
        */
        bool flag = true;
        for(int i = n-2; i >= 0; i--)
            if(nums[i] < nums[i+1])
                flag = false;

        /*if we already have the max permutation,
        then we return the min permutation
        */
        if(flag){
            reverse(nums.begin(), nums.end());
        }
        else{
            int index = -1;
            for(int i = n-2; i >= 0; i--){
                // find just greater element
                for(int j = i+1; j < n; j++){
                    if(nums[j] > nums[i]){
                        index = j;
                    }
                }

                // if found , then swap and sort and return
                if(index > 0){
                    swap(nums[i], nums[index]);
                    reverse(nums.begin()+i+1, nums.end());
                    return ;
                }
            }
        }
    }

    // O(n) Solution
    void nextPermutationII(vector<int>& nums) {
        int n = nums.size();

        int index = -1;
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }

        if(index != -1){
            int temp = nums[index];
            int i=0;
            for(i = n-1; i > index; i--)
                if(nums[i] > temp)
                    break;

            swap(nums[i], nums[index]);
            reverse(nums.begin()+index+1, nums.end());
        }
        else
            reverse(nums.begin(), nums.end());

        return ;
    }
};

// Driver function
int main(){
    // vector<int> arr({1, 2, 3});
    // vector<int> arr({3, 2, 1});
    // vector<int> arr({1, 1, 5});
    vector<int> arr({1, 3, 2});
    // vector<int> arr({1, 2});
    // vector<int> arr({4, 2, 0, 2, 3, 2, 0});
    // vector<int> arr({2,2,7,5,4,3,2,2,1});
    // vector<int> arr({2,2,0,4,3,1});
    // vector<int> arr({0,0,4,2,1,0});
    // vector<int> arr({2,2,0,4,3,1});

    Solution s;

    s.nextPermutation(arr);

    for(auto i:arr)
        cout << i << " ";
    cout << endl;

    return 0;
}
/*
[2,2,7,5,4,3,2,2,1]
[2,2,0,4,3,1]
[0,0,4,2,1,0]
[2,2,0,4,3,1]
*/
