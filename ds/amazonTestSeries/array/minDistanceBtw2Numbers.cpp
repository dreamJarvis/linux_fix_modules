/*
    4. Minimum distance between two numbers
    https://practice.geeksforgeeks.org/problems/minimum-distance-between-two-numbers/0/?track=amazon-arrays&batchId=192#

    ref : https://www.youtube.com/watch?v=hoceGcqQczM
*/
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;

// tc : O(n)
// sc : O(1)
int minDist(int a[], int n, int x, int y) {
    int prev = -1, minDist = n;

    for(int i = 0; i < n; i++){
        if(a[i] == x || a[i] == y){
            if(prev != -1 && a[i] != a[prev])
                minDist = min(minDist, abs(i-prev));
            prev = i;
        }
    }

    return minDist == n ? -1 : minDist;
}

int main(){
    // int arr[] = {1, 2, 3, 2};
    // int x = 1, y = 2;

    int arr[] = {86,39,90,67,84,66,62};
    int x = 39, y = 66;

    // int arr[] = {86,39,90,67,84,66,62};
    // int x = 42, y = 12;

    int n = sizeof(arr)/sizeof(arr[0]);

    cout << minDist(arr, n, x, y) << endl;

	return 0;
}
