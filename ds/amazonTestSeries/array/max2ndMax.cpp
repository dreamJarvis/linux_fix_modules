/*
    https://practice.geeksforgeeks.org/problems/max-and-second-max/0/?track=amazon-arrays&batchId=192#
*/
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> twoMaxes(int arr[], int N){
    int a = INT_MIN, b = INT_MIN;

    for(int i = 0; i < N; i++){
        if(a < arr[i]){
            b = a;
            a = arr[i];
        }
        else if(b < arr[i] && arr[i] != a){
            b = arr[i];
        }
    }

    if(b == INT_MIN)
        return vector<int>({a, -1});
    return vector<int>({a, b});
}

// Driver function
int main(){
    int arr[] = {2, 1, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(auto &i:twoMaxes(arr, n)){
        cout << i << " ";
    }

    return 0;
}
