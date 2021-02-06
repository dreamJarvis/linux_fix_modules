// to print the number of permutations in the string
#include <bits/stdc++.h>
using namespace std;

void printPermuations(string str, string ans){
    // base case
    if(str.length() == 0){
        cout << ans << endl;
        return ;
    }

    for(int i = 0; i < str.length(); i++){
        char ch = str[i];
        string restOfString = str.substr(0, i) + str.substr(i+1);
        printPermuations(restOfString, ans+ch);
    }
}

// Driver function
int main(){
    string str;
    cin >> str;

    printPermuations(str, "");

    return 0;
}
