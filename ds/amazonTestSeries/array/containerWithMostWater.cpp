/*
    20. Container With Most Water
    https://practice.geeksforgeeks.org/problems/container-with-most-water0535/0/?track=amazon-arrays&batchId=192
*/
#include <bits/stdc++.h>
using namespace std;

#define lli long long int

long long maxArea(long long A[], int len){
    lli maxArea = 0, area = 0;
    int s = 0, e = len-1;

    while(s < e){
        area = min(A[s], A[e])*(abs(s-e));

        if(A[s] < A[e])         s++;
        else if(A[s] >= A[e])   e--;

        maxArea = max(maxArea, area);
    }

    return maxArea;
}

// Driver function
int main(){
    lli arr[] = {1, 5, 4, 3};
    // lli arr[] = {3, 1, 2, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << maxArea(arr, n) << endl;

    return 0;
}
