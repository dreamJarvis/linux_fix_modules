/*
    Tower of Hanoi
    https://practice.geeksforgeeks.org/problems/tower-of-hanoi/0
*/
#include <iostream>
using namespace std;

void TOH(int s, int d, int h, int n){
    if(n==1){
        cout << "move disk " << n << " from rod " << s << " to rod " << d << endl;
        return;
    }

    TOH(s, h, d, n-1);
    cout << "move disk " << n << " from rod " << s << " to rod " << d << endl;
    TOH(h, d, s, n-1);
}

// Driver function
int main(){
    int n;
    cin >> n;
    TOH(1, 3, 2, n);
    return 0;
}
