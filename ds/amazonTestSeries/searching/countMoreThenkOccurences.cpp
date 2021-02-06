/*
    10. Count More than n/k Occurences
    https://practice.geeksforgeeks.org/problems/count-element-occurences/0/?track=amazon-searching&batchId=192
*/
#include <bits/stdc++.h>
using namespace std;

int countOccurence(int arr[], int n, int k) {
    k = n/k;

    unordered_map<int, int> freq;
    for(int i = 0; i < n; i++)
        freq[arr[i]]++;

    int count = 0;
    for(auto &i:freq)
        if(i.second > k)
            count++;

    return count;
}

// Driver function
int main(){
    // int arr[] = {3,1,2,2,1,2,3,3};
    // int k = 4;

    int arr[] = {2,3,3,2};
    int k = 3;

    int n = sizeof(arr)/sizeof(arr[0]);

    cout << countOccurence(arr, n, k) << endl;

    return 0;
}
