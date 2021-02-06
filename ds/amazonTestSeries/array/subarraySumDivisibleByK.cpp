/*
    leetcode : 974. Subarray Sums Divisible by K
    https://leetcode.com/problems/subarray-sums-divisible-by-k/

    referene : https://www.youtube.com/watch?v=ufXxc8Vty9A
*/
#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int>& A, int k) {
    int n = A.size();

    unordered_map<int, int> freq;
    freq[0] = 1;
    int sum = 0, count = 0;
    for(int i = 0; i < n; i++){
        sum += A[i];
        int rem = sum%k;
        if(rem < 0) rem +=k;

        if(freq.count(rem))
            count += freq[rem];

        freq[rem]++;
    }

    return count;
}

// Driver function
int main(){
    vector<int> arr({4,5,0,-2,-3,1});
    int K = 5;

    // vector<int> arr({-1, 2, 9});
    // int K = 2;

    // vector<int> arr({1,-10,5});
    // int K = 9;

    cout << subarraysDivByK(arr, K) << endl;

    return 0;
}
/*
[1,-10,5]
9
*/
