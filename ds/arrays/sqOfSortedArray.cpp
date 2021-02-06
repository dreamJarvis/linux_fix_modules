// Squares of a Sorted Array : O(n)
#include <bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int>& arr){
    vector<int> res(arr.size());

    int left = 0, right = arr.size()-1;

    for(int k = arr.size() - 1; k >= 0; k--){
        if(abs(arr[right]) > abs(arr[left]))    res[k] = arr[right] * arr[right--];
        else    res[k] = arr[left] * arr[left++];
    }

    return res;
}

// Driver function
int main(){
    vector<int> arr({-4, -2, 0, 1, 2});
    
    for(auto value:sortedSquares(arr))
        cout << value << " ";
    cout << endl;

    return 0;
}
