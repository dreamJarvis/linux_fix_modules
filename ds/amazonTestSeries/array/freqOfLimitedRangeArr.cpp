/*
    25. Frequencies of Limited Range Array Elements
    https://practice.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/0/?track=amazon-arrays&batchId=192#
*/
#include <bits/stdc++.h>
using namespace std;

// tc : O(n)
// sc : O(1)
void frequencycount(vector<int>& arr,int n){
    for(int i = 0; i < n; i++)
        arr[i] -= 1;

    for(int i = 0; i < n; i++)
        arr[arr[i]%n] = arr[arr[i]%n]+n;

    for(int i = 0; i < n; i++)
        arr[i] /= n;
}

// tc : O(n)
// sc : O(1)
// void frequencycount(vector<int>& arr,int n){
//     for(int i = 0; i < n; i++)
//         arr[i] -= 1;
//
//
//     for(int i = 0; i < n; i++){
//         if(arr[i] == i){
//             continue;
//         }
//
//         while(arr[i] != arr[arr[i]]){
//             swap(arr[i], arr[arr[i]]);
//         }
//     }
//
//     for(int i = 0; i < n; i++){
//         if(arr[i] == i)
//             arr[i] = n;
//     }
//
//     for(int i = 0; i < n; i++){
//         if(arr[i] < n){
//             arr[arr[i]] = (arr[arr[i]]/n)*n + n;
//         }
//     }
//
//     for(int i = 0; i < n; i++){
//         arr[i] /= n;
//     }
// }

// Driver function
int main(){
    int arr[] = {2, 3, 2, 3, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    frequencycount(arr, n);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
