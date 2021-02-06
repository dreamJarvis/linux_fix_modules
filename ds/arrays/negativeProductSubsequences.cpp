// Given an array arr[] of N integers, the task is to find the count of all the subsequences of the array that have a negative products.
#include <bits/stdc++.>
using namespace std;

// count of all the subsequences with negative product
int countNegativeProductSubsequences(vector<int> &arr, int n){
    int pos_count = 0;      // count of all the +ve elements in the array
    int neg_count = 0;      // count of all he -ve elements in the array

    int result;

    for(int i = 0; i < n; i++){
        if(arr[i] > 0)  pos_count++;    // current element is +ve
        if(arr[i] < 0)  neg_count++;    // current element is -ve
    }

    // all the subsequences that all the +ve element will make
    result = pow(2, pos_count);

    // all the subsequences that all -ve will make
    if(neg_count > 0)   result *= pow(2, neg_count-1);
    else                result = 0;

    return result;
}

// Driver function
int main(){
    vector<int> arr({3, -4, -1, 6});

    cout << countNegativeProductSubsequences(arr, arr.size()) << endl;

    return 0;
}
