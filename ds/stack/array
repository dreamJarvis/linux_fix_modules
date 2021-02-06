#include <bits/stdc++.h>
using namespace std;

// // brute force : TLE
// // tc : O(n^2)
// int maxArea(vector<int>& arr){
//     int n = arr.size();
//     int maxWaterContained = 0;
//
//     for(int i = 0; i < n; i++){
//         for(int j = i+1; j < n; j++){
//             int area = min(arr[i], arr[j])*(j-i);
//             maxWaterContained = max(maxWaterContained, area);
//         }
//     }
//
//     return maxWaterContained;
// }

// tc : O(n)
int maxArea(vector<int>& arr){
    int n = arr.size();
    int l = 0;
    int r = n-1;

    int maxWater = INT_MIN;
    while(l < r){
        int area = min(arr[l], arr[r])*(r-l);
        maxWater = max(maxWater, area);

        if(arr[l] < arr[r])
            l++;
        else if(arr[l] >= arr[r])
            r--;
    }

    return maxWater;
}

// Driver function
int main(){
    // vector<int> arr({1,8,6,2,5,4,8,3,7});
    // vector<int> arr({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    // vector<int> arr({2,3,4,5,18,17,6});
    vector<int> arr({9,6,14,11,2,2,4,9,3,8});


    cout << maxArea(arr) << endl;

    return 0;
}
/*
[2,3,4,5,18,17,6], 17
[9,6,14,11,2,2,4,9,3,8], 72
*/
