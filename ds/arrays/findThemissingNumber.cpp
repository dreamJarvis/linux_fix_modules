// Find the Missing Number
// You are given a list of n-1 integers and these integers are in the range of 1 to n. There are no duplicates in the list. One of the integers is missing in the list. Write an efficient code to find the missing integer.
#include <bits/stdc++.h>
using namespace std;

// method 1: sum all the elements
// 1. Get the sum of numbers which is total = n*(n+1)/2
// 2. Subtract all the numbers from sum and you will get the missing number
int getMissingNumber(vector<int> &arr){
    int n = arr.size();
    int total = 1;

    // sum of n numbers : because we have to sum numbers from 1 --> n, .'. the formula changes to (n+1)*(n+2)/n
    for(int i = 2; i <= (n+1); i++){
        total += i;
        total -= arr[i-2];
    }

    return total;
}

// method 2 : using XOR
// 1) XOR all the array elements, let the result of XOR be X1.
// 2) XOR all numbers from 1 to n, let XOR be X2.
// 3) XOR of X1 and X2 gives the missing number.
int getMissingNumberXOR(vector<int> &arr){
    // for xor of all the elements in the array
    int x1 = arr[0];

    // for xor of all the element upto n
    int x2 = 1;

    // XOR'ing all the numbers in the array
    for(int i=1; i < arr.size(); i++)   x1 ^= arr[i];

    // XOR'ing all the numbers from 1 --> n
    for(int i=2; i<= arr.size()+1; i++)   x2 ^= i;

    return (x1^x2);
}

// Driver function
int main(){
    vector<int> arr({1, 2, 3, 5});

    cout << getMissingNumber(arr) << endl;
    cout << getMissingNumberXOR(arr) << endl;

    return 0;
}
