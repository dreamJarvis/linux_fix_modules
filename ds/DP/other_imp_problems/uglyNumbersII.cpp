/*
    264. Ugly Number II
    https://leetcode.com/problems/ugly-number-ii/
*/
#include <bits/stdc++.h>
using namespace std;

// #define lli long long int
// int nthUglyNumber(int n) {
//     set<ll> st;
//     st.insert(1);
//
//     lli uglyNum = 1;
//     int index = 0;
//     while(!st.empty()){
//         if(index == n)  break;
//
//         uglyNum = (*st.begin());
//         st.erase(uglyNum);
//
//         // insert
//         st.insert(2*uglyNum);
//         st.insert(3*uglyNum);
//         st.insert(5*uglyNum);
//
//         index++;
//     }
//
//     return uglyNum;
// }

int nthUglyNumber(int n) {
    if(n == 1)  return 1;

    vector<int> uglies(n);
    uglies[0] = 1;

    // indexes for respective lists
    int l2 = 0, l3 = 0, l5 = 0;

    for(int i = 1; i < n; i++){
        uglies[i] = min(min(2*uglies[l2], 3*uglies[l3]), 5*uglies[l5]);

        /*  from whichever index the next ugly number belonged from,
            we will increment the index
        */
        if(uglies[i] == 2*uglies[l2])
            l2++;

        if(uglies[i] == 3*uglies[l3])
            l3++;

        if(uglies[i] == 5*uglies[l5])
            l5++;
    }

    return uglies[n-1];
}

// Driver function
int main(){
    int n = 1407;
    cout << nthUglyNumber(n) << endl;
    return 0;
}
