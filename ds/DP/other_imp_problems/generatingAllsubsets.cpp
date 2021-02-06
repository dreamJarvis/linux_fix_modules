// to count all the palindromic substrings in the given strings
#include <bits/stdc++.h>
using namespace std;

// bool isPalindrome(string str){
//     int l = 0;
//     int r = str.size()-1;
//
//     while(l <= r){
//         if(str[l] != str[r])
//             return false;
//
//         l++;
//         r--;
//     }
//
//     return true;
// }
//
// void substrCountUtil(string s, int start, int end){
//     if(end == s.size()){
//         return ;
//     }
//     else if(start > end){
//         substrCountUtil(s, 0, end+1);
//     }
//     else {
//         string str="";
//         for(int i = start; i <= end; i++)
//             str += s[i];
//
//         if(isPalindrome(str)){
//             cout << str << endl;
//             totalCount++;
//         }
//
//         substrCountUtil(s, start+1, end);
//     }
//
//     return ;
// }
//
// long substrCount(string s) {
//     substrCountUtil(s, 0, 0);
//     return totalCount;
// }

// global variables
int totalPalindromeCount = 0;
unordered_map<string, bool> palindromeTable;

bool isPalindrome(int si, int ei, string str){
    string key = to_string(si) + to_string(ei);

    if(palindromeTable[key]){
        totalPalindromeCount++;
        return true;
    }

    if(si == ei){
        totalPalindromeCount++;
        palindromeTable[key] = true;
        return true;
    }

    // the first charecters
    char ch1 = str[si];
    char ch2 = str[ei];

    // if the charecters are adjacent
    if(si == ei - 1){
        return ch1 == ch2 ? palindromeTable[key] : false;
    }

    if(ch1 == ch2 && isPalindrome(si+1, ei-1, str)){
        totalPalindromeCount++;
        palindromeTable[key] = true;
        return true;
    }
    else
        return false;
}

long substrCount(string str){
    if(s.size() <= 1)   return str;

    int len = s.size();

    for(int i = 0; i < len-1; i++)
        for(int j = i; i < len; i++)
            isPalindrome(i, j, str);
}

// Driver function
int main(){
    string str = "abcbaba";

    cout << substrCount(str) << endl;

    return 0;
}
