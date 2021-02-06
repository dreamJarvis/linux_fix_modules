/*
    Can Make Arithmetic Progression From Sequence
*/
#include <bits/stdc++.h>
using namespace std;

bool canMakeArithmeticProgression(vector<int>& arr) {
    sort(arr.begin(), arr.end());

    int diff = arr[1] - arr[0];

    for(int i = 1; i < arr.size(); i++){
        if(arr[i]-arr[i-1] != diff)
            return false;
    }

    return true;
}

// Driver function
int main(){
    // vector<int> arr({3, 5, 1});
    // vector<int> arr({1, 2, 4});
    // vector<int> arr({13,12,-12,9,9,16,7,-10,-20,0,18,-1,-20,-10,-8,15,15,16,2,15});
    // vector<int> arr({1,10,10,10,19});
    vector<int> arr({0, 0, 0, 0});

    cout << canMakeArithmeticProgression(arr) << endl;

    return 0;
}
/*
[13,12,-12,9,9,16,7,-10,-20,0,18,-1,-20,-10,-8,15,15,16,2,15]
[1,10,10,10,19]
*/
