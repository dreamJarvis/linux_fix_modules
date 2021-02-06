#include <bits/stdc++.h>
using namespace std;

long maximumSum(vector<long> a, long m) {
    long currentSum = 0;
    long maximumSum = 0;
    // long moduloSum = 0;

    for(int i = 0; i < a.size(); i++){
        currentSum = max(a[i], currentSum + a[i]);
        // cout << currentSum%m << endl;
        maximumSum = max(maximumSum, currentSum);
        // moduloSum = max(moduloSum, maximumSum%m);
        // cout << maximumSum << endl;
    }

    return moduloSum;
}

// Driver function
int main(){
    // vector<long> arr({3, 3, 9, 9, 5});
    // long m = 7;
    // vector<long> arr({1, 2, 3});
    // long m = 2;
    vector<long> arr({1, 5, 9});
    long m = 5;

    cout << maximumSum(arr, m) << endl;

    return 0;
}
