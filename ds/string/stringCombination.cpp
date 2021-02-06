// to count all the subsequences of the given array
#include <bits/stdc++.h>
using namespace std;

// to print all the subsequences/subsets in a string
void printSubsequences(string str, string ans){
    if(str.length()==0){
        cout << ans << endl;
        return ;
    }

    char ch = str[0];
    printSubsequences(str.substr(1), ans+ch);
    printSubsequences(str.substr(1), ans);
}

// to count the total no. of subsequences/subsets in an given string
int countSubsequences(string str, string ans){
    if(str.length()==0){
        return 1;
    }

    char ch = str[0];
    int leftCount=0, rightCount=0;
    leftCount = countSubsequences(str.substr(1), ans+ch);
    rightCount = countSubsequences(str.substr(1), ans);

    return (leftCount + rightCount);
}

// Driver function
int main(){
    string str = "tacocat";

    // printSubsequences(str, "");
    cout << countSubsequences(str, "") << endl;

    return 0;
}
