// Given an array of integers, sort the array into a wave like array and return it,
// In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....
#include <bits/stdc++.h>
using namespace std;

vector<int> waveArray(vector<int> &arr){
    int n = arr.size();

    sort(arr.begin(), arr.end());

    // int div = n/2;
    int rem = n%2;

    for(int i = 0; i < n; i+=2){
        if(i+1 <= n-rem)
            swap(arr[i], arr[i+1]);
    }

    return arr;
}

// Driver function
int main(){
    vector<int> arr({1, 2, 3, 4, 5});

    for(auto value:waveArray(arr))
        cout << value << " ";
    cout << endl;

    return 0;
}
