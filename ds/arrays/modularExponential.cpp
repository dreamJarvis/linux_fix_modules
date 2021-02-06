// to calculate power efficiently
#include <bits/stdc++.h>
using namespace std;

// to calculate (x^y) in O(log y)
int modularExponential(int x, unsigned int y){
    int res = 1;

    while(y > 0){
        // if y is odd
        if(y&1)
            res = res*x;

        // y must be even now
        y = y >> 1;
        x = x*x;
    }
    return res;
}

// to calculate (x^y)%p in O(log y)
int power(int x, unsigned int y, int p){
    int res = 1;

    x = x % p;

    while(y > 0){
        // if y is odd, multiply x with result
        if(y&1) res = (res*x)%p;

        // y must be even now
        y = y>>1;   //  y = y/2
        x = (x*x)%p;
    }
    return res;
}

// Driver function
int main(){
    int x = 2;
    int y = 5;
    int p = 13;

    cout << "Power is : " << power(x,y,p) << endl;

    cout << modularExponential(x, y) << endl;
    return 0;
}
