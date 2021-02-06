// next greater element
#include <bits/stdc++.h>
using namespace std;

// tutorial : https://www.youtube.com/watch?v=HmBbcDiJapY&t=308s
// ṭime complexity : O(n^2)
// space complexity : O(1)
int Trap(vector<int>& arr){
    int n = arr.size();
    int sum = 0;

    for(int i = 0; i < n; i++){
        // find the left max
        int leftMax = -1;
        for(int j = 0; j <= i; j++)
            leftMax = max(leftMax, arr[j]);

        // find the right max
        int rightMax = -1;
        for(int j = i; j < n; j++)
            rightMax = max(rightMax, arr[j]);

        // adding the amount of water
        sum += (min(leftMax, rightMax) - arr[i]);
    }

    return sum;
}

// tutorial : https://www.youtube.com/watch?v=VZpJxINSvfs
// time complexity : O(n)
// space complexity : O(n)
int TrapII(vector<int>& arr){
    int n = arr.size();
    int sum = 0;

    vector<int> left(n, -1);
    vector<int> right(n, -1);

    int leftMax = arr[0];
    for(int i = 0; i < n; i++){
        leftMax = max(leftMax, arr[i]);
        left[i] = leftMax;
    }

    int rightMax = arr[n-1];
    for(int i= n-1; i >=0; i--){
        rightMax = max(rightMax, arr[i]);
        right[i] = rightMax;
    }

    for(int i = 0; i < n; i++)
        sum += (min(left[i], right[i]) - arr[i]);

    return sum;
}


// time complexity : O(n)
// space complexity : O(1)
// tutorial : https://www.youtube.com/watch?v=XqTBrQYYUcc

// lower envolope technique : (either uses 2 pointer/ binary search approach)
// left max :-> non-decreasing funtion
// right max :-> non-increasing funtion
int TrapIII(vector<int>& arr){
    int n = arr.size();
    if(n < 3)   return 0;

    int sum = 0;
    int i = 0, j = n-1;
    int leftMax = -1, rightMax = -1;
    while(i <= j){
        leftMax = max(leftMax, arr[i]);
        rightMax = max(rightMax, arr[j]);

        if(leftMax <= rightMax){
            sum += leftMax - arr[i];
            i++;
        }
        else if(rightMax <= leftMax){
            sum += rightMax - arr[j];
            j--;
        }
    }

    return sum;
}

// Driver function
// 0,1,0,2,1,0,1,3,2,1,2,1
// [0,7,1,4,6]
// [9,6,8,8,5,6,3]
int main(){
    vector<int> arr({3, 2, 5, 1, 4, 6, 10, 4, 2, 5});
    // vector<int> arr({0,1,0,2,1,0,1,3,2,1,2,1});
    // vector<int> arr({5, 4, 1, 2});
    // vector<int> arr({1, 7, 5});
    // vector<int> arr({0, 7, 1, 4, 6});
    // vector<int> arr({9, 6, 8, 8, 5, 6, 3});


    cout << TrapIII(arr) << endl;

    return 0;
}
