/*
    28. Binary Array Sorting
    https://practice.geeksforgeeks.org/problems/binary-array-sorting5355/0/?track=amazon-arrays&batchId=192
*/
#include <bits/stdc++.h>
using namespace std;

// one pass solution
vector<int> SortBinaryArray(vector<int> &arr){
    int n = arr.size();

    int s = 0, e = n-1;
    while(s < e){
        if(arr[s] == 1 && arr[e] == 0){
            swap(arr[s], arr[e]);
            s++;
            e--;
        }
        if(arr[s] == 0)
            s++;
        if(arr[e] == 1)
            e--;
    }

    return arr;
}

// Driver function
int main(){
    // vector<int> arr({1,0,1,1,0});
    // vector<int> arr({1,0,1,1,1,1,1,0,0,0});
    vector<int> arr({0, 1, 0, 1, 1, 0, 0});

    for(auto &i:SortBinaryArray(arr))
        cout << i << " ";
    cout << endl;

    return 0;
}
