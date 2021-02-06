// add 2 numbers using bit
#include <bits/stdc++.h>
using namespace std;

// O(n)
// 4 ms
int add(int a, int b){
    // keep adding until we have no carry
    while(b != 0){
        // carry is not applied where it is discovered, it is applied to the left of where it was born

        // b will contain carry, generated from the prevous step
        int carry = a & b;

        // a is what happens when 2 numbers are added without taking caryy into consideration
        a = a^b;

        // b houses the carry from the operation, we will shift it by 1 place to left, in order to add it to the sum
        b = carry << 1;
    }

    return a;
}

// recursive approach
// 0 ms
int getSum(int a, int b){
    if(b == 0)  return a;

    int carry = a & b;

    a = a^b;
    b = ((carry & 0xffffffff) << 1);    // limiting to 32 bit
    a = getSum(a, b);

    return a;
}

// Driver function
int main(){
    int a = 12, b = 23;
    // cout << add(a, b) << endl;
    cout << getSum(a, b) << endl;
    return 0;
}
