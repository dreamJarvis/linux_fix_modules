// subtract 2 numbers using bit-manipulation
#include <bits/stdc++.h>
using namespace std;

// O(n)
// bitset() : for bit's operation
int sub(int a, int b){
    int x = max(abs(a), abs(b));
    int y = min(abs(a), abs(b));;
    while(y != 0){
        // hme yaha pe, and operator se ulta kaam krwana h, jaha wo additon me 1 + 1 = 1, deta tha ab wo whi subtraction 1 - 1 = 0, dega, mtlb and ka opeartion ulta kr diya
        int carry = (~x) & y;  // nand operator

        x = x ^ y;              // ya sum dega without subtracting carry

        y = carry << 1;         // farak itna h, ki ye carry, apne next step me total sum se subtractho jayega
    }

    if(abs(a) > abs(b))
        if(a < 0)
            return -x;
    return x;
}

// Driver function
int main(){
    int a = -14, b = 16;

    cout << sub(a,b) << endl;

    return 0;
}
