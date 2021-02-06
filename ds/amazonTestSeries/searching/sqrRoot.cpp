/*
    1. Square root
    https://practice.geeksforgeeks.org/problems/square-root/0/?track=amazon-searching&batchId=192
*/
#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int x){
    if(x == 0 || x == 1)
        return x;

    int s = 1, e = x, ans;
    while(s <= e){
        int mid = (s+e)/2;

        if(mid*mid == x)
            return mid;

        /*
            since we need floor, we update answer when mid*mid is smaller then x,
            ans move closer to sqrt(x)
        */
        if(mid*mid < x){
            s = mid+1;
            ans = mid;
        }
        else
            e = mid-1;
    }

    return ans;
}

// Driver function
int main(){
    int x = 5;

    cout << floorSqrt(x) << endl;

    return 0;
}
