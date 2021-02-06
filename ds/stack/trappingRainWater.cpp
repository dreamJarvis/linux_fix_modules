// 42. Trapping Rain Water
#include <bits/stdc++.h>
using namespace std;

/*
    max water can only be contained in btw 2 bars of greater height ot its left and right
    as the water contained on top of it will be the difference btw the heights of the smaller of the 2 bars to its left and right and itself
*/
// tc : O(n)
// sc : 2*O(n)
void trap(vector<int>& arr) {
    int n = arr.size();

    // find the maximum bar height to it's left and right
    vector<int> rightMax(n, -1);
    vector<int> leftMax(n, -1);

    int rMax = INT_MIN;
    for(int i = 0; i < n; i++){
        rMax = max(rMax, arr[i]);
        rightMax[i] = rMax;
    }

    int lMax = INT_MIN;
    for(int i = n-1; i >= 0; i--){
        lMax = max(lMax, arr[i]);
        leftMax[i] = lMax;
    }

    // max water contained
    int maxWaterContained = 0;
    for(int i = 0; i < n; i++){
        maxWaterContained += (min(leftMax[i], rightMax[i]) - arr[i]);
    }

    return maxWaterContained;
}

// Driver function
int main(){
    // vector<int> arr({0,1,0,2,1,0,1,3,2,1,2,1});
    vector<int> arr({2, 0, 2});
    trap(arr);
    return 0;
}
/*
2, 0, 2, 2
*/
