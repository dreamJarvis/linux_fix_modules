/*
    6. Index Of an Extra Element
    https://practice.geeksforgeeks.org/problems/index-of-an-extra-element/0/?track=amazon-searching&batchId=192
*/
#include <bits/stdc++.h>
using namespace std;

int findExtra(int a[], int b[], int n) {
    int index = n;
    int s = 0, e = n-1;
    while(s <= e){
        int mid = (s+e)/2;

        if(a[mid] == b[mid])
            s = mid+1;
        else{
            index = mid;
            e = mid-1;
        }
    }

    return index;
}

// Driver function
int main(){
    int a[] = {2,4,6,8,9,10,12};
    int b[] = {2,4,6,8,10,12};

    // int a[] = {3,5,7,9,11,13};
    // int b[] = {3,5,7,11,13};

    // int a[] = {1, 2, 3, 4};
    // int b[] = {1, 3, 4};

    int n = sizeof(a)/sizeof(a[0]);

    cout << findExtra(a, b, n) << endl;

    return 0;
}
