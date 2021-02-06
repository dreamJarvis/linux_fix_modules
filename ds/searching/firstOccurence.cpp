#include <bits/stdc++.h>
using namespace std;

// find the first occurence of an element k, in an array arr
void firstOccurence(vector<int> &arr, int &k, int start, int end){
    if(start == end){
        return ;
    }

    int mid = start + (end - start) / 2;

    if(arr[mid] == k)
        if(arr[mid] == arr[mid-1])
            firstOccurence(arr, k=mid-1, start, mid - 1);
    else if(arr[mid] < k)
        firstOccurence(arr, k, mid + 1, end);

    firstOccurence(arr, k, start, mid - 1);
}

// Driver function
int main(){
    vector<int> arr({1, 2, 2, 3, 4, 5, 2, 8});
    int k = 2;

    int index = -1;
    firstOccurence(arr, index, 0, arr.size());

    cout << k << endl;

    return 0;
}
