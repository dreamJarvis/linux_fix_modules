// Array Rotation : Reversal Algo
#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr, int si, int ei){
    while(si < ei){
        swap(arr[si], arr[ei]);
        si++;
        ei--;
    }
}

void leftRotate(vector<int> &arr, int d){
    if(d == 0)
        return ;

    int n = arr.size();
    reverseArray(arr, 0, d - 1);
    reverseArray(arr, d, n-1);
    reverseArray(arr, 0, n-1);
}

void printArray(vector<int> &arr){
    for(auto value : arr)
        cout << value << " ";
    cout << endl;
}

// Driver function
int main(){
    vector<int> arr({1, 2, 3, 4, 5, 6, 7});
    int d = 2;

    d = d%(arr.size());

    leftRotate(arr, d);
    printArray(arr);

    return 0;
}