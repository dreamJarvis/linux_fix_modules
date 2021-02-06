/*
    7. Remove duplicates in small prime array
    https://practice.geeksforgeeks.org/problems/remove-duplicates-in-small-prime-array/0/?track=amazon-arrays&batchId=192#
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// tc : O(n)
// sc : O(1)
// only works for product upto 10^18
vector<int> removeDuplicate(vector<int>& arr, int n){
    long long int prod = arr[0];
    int resId = 1;

    for(int i = 1; i < n; i++){
        if(prod%arr[i] != 0){
            arr[resId++] = arr[i];
            prod *= arr[i];
        }
    }

    arr.erase(arr.begin()+resId, arr.end());
    return arr;
}

// Driver function
int main(){
    vector<int> arr({2,2,3,3,7,5});

    for(auto &i:removeDuplicate(arr, arr.size()))
        cout << i << " ";
    cout << endl;

    return 0;
}
