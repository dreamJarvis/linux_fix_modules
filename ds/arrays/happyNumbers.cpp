#include <bits/stdc++.h>
using namespace std;

// happy numbers
bool isHappy(int num){
    while(num != 1){
        int temp = num;
        int sum = 0;
        while(temp != 0){
            sum += (temp%10)*(temp%10);
            temp/=10;
        }

        if(sum == 4)    return false;
        num = sum;
    }

    return true;
}

// driver function
int main(){
    int num = 123;
    isHappy(num);
    return 0;
}
