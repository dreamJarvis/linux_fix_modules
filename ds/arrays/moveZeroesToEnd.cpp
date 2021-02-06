/*  Leetcode : 
    Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

    *** constraints :   1) You must do this in-place without making a copy of the array.
                        2) Minimize the total number of operations.
*/
#include <bits/stdc++.h>
using namespace std;

// move zeroes to end
void moveZeroesToEnd(vector<int> &nums){
    int n = nums.size();

    int index = 0;
    for(auto value:nums){
        if(value != 0){
            nums[index++] = value;
        }
    }

    for(int i = index; i < n; i++)
        nums[i] = 0;

    for(auto value:nums)
        cout << value << " ";
    cout << endl;
}

// Driver function
int main(){
    vector<int> arr({0, 1, 0, 3, 12});
    moveZeroesToEnd(arr);
    return 0;
}
