// To search an element in an circular sorted array
#include <bits/stdc++.h>
using namespace std;

// applying binary search to find the element in the array
// time complexity : O(n*lon(n))
bool findElement(vector<int> &arr, int start, int end, int k){
    if(start == end)
        return false;

    int mid = start + (end - start)/2;

    if(k == arr[mid])
        return true;
    else if(k < arr[mid])
        return findElement(arr, start, mid, k);
    return findElement(arr, mid+1, end, k);
}

// utility function to divide the array's into 2 sub-arrays
bool findElementUTIL(vector<int> &arr, int k){
    int n = arr.size();

    // to find the pivot point
    int pivot = 0;
    for(int i=0; i<n-1; i++)
        if(arr[i] > arr[i+1])
            pivot = i;

    return (findElement(arr, 0, pivot, k) || findElement(arr, pivot+1, n, k));
}

// Driver function
int main(){
    vector<int> arr({3,4,5,1,2});
    int k = 2;

    cout << findElementUTIL(arr, k) << endl;

    return 0;
}
