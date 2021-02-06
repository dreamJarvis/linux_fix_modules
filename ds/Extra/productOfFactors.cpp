// to find the product of factors of a number
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define M 1000000007

// to calculate (x^y) in O(log y)
ll power(ll x, ll y){
    ll res = 1;

    while(y > 0){
        // when y is odd
        if(y&1) res = (res*x)%M;

        // y is even
        y = (y>>1)%M;       //  y = y/2;
        x = (x*x)%M;        //  x^2;
    }

    return res;
}

// count's the total no. of factors
int countFactors(int n){
    int count = 0;
    for(int i = 1; i*i <= n; i++){
        if(n%i == 0){
            // if both the divisors and dividend are equal , i.e. n is s square of i
            // .'. we include it only once
            if(n/i == i)    count++;
            else            count+=2;       // else, count both the factors, i.e. divisors and dividend
        }
    }

    return count;
}

ll multiplyFactors(int n){
    int numFactor = countFactors(n);       // calculates the total number of factors

    // calculate product of factors : even numbers
    ll product = power(n, numFactor/2);

    // if n is odd : power(n, numFactor/2) * sqrt(n)
    if(numFactor&1) product = (product * (int)sqrt(n))%M;

    return product;
}

// Driver function
int main(){
    int n;
    cin >> n;

    cout << multiplyFactors(n) << endl;

    return 0;
}
