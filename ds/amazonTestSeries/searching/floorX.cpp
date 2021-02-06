/*
    8. Floor in a Sorted Array
    https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/0/?track=amazon-searching&batchId=192
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int findFloor(vector<long long> v, long long n, long long x){
    ll s = 0, e = n-1;
    int index = -1;
    while(s <= e){
        ll mid = (s+e)/2;

        if(v[mid] > x)
            e = mid-1;
        else{
            index = mid;
            s = mid+1;
        }
    }

    return index;
}

// Driver function
int main(){
    vector<ll> v({1,2,8,10,11,12,19});
    ll x = 0;
    // vector<ll> v({1,2,8,10,11,12,19});
    // ll x = 5;


    cout << findFloor(v, v.size(), x) << endl;

    return 0;
}
