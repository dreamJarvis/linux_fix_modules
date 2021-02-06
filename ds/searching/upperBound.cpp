// To find the upper bound of an element in an array of repeated elements
#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int start, int end, int k){
    // base cases :
    if(arr.size() == 0){
        return -1;
    }

    if(start == end){
        if(arr[start] == k)
            return start;
    }

    if(start > end){
        return -1;
    }

    // recursive condition:
    int mid = start + (end - start)/2;          //  to avoid overflow

    if(arr[mid] == k){
        if(arr[mid+1] == arr[mid])
            return upperBound(arr, mid+1, end, k);
        return mid;
    }

    if(arr[mid] > k)
        return upperBound(arr, start, mid-1, k);
    return upperBound(arr, mid+1, end, k);
}

// Driver function
int main(){
    vector<int> arr({1, 1, 1, 3, 3, 3, 4, 5, 5, 6});

    int k = 3;

    cout << upperBound(arr,0, arr.size(),k) << endl;
    return 0;
}