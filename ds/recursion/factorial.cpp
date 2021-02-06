#include <iostream>
using namespace std;

int fact(int n){
    // base condition
    if(n == 0 || n == 1)
        return 1;

    int t = fact(n-1);          // hypothesis
    return (n*t);               // induction
}

int main(){
    int n = 5;
    cout << fact(n) << endl;
    return 0;
}
