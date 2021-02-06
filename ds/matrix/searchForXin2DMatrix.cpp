// To search for an element x in an row sorted 2d matrix
#include <bits/stdc++.h>
using namespace std;

// O(log(n))
bool binarySearch(vector<int> &arr, int start, int end, int k){
    if(start > end){
        return false;
    }

    int mid = start + (end - start)/2;

    if(arr[mid] == k)
        return true;
    else if(arr[mid] > k)
        return binarySearch(arr, start, mid - 1, k);
    return binarySearch(arr, mid+1, end, k);
}

// O(nlog(n))
bool searchUTIL(vector<vector<int>> &arr, int k){
    int row = arr.size();
    int col = arr[0].size();

    for(int i = 0; i < row; i++)
        if(binarySearch(arr[i], 0, col-1 ,k))
            return true;
    return false;
}

// Driver function
int main(){
    vector<vector<int>> arr{
                    {1, 3, 5},
                    {2, 6, 9},
                    {3, 6, 9}
                };
    int k = 37;
    cout << searchUTIL(arr, k) << endl;

    return 0;
}
