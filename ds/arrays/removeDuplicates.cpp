// remove duplicates from an array in O(1) space
#include <bits/stdc++.h>
using namespace std;

// t : O(n)
// s : O(1)
int removeDuplicates(vector<int> &nums){
    if(nums.empty())   return 0;

    int n = nums.size()-1;

    int temp = nums[0], uniqueLength = 1;
    int prevIndex = 0, currIndex = 1;
    bool flag = false, endReached = false;

    // removing the duplicates
    while(currIndex <= n){
        while(nums[prevIndex] == nums[currIndex]){

            currIndex++;
            if(currIndex > n){
                endReached = true;
                break;
            }
        }

        if(endReached)  break;

        prevIndex++;
        nums[prevIndex] = nums[currIndex];
        uniqueLength++;
    }

    return uniqueLength;
}

// light-weight solution
// t : O(n)
// s : O(1)
int removeDuplicatesII(vector<int>& nums) {
    int n = nums.size();

    int j = 0;
    for(int i = 1; i < n; i++){
        if(nums[j] != nums[i]){
            nums[j+1] = nums[i];
            j++;
        }
    }

    return (j+1);
}

// Driver function
int main(){
    vector<int> arr({1});
    // vector<int> arr({1, 1});
    // vector<int> arr({1, 1, 2});
    // vector<int> arr({0,0,1,1,1,2,2,3,3,4});

    cout << "\n" << removeDuplicatesII(arr) << endl;

    return 0;
}
