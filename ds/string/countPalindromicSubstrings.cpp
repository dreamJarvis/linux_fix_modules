// To count all the palindromic substrings in a given string
#include <bits/stdc++.h>
using namespace std;

// DP solution
// time complexity : O(n^2)
// space complexity ; O(n^2)
int countPalindromes(string str){
    int n = str.length();
    int countPalindromes = n;

    vector<vector<bool>> dp(n, vector<bool>(n, 0));

    // for every single charecter , it is a palindrome
    int start = 0;
    int maxLen = 1;
    for(int i = 0; i < n; i++){
        dp[i][i] = true;
    }

    // every 2 size palindrome
    for(int i = 0; i < n-1; i++){
        if(str[i] == str[i+1]){
            dp[i][i+1] = true;
            countPalindromes++;
            start = i;
            maxLen = 2;
        }
    }

    // checking for palindrome with length > 3
    for(int k = 3; k <= n; k++){
        for(int i = 0; i < n-k+1; i++){
            int j = i + k - 1;

            if(dp[i+1][j-1] && str[i] == str[j]){
                dp[i][j] = true;
                countPalindromes++;

                if(k > maxLen){
                    maxLen = k;
                    start = i;
                }
            }
        }
    }

    return countPalindromes;
}

// Driver function
int main(){
    // string  str = "aaaabbaa";
    string  str = "tacocat";
    // string  str = "daata";

    cout << countPalindromes(str) << endl;

    return 0;
}
