// To find gcd / hcf of 2 numbers
#include <bits/stdc++.h>
using namespace std;

// using euclidean algorithm
int gcd(int a, int b){
    // everything divides 0
    if(a == 0)
        return b;
    if(b == 0)
        return a;

    // base case :
    if(a == b)
        return a;

    // if a is >
    if(a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

// using modulo for finding gcd
int gcd2(int a, int b){
    if(b == 0)
        return a;
    return gcd2(b, a%b);
}

// Driver function
int main(){
    int a = 98, b = 56;

    cout << "GCD of " << a << " and " << b << " is " << gcd2(a, b) << endl;

    return 0;
}
