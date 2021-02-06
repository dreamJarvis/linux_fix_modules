// Given an array of n elements which contains elements from 0 to n-1, with any of these numbers appearing any number of times. Find these repeating numbers in O(n) and using only constant memory space
#include <bits/stdc++.h>
using namespace std;

void printRepeatingElements(int arr[], int size){
    int i;

    for(int i = 0; i < size; i++){
        if(arr[abs(arr[i])] >= 0)
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        else
            cout << abs(arr[i]) << " ";
    }
}

// Driver function
int main(){
    int arr[] = {1, 2, 3, 1, 3, 6, 6};
    int size = sizeof(arr)/sizeof(arr[0]);

    printRepeatingElements(arr, size);

    return 0;
}
