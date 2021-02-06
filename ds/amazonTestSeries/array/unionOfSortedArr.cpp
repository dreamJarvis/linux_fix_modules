/*
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(int arr1[], int arr2[], int n, int m){
    vector<int> result;

    int i = 0, j = 0;
    while(i < n && j < m){
        if(arr1[i] < arr2[j]){
            if(result.size() == 0 || result.back() != arr1[i])
                result.push_back(arr1[i]);
            i++;
        }
        else if(arr2[j] < arr1[i]){
            if(result.size() == 0 || result.back() != arr2[j])
                result.push_back(arr2[j]);
            j++;
        }
        else if(arr1[i] == arr2[j]){
            if(result.size() == 0 || result.back() != arr1[i])
                result.push_back(arr1[i]);
            i++;j++;
        }
    }

    while(i < n){
        if(result.size() == 0 || result.back() != arr1[i])
            result.push_back(arr1[i]);
        i++;
    }

    while(j < m){
        if(result.size() == 0 || result.back() != arr2[j])
            result.push_back(arr2[j]);
        j++;
    }

    return result;
}

// Driver function
int main(){
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3};

    // int arr1[] = {2, 2, 3, 4, 5};
    // int arr2[] = {1, 1, 2, 3, 4};

    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);

    for(auto i:findUnion(arr1, arr2, n, m))
        cout << i << " ";
    cout << endl;

    return 0;
}
