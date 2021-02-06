// To find the lower bound of an element in an array of repeated elements
#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &arr,int start, int end, int k){
    // base cases:
    if(arr.size() == 0){
        cout << "Empty array" << endl;
        return -1;
    }

    if(start == end){
        if(arr[start] == k)
            return start;
    }

    if(start > end)
        return -1;

    // recursive cases : 
    int mid = start + (end - start)/2;
    int lb = 0;

    if(arr[mid] == k){
        if(arr[mid-1] == arr[mid]){
            return lowerBound(arr, start, mid-1, k);
        }
        return mid;
    }
    else if(arr[mid] > k)
        return lowerBound(arr, start, mid-1, k);
    return lowerBound(arr, mid+1, end, k);
}

// Driver function
int main(){
    vector<int> arr({1, 1, 1, 3, 3, 3, 4, 5, 5, 6});

    int k = 5;
    // cin >> k;

    cout << lowerBound(arr, 0, arr.size(), k) << endl;

    return 0;
}