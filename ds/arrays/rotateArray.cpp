// Given an array, rotate the array to the right by k steps, where k is non-negative. (leetcode : 189)
#include <bits/stdc++.h>
using namespace std;

// rotating an array
// void rotateArray(std::vector<int> &arr, int k){
//     if(k > arr.size())
//         k = k/arr.size();
//
//     int i = 0;
//     int j = arr.size() - k;
//
//     if(i == j)
//         return ;
//
//     int fst = arr[0];
//     cout << arr[j] << endl;
//
//     while(j < arr.size()){
//         swap(arr[i], arr[j]);
//         i++;
//         j++;
//     }
//
//     int temp;
//
//     cout << arr[i] << endl;
//     while(arr[i] != fst){
//         temp = arr[i];
//         arr.erase(arr.begin()+i);
//         arr.push_back(temp);
//     }
// }

void rotateArray(vector<int> &arr, int k){
    // reversing the array
    reverse(arr.begin(), arr.end());

    if(k > arr.size())
        k = k%arr.size();

    int low = 0;
    int high = k-1;

    while(low < high){
        swap(arr[low], arr[high]);
        low++;
        high--;
    }

    low = k;
    high = arr.size()-1;
    while(low < high){
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}

// Driver function
int main(){
    vector<int> arr({1, 2, 3, 4, 5, 6});
    // vector<int> arr({1, 2});
    int k = 11;

    rotateArray(arr, k);

    for(auto value:arr){
        cout << value <<" ";
    }
    return 0;
}
