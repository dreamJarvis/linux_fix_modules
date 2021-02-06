/*
    27. Intersection of two arrays
    https://practice.geeksforgeeks.org/problems/intersection-of-two-arrays2404/0/?track=amazon-arrays&batchId=192#
*/
#include <bits/stdc++.h>
using namespace std;

int NumberofElementsInIntersection (int a[], int b[], int n, int m ){
    unordered_map<int, bool> freq;
    for(int i = 0; i < n; i++)
        freq[a[i]] = true;

    int count = 0;
    for(int i = 0; i < m; i++){
        if(freq[b[i]]){
            freq[b[i]] = false;
            count++;
        }
    }

    return count;
}

// Driver function
int main(){
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3};

    // int arr1[] = {2, 2, 3, 4, 5};
    // int arr2[] = {1, 1, 2, 3, 4};

    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);

    cout << NumberofElementsInIntersection(arr1, arr2, n, m) << endl;
    return 0;
}
