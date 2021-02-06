#include <bits/stdc++.h>
using namespace std;

// tc : O(n)
// sc : O(m) , m : total no. of unique number in the array
void smallestSubarray(int arr[], int n){
    unordered_map<int ,int> leftMostIndex;    // stores the left-most index of an number
    unordered_map<int ,int> freqCounter;      // stores the freq. of an number

    int maxFreq = 0;                 // stores max. frequency
    int minLength, startingIndex;   //  stores sub-array length and startign index

    for(int i = 0; i < n; i++){
        int num = arr[i];

        // storing the index at their first most occurrence
        if(freqCounter[num] == 0){
            leftMostIndex[num] = i;        // storing the left-most index
            freqCounter[num] = 1;       // also initializing their count = 1
        }
        else
            freqCounter[num]++;         // else increment, if not occuring for the first time

        // finding maximum repeated element and storing it's first occurrence and their the length of the sub-array, to determine the last occurrence
        if(freqCounter[num] > maxFreq){
            maxFreq = freqCounter[num];
            minLength = i - leftMostIndex[num] + 1;     // length of the sub-array
            startingIndex = leftMostIndex[num];
        }
        else if(freqCounter[num] == maxFreq && i - leftMostIndex[num] + 1 < minLength){
            minLength = i - leftMostIndex[num] + 1;
            startingIndex = leftMostIndex[num];
        }
    }

    // the min-subarray containing all the count of max-frequency element
    for(int i = startingIndex; i < startingIndex+minLength; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver function
int main(){
    int A[] = { 1, 2, 2, 2, 1 };
    int n = sizeof(A) / sizeof(A[0]);
    smallestSubsegment(A, n);

    return 0;
}
