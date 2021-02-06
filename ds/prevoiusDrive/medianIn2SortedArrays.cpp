// find median in 2 sorted arrays
#include <bits/stdc++.h>
using namespace std;

// tc : O(N)
// sc : O(N)
int medianOfSortedArrays(vector<int> &arr1, vector<int> &arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();

    // sorting and merging 2 arrays
    vector<int> res;
    int i = 0, j = 0;
    while(i < n1 && j < n2){
        if(arr1[i] <= arr2[j]){
            res.push_back(arr1[i]);
            i++;
        }
        else if(arr1[i] > arr2[j]){
            res.push_back(arr2[j]);
            j++;
        }
    }

    // arr1 ke remaining elements ke liye
    while(i < n1){
        res.push_back(arr1[i]);
        i++;
    }

    // arr2 ke remaining elements ke liye
    while(j < n2){
        res.push_back(arr2[j]);
        j++;
    }

    int mid = (n1+n2)%2;
    int index = n1+n2;
    if(mid == 0)
        return ((res[index/2] + res[index/2-1])/2);
    return res[index/2];
}

// Driver function
int main(){
    vector<int> arr1({4, 7, 13, 20, 40});
    vector<int> arr2({1, 3, 5, 19, 25});

    int median = medianOfSortedArrays(arr1, arr2);
    cout << median << endl;

    return 0;
}
