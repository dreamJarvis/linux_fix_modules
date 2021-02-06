/*
    2. Majority Element
    https://practice.geeksforgeeks.org/problems/majority-element-1587115620/0/?track=amazon-searching&batchId=192#

    moore's voting algorithm :
        https://www.youtube.com/watch?v=n5QY3x_GNDg
        https://www.geeksforgeeks.org/majority-element/
*/
#include <bits/stdc++.h>
using namespace std;

// moore's voting algorithm
// tc : O(n)
// sc : O(1)
int majorityElement(int arr[], int n){
    int majElement = arr[0], count = 1;
    for(int i = 1; i < n; i++){
        if(majElement != arr[i]){
            count--;
        }
        else
            count++;

        if(!count){
            count = 1;
            majElement = arr[i];
        }
    }

    count = 0;
    for(int i = 0; i < n; i++)
        if(arr[i] == majElement)
            count++;

    if(count > n/2)
        return majElement;
    return -1;
}

// Driver function
int main(){
    // int arr[] = {1,2,3};
    int arr[] = {3,1,3,3,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << majorityElement(arr, n) << endl;

    return 0;
}
