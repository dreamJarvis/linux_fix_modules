// hackerRank : Highest Value Palindrome
// discussed here --> https://www.geeksforgeeks.org/make-largest-palindrome-changing-k-digits/
#include <bits/stdc++.h>
using namespace std;

string highestValuePalindrome(string s, int n, int k) {
    string str = s;

    int l = 0;
    int r = n-1;

    while(l <= r){
        if(str[l] != str[r]){
            str[l] = str[r] = max(str[l], str[r]);
            k--;
        }
        l++;
        r--;
    }

    if(k < 0)   return "-1";

    l = 0;
    r = n-1;

    while(l <= r){
        if(l == r && k > 0){
            str[l] = '9';
        }

        if(str[l] < '9'){
            if(str[l] == s[l] && s[l] == s[r] && k >= 2){
                str[l] = str[r] = '9';
                k-=2;
            }

            else if(k >= 1 && (str[l] != s[l] || str[l] != s[r])){
                str[l] = str[r] = '9';
                k--;
            }
        }

        l++;
        r--;
    }

    return str;
}

// Driver function
int main(){
    string str = "932239";
    int k = 2;

    cout << highestValuePalindrome(str, str.size(), k) << endl;

    return 0;
}
/*
3943, k = 1
092282, k = 3
0011, k = 1
777, k=0
932239, k = 2
5, k =1;
*/
