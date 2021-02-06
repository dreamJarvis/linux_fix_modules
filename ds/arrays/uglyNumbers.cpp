#include <bits/stdc++.h>
using namespace std;

// simple solution
// time complexity : O(n^2)
// spoace complexity : O(1)

// here we divide until we stop getting 0 as a remainder, that means now we have to try other prime no. at our disposal to fully divide it
int maxDivide(int a, int b){
    while(a%b == 0)
        a = a/b;
    return a;
}

// to check if a number is ugly or not
int isUgly(int no){
    no = maxDivide(no, 2);
    no = maxDivide(no, 3);
    no = maxDivide(no, 5);

    return (no == 1)?1 : 0;
}

// to get the n'th ugly number
int getNthUgly(int n){
    int i = 1;
    int count = 1;

    while(n > count){
        i++;
        if(isUgly(i))   count++;
    }

    return i;
}

// DP solution
// because every ugly number is a product of (2, 3, or 5). .'. koi bhi next ugly nuber agr hme chahiye toh wo (2, 3, ya 5) insb mese kisi ka product he hoga,
unsigned getNthUglyNumber(unsigned n){
    unsigned ugly[n];       // to store ugly numbers
    unsigned i2 = 0, i3 = 0, i5 = 0;
    unsigned nextMultipleOf2 = 2;
    unsigned nextMultipleOf3 = 3;
    unsigned nextMultipleOf5 = 5;
    unsigned nextUglyNo = 1;

    ugly[0] = 1;
    for(int i = 1; i < n; i++){
        nextUglyNo = min(nextMultipleOf2, min(nextMultipleOf3, nextMultipleOf5));

        ugly[i] = nextUglyNo;

        if(nextUglyNo == nextMultipleOf2){
            i2++;
            nextMultipleOf2 = ugly[i2]*2;
        }
        if(nextUglyNo == nextMultipleOf3){
            i3++;
            nextMultipleOf3 = ugly[i3]*3;
        }
        if(nextUglyNo == nextMultipleOf5){
            i5++;
            nextMultipleOf5 = ugly[i5]*5;
        }
    }

    return nextUglyNo;
}

// Driver function
int main(){
    unsigned n = 150;
    cout << getNthUglyNumber(n) << endl;
    return 0;
}
