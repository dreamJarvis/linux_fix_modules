// leetcode : 287
/*
    Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
*/
#include <bits/stdc++.h>
using namespace std;

// by applying : floyds tortoise and hare algorithm (floyd cycle-finding algorithm)
// vedio : https://www.youtube.com/watch?v=-YiQZi3mLq0&t=369s
int findDuplicateElement(vector<int> &arr){
    int n = arr.size();

    int slow_ptr = arr[0];
    int fast_ptr = arr[0];

    // here we use slow and fast ptr to fing the loop
    slow_ptr = arr[slow_ptr];
    fast_ptr = arr[arr[fast_ptr]];

    while(slow_ptr != fast_ptr){
        slow_ptr = arr[slow_ptr];
        fast_ptr = arr[arr[fast_ptr]];
    }

    // now the difference between the length of the path from the starting of the array, to the point where the loop has been found , when traversed equally by keeping one ptr at the starting point of the array, and one where the loop has been detected, they meet at the starting of the loop
    //** proof can be found :  https://www.youtube.com/watch?v=-YiQZi3mLq0&t=369s
    int a_ptr = arr[0];
    int b_ptr = slow_ptr;

    while(a_ptr != b_ptr){
        a_ptr = arr[a_ptr];
        b_ptr = arr[b_ptr];
    }

    return a_ptr;
}

// driver function
int main(){
    vector<int> arr({1, 3, 4, 2, 2});
    cout << findDuplicateElement(arr) << endl;
    return 0;
}
