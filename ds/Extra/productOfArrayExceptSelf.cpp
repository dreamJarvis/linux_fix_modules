// leetcode 238.
// Product of Array Except Self
#include <bits/stdc++.h>
using namespace std;

// value at any i'th index is the prodcut of all its left * all its right values
// time complexity : O(n)
// space complexity : O(n)
vector<int> productExceptSelf(vector<int> &arr){
    int n = arr.size();

    int leftValue = 1;
    int rightValue = 1;
    vector<int> result(n, 1);

    for(int i = 0; i < n; i++){
        result[i] *= leftValue;
        leftValue  = leftValue * arr[i];
        result[n-1-i] *= rightValue;
        rightValue = rightValue * arr[n-1-i];
    }

    return result;
}

// Driver function
int main(){
    vector<int> arr({1, 2, 3, 4});

    for(auto item:productExceptSelf(arr))
        cout << item << " ";
    cout << endl;

    return 0;
}
