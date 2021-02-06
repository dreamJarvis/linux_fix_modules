/*      Leetcode : 27
Given an array nums and a value val, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/
#include <bits/stdc++.h>
using namespace std;

// same technique as remove repeating element in an sorted array : arrays\removeDuplicates.cpp
// t : O(n)
// s : O(1)
int removeElement(vector<int> arr, int remElement){
    int index = 0;
    for(auto value:arr){
        if(value != remElement){
            arr[index] = value;
            index++;
        }
    }

    return index;
}

// driver function
int main(){
    vector<int> arr({0,1,2,2,3,0,4,2});

    cout << removeElement(arr, 2) << endl;

    return 0;
}
