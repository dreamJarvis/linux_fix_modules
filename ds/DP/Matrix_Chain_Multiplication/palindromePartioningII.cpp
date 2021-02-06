/*
    132. Palindrome Partitioning II
    https://leetcode.com/problems/palindrome-partitioning-ii/
*/
#include <iostream>
#include <unordered_map>
#include <climits>
#include <cstring>
using namespace std;

// tc : O(n^3)
// bool isPalindrome(string str, int i, int j){
//     while(i <= j){
//         if(str[i] != str[j])
//             return false;
//         i++;
//         j--;
//     }
//
//     return true;
// }
//
// int minCut(string str) {
//     int n = str.length();
//
//     int dp[n+1][n+1];
//     memset(dp, 0, sizeof(dp));
//
//     for(int i = 0; i < n; i++)
//         dp[i][i] = 0;
//
//     for(int l = 2; l <= n; l++){
//         for(int i = 0; i < n-l+1; i++){
//             int j = i+l-1;
//
//             if(isPalindrome(str, i, j)){
//                 dp[i][j] = 0;
//             }
//             else {
//                 dp[i][j] = INT_MAX;
//                 for(int k = i; k <= j-1; k++){
//                     long int temp =  1 + dp[i][k] + dp[k+1][j];
//
//                     if(temp < dp[i][j])
//                         dp[i][j] = temp;
//                 }
//             }
//         }
//     }
//
//     return dp[0][n-1];
// }

// tc : O(n^2)
// sc : O(n^2) + O(n)
int minCut(string str){
    int n = str.length();

    bool dp[n+1][n+1];
    memset(dp, false, sizeof(dp));

    // palindrome of length = 1
    for(int i = 0; i < n; i++)
        dp[i][i] = true;

    // palindrome of length = 2
    for(int i = 0; i < n-1; i++)
        if(str[i] == str[i+1])
            dp[i][i+1] = true;

    // palindromes of len > 2
    for(int len = 3; len <= n; len++){
        for(int i = 0; i < n-len+1; i++){
            int j = i + len - 1;

            if(str[i] == str[j] && dp[i+1][j-1]){
                dp[i][j] = true;
            }
        }
    }

    int cuts[n] = {n};

    for(int i = 0; i < n; i++){
        int temp = INT_MAX;
        if(dp[0][i]){
            cuts[i] = 0;
        }
        else{
            for(int j = 0; j < i; j++){
                if(dp[j+1][i] && temp > cuts[j] + 1){
                    temp = cuts[j] + 1;
                }
            }
            cuts[i] = temp;
        }
    }

    return cuts[n-1];
}

// space efficient method
// tc : O(n^2)
// tc : O(n)
int minCut2(string s){
    int n = s.length();

    int dp[n+1];

    // initializing values
    for(int i = 0; i <= n; i++)
        dp[i] = i-1;

    for(int i = 0; i < s.length(); i++){

        // for odd occurences
        for(int j = 0; i-j >= 0 && i+j < s.length(); j++){
            if(s[i-j] == s[i+j])
                dp[i+j+1] = min(dp[i+j+1], 1 + dp[i-j]);
            else
                break;
        }

        // for even occurences
        for(int j = 0; i-j >= 0 && i+j+1 < s.length(); j++){
            if(s[i-j] == s[i+j+1])
                dp[i+j+2] = min(dp[i-j]+1, dp[i+j+2]);
            else
                break;
        }
    }

    return dp[n];
}

// Driver function
int main(){
    string str = "aabbbc";
    // string str = "ccd";

    cout << minCut(str) << endl;
    cout << minCut2(str) << endl;

    return 0;
}
