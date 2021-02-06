// to find gcd of an array of numbers
#include <bits/stdc++.h>
using namespace std;

// gcd
int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

// gcd of an array
int gcdOfArray(vector<int> &arr){
    int n = arr.size();
    int ans = arr[0];

    for(int i = 1; i < n; i++){
        ans = gcd(ans, arr[i]);

        if(ans == 1)
            return 1;
    }
    return ans;
}

// Driver function
int main(){
    vector<int> arr({2, 4, 6, 8});

    cout << "gcd of array ";
    for(auto val:arr)
        cout << val << " ";
    cout << " is : " << gcdOfArray(arr) << endl;

    return 0;
}
