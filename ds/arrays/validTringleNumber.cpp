// 611. Valid Triangle Number
/*
    Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
*/
#include <bits/stdc++.h>
using namespace std;

// TLE
// time complexity : O(n^3)
// space complexity : O(1)
int validTriangleNumber(vector<int> &arr){
    sort(arr.begin(), arr.end());

    if(arr.size() < 3) return 0;

    int n = arr.size();

    int count = 0;
    for(int i = 0; i < n-2; i++){
        for(int j = i+1; j < n-1; j++){
            for(int k = j+1; k < n; k++){
                if( (arr[i] + arr[j] > arr[k]) &&
                    (arr[i] && arr[j] && arr[k]) ) {
                    count++;
                    cout << arr[i] <<", " << arr[j] <<", " << arr[k] << endl;
                }
            }
        }
    }

    return count;
}

// time complexity : O(n^2)
// space complexity : O(1)
int validTriangleNumberEditorial(vector<int> &arr){
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int count = 0;

    // i -> 1st side of the triangle
    // j -> 2nd side of the triangle
    // k -> all the sides who are less the sum of arr[i] + arr[j]
    for(int i = 0; i < n - 2; ++i){
        // kyuki i, i+1, toh pehle 2 elements h he, k ki value i+1 ke badh se shru hogi, joki h i+2
        int k = i + 2;
        for(int j = i+1; j < n; ++j){

            // kyuki array sorted h, toh k'th index hme wo rightmost value lake dega, jaha tk i'th & j'th elements ka sum > k'th element se
            while(k < n && arr[i] + arr[j] > arr[k])
                k++;

            // k - 1, cause k is incremented 1 extra time in the above loop
            if(k > j)
                count += (k - j - 1);
        }
    }

    return count;
}

// 2 pointer approach
// time complexity : O(n^2)
// space complexity : O(1)
int validTriangleNumberSolution(vector<int> &arr){
    if(arr.empty()) return 0;

    int n = arr.size();
    sort(arr.begin(), arr.end());

    int count = 0;

    for(int i = n-1; i >= 2; i--){
        int l = 0, r = i - 1;
        while(l < r){
            // checking the conditions of the triangle
            // now if the arr[l] + arr[r] > arr[i], then logically it is sure enouggh that arr[l+1].....+ arr[r-1] > arr[i].. and so on
            if(arr[l] + arr[r] > arr[i]){
                count += r - l;
                r--;
            }
            else    l++;
        }
    }

    return count;
}

// Driver function
int main(){
    // vector<int> arr({1,1,1,1});
    // vector<int> arr({2,2,3,4});
    vector<int> arr({24,3,82,22,35,84,19});

    // cout << validTriangleNumber(arr) << endl;

    // validTriangleNumber_2(arr);

    // cout << validTriangleNumberEditorial(arr) << endl;
    cout << validTriangleNumberSolution(arr) << endl;

    return 0;
}
// [24,3,82,22,35,84,19]
// 2,2,3,4
// [0,1,1,1]
