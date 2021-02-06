// leetcode : 969
// gfg : https://www.geeksforgeeks.org/pancake-sorting/
#include <bits/stdc++.h>
using namespace std;

// finding the index of the maximum element
int findMax(vector<int> &arr, int index){
    int maxIndex = 0, maxElement = INT_MIN;
    for(int i = 0; i <= index; i++){
        if(arr[i] > maxElement){
            maxIndex = i;
            maxElement = arr[i];
        }
    }

    return maxIndex;
}

// ab hm start se leke max-element ke index tk values swap kr denge
void flip(vector<int> &arr, int index){
    int start = 0, end = index;
    while(start <= end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void pancakeSorting(vector<int> &arr){
    int n = arr.size()-1;

    for(int i = n; i >= 0; --i){
        int maxIndex = findMax(arr, i);

        // agar max element already array ke last index pr h, toh hme kuch krne ke zarurat ne nhi h
        if(maxIndex != i){
            flip(arr, maxIndex);
            flip(arr, i);
        }
    }
}

// Driver funtion
int main(){
    vector<int> arr({3, 2, 4, 1});
    pancakeSorting(arr);

    for(auto value:arr)
        cout << value << " ";

    return 0;
}
