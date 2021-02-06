// 628. Maximum Product of Three Numbers
#include <bits/stdc++.h>
using namespace std;

int maximumProduct(vector<int>& nums) {
    int n = nums.size();

    // to find 2 smallest elements
    int a = INT_MAX, b = INT_MAX;
    for(int i = 0; i < n; i++){
        if(a > nums[i]){
            b = a;
            a = nums[i];
        }
        else if(b > nums[i]){
            b = nums[i];
        }
    }

    // to find the 3 largest elements
    int c = INT_MIN, d = INT_MIN, e = INT_MIN;
    for(int i = 0; i < n; i++){
        if(e < nums[i]){
            c = d;
            d = e;
            e = nums[i];
        }
        else if(d < nums[i]){
            c = d;
            d = nums[i];
        }
        else if(c < nums[i])
            c = nums[i];
    }

    return max(a*b*e, c*d*e);
}
// Driver function
int main(){
    vector<int> arr({1, 2, 3});

    cout << maximumProduct(arr) << endl;

    return 0;
}
