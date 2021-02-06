// 258. Add Digits
#include <bits/stdc++.h>
using namespace std;

int addDigitsI(int num) {
    while(num >= 10){
        int carry = num%10;
        int sum = num/10 + carry;
        num = sum;
    }

    return num;
}

int addDigitsII(int num) {
    int sum,x;
    if(num>=0 && num<=9)
        return num;

    while(true){
        sum=0;
        while(num!=0){
            x = num % 10;
            sum = sum + x;
            num = num / 10;
        }

        if(sum>=0 && sum<=9)
            return sum;
        num = sum;
    }

    return sum;
}

// kyuki hme question me keh rkha h ki , hme single digit sum return krwana h,
// yani ki < 10, isska mtlb wo 1 -- 9 ke beech me hoga
int addDigitsIII(int num) {
    if(num%9 == 0 && num!=0)    // ya toh wo number pura divisible h 9 se
        return 9;

    return (num%9);  // nhi pura divisible h toh usska remainder bhej denge
}

// Driver function
int main(){
    int n = 199;

    cout << addDigitsIII(n) << endl;
    return 0;
}
