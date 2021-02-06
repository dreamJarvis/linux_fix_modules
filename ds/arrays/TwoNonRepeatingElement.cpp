// Find the two non-repeating elements in an array of repeating elements
#include <bits/stdc++.h>
using namespace std;

// finding the non-repeating values
// time complexity : O(n)
// space complexity : O(1)
void get2NonRepeatingElements(vector<int> &arr){
    int n = arr.size();

    //  xor of all the elements in the array
    int Xor = arr[0];
    for(int i = 1; i < n; i++)  Xor ^= arr[i];

    // ~(Xor-1) --> 2's complement of Xor
    // Take two's complement of the given no as all bits are reverted except the first '1' from right to left
    // and Xor & (Xor 2's complement) == rightmost set bit
    //** gfg link for finding rightmost set bit : https://www.geeksforgeeks.org/position-of-rightmost-set-bit/
    int setRightBit = Xor & ~(Xor-1);

    // dividing the array into 2 halves,
    // 1)   all the elements whose set bit matches with out setRightBit
    // 2)   those whose doesn't
    int a = 0, b = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] & setRightBit)    a ^= arr[i];
        else                        b ^= arr[i];
    }

    cout << a <<" " << b << endl;
}

// Driver function
int main(){
    vector<int> arr({2, 3, 7, 9, 11, 2, 3, 11});
    get2NonRepeatingElements(arr);
    return 0;
}
