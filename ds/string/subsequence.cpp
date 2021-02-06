// to print all the possible subsequences of a given string
#include <bits/stdc++.h>
using namespace std;

void printSubsequences(string str, string ans){
    // base case:
    if(str.length() == 0){
        cout << ans << endl;
        return ;
    }

    char ch = str[0];
    string restOfString = str.substr(1);

    printSubsequences(restOfString, ans);       //  ek baar consider krenge
    printSubsequences(restOfString, ans+ch);    //  ek baar nhi krenge
}

// Driver function
int main(){
    printSubsequences("abc", "");
    return 0;
}
