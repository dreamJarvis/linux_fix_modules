#include <bits/stdc++.h>
using namespace std;

int countDivisors(int n){
    int prod = 1;

    for(int i = 2; i <= n/2; i++)
        if(n%i==0)  prod*=i;

    return prod*n;
}

// Driver function
int main(){
    int n = 1;
    cout << "produt of divisors : " << countDivisors(n) << endl;
    return 0;
}
