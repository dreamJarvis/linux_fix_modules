// To print all the
// C++ Program of above approach
#include <bits/stdc++.h>
using namespace std;

void printAllSets(vector<int> &arr){
    int n = arr.size();

    int totalPossibleWays = pow(2, n);

    for(int i = 0; i < totalPossibleWays; i++){
        for(int j= 0; j < n; j++){
            if(i & (1 << j))
                cout << arr[j] << ", ";
        }
        cout << endl;
    }
}

// Driver function
int main(){
    vector<int> arr({1, 2, 3});

    printAllSets(arr);

    return 0;
}
