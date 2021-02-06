/*
    214. Shortest Palindrome
    https://leetcode.com/problems/shortest-palindrome/

    reference : https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
    https://www.youtube.com/watch?v=c4akpqTwE5g
*/
#include <bits/stdc++.h>
using namespace std;

string shortestPalindrome(string s) {
    string rev(s);
    reverse(rev.begin(), rev.end());

    string l = s + '#' + rev;
    int n = l.length();

    int lps[n];         // longest prefix array

    int len = 0;
    lps[0] = 0;
    int i = 1;

    while(i < n){
        if(l[i] == l[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len != 0){
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }

    return (rev.substr(0, s.length() - lps[n-1]) + s);
}

// Driver function
int main(){
    string str = "aacecaaa";
    // string str = "ababbbabbaba";
    // string str = "abcd";
    // string str = "";

    string res = shortestPalindrome(str);
    cout << res << " - " << res.length() << endl;

    return 0;
}

/*
"ababbabbbababbbabbaba"
*/
