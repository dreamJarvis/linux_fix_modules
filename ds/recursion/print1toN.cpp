#include <iostream>
using namespace std;

// void print(int n, int i){
//     // base condition
//     if(i > n)  return;
//     cout << i << " ";
//
//     // recursive condition
//     print(n, i+=1);
// }

void print(int n){
    // base condition
    if(n == 0)  return ;

    print(n-1);             // hypothesis

    cout << n << " ";       // induction
}

void printRev(int n){
    if(n == 0)  return;     // base condition

    cout << n << " ";       // induction
    printRev(n-1);          // hypothesis
}

int main(){
    int n=10;

    // print(n, i);
    print(n);
    cout << "\n";
    printRev(n);

    return 0;
}
