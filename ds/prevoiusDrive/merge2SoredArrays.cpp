// merge 2 sorted arrays
// attempt this question and its varients --> (https://www.geeksforgeeks.org/merge-two-sorted-arrays-o1-extra-space/)
#include <bits/stdc++.h>
using namespace std;

// tc : O(N*log(N));
// sc : O(1)
void mergeArraysI(vector<int> &arr1, vector<int> &arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();

    for(auto i:arr2)
        arr1.push_back(i);

    sort(arr1.begin(), arr1.end());
    return ;
}

// tc : O(N)
// sc : O(N)
void mergeArraysII(vector<int> &arr1, vector<int> &arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();

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

    arr1 = res;
    return ;
}

// Driver function
int main(){
    vector<int> arr1({4, 7, 13, 20});
    vector<int> arr2({1, 3, 5, 19, 25});

    // mergeArraysI(arr1, arr2);
    // for(auto i:arr1)
    //     cout << i << " ";
    // cout << endl;

    mergeArraysII(arr1, arr2);
    for(auto i:arr1)
        cout << i << " ";
    cout << endl;

    return 0;
}
