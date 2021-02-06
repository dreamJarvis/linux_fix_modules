/*
    Print all LCS sequences
    https://practice.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1
*/
#include <bits/stdc++.h>
using namespace std;

// Driver function
int main(){
    // string s = "abaaa";
    // string t = "baabaca";

    string s = "fecbdabbbce";
    string t = "debecafcfeaebb";

    for(auto &i:printAllLCS(s, t))
        cout << i << " ";
    cout << endl;

    return 0;
}
