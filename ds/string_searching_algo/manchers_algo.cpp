// manachers algorithm
// To find longest palindromic substring using manacher's algorithm
// https://www.youtube.com/watch?v=nbTSfrEfo6M
#include <bits/stdc++.h>
using namespace std;

int longestPalindromicSubstring(string str){
    vector<int> p(str.length());
    int c = 0, r = 0;

    int maxPalindrome = 0;
    for(int i = 1; i < str.length(); i++){
        int mirr = 2*c - i;

        if(i < r)
            p[i] = min(r-i, p[mirr]);

        while(str[i + (1 + p[i])] == str[i - (1 + p[i])]){
            p[i]++;
        }

        if(i + p[i] > r){
            c = i;
            r = i + p[i];
        }

        maxPalindrome = max(maxPalindrome, p[i]);
    }

    // for(auto i : p)
    //     cout << i << "  ";
    // cout << endl;

    return maxPalindrome;
}

int  longestPalindromicSubstringUTIL(string str){
    int n = str.length();

    string newStr = "$";
    for(auto i:str){
        newStr += '#';
        newStr += i;
    }
    newStr += "#@";

    // cout <<newStr << endl;

    return longestPalindromicSubstring(newStr);
}

// Driver function
int main(){
    string str = "daata";
    // string str = "tacocat";
    cout << longestPalindromicSubstringUTIL(str) << endl;

    return 0;
}
