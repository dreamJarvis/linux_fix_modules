// Find the two repeating elements in a given array
// You are given an array of n+2 elements. All elements of the array are in range 1 to n. And all elements occur once except two numbers which occur twice. Find the two repeating numbers.
#include <bits/stdc++.h>
using namespace std;

// find the repeating element in the array
// using XOR
int repeatingElementInArray(vector<int> &arr){
    int n = arr.size();
    int x1 = arr[0];
    int x2 = 1;

    for(int i = 1; i < n; i++) x1 ^= arr[i];
    for(int i = 2; i < n; i++)  x2 ^= i;

    return (x1^x2);
}

// Driver function
int main(){
    vector<int> arr({1, 8, 3, 4, 2, 5, 6, 8, 7});
    cout << repeatingElementInArray(arr) << endl;

    return 0;
}
