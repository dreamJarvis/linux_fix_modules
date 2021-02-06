// Given an array arr[], find a Noble integer in it. An integer x is said to be Noble in arr[] if the number of integers greater than x are equal to x. If there are many Noble integers, return any of them. If there is no, then return -1.
#include <bits/stdc++.h>
using namespace std;

int nobleInteger(vector<int> &arr) {
    sort(arr.begin(), arr.end());

    for(int i = 0; i < arr.size(); i++){
        // for duplicates
        if(arr[i] == arr[i+1])
            continue;
        if(arr[i] == n-i-1)
            return arr[i];
    }
    if(arr[n-1] == 0)
        return arr[n-1];

    return -1;
}

// Driver function
int main(){
    vector<int> arr({2,1,4,5,6,3});

    cout << nobleInteger(arr) << endl;

    return 0;
}
