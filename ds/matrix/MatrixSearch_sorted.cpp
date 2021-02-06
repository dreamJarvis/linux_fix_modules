// to search for an elment in an sorted array(row-wise, col-wise)
#include <bits/stdc++.h>
using namespace std;

// O(n+m)
bool searchElement_1(vector<vector<int>> &arr, int target){
    // handle edge-case, empty array
    if (empty(arr)) return false;

    // start from top right corner
    int row = 0;
    int col = arr[0].size() - 1;

    while(row < arr.size() && col >= 0) {
        // if target is found in current position, return true
        if (target == arr[row][col]) {
            return true;
        }
        // if target is smaller than current position, go left
        // if target is larger than current position, go down
        target < arr[row][col] ? --col : ++row;
    }

    return false;
}

// O(n)
bool searchElement_2(vector<vector<int>> &arr, int target){
    int totalRows = arr.size();
    if(!totalRows)  return false;

    int totalCols = arr[0].size();

    int start = 0, end = totalRows * totalCols - 1, mid;

    while(start <= end){
        mid = start + (end - start)/2;

        int middleElementValue = arr[mid/totalCols][mid%totalCols];

        if(middleElementValue == target)        return true;
        else if(middleElementValue > target)    end = mid - 1;
        else                                    start = mid + 1;
    }

    return false;
}

// Driver function
int main(){
    vector<vector<int>> arr{{1, 2, 3, 4},
                            {5, 6, 7, 8},
                            {9, 10, 11, 12},
                            {13, 14, 15, 16}
                        };
    // vector<vector<int>> arr;
    int row = arr.size();
    int col = arr[0].size();

    int k = 10;
    cout << searchElement_2(arr, k) << endl;

    return 0;
}
