// to find the longest palindromic subsequence in a given string
#include<bits/stdc++.h>
using namespace std;

// longest palindromic subsequences
// recursive solution
// time complexity : O(2^n)
// space complexity : O(2^n)
int longestPalindromicSubsequence(string a, int s, int e){
    if(s >= a.length()-1 || e <= 0){
        return 0;
    }

    char ch1 = a[s];
    char ch2 = a[e];

    int maxLen = 0;
    if(ch1 == ch2){
        maxLen = longestPalindromicSubsequence(a, s+1, e-1) + 1;
    }
    else {
        maxLen = max(
                        longestPalindromicSubsequence(a, s+1, e),
                        longestPalindromicSubsequence(a, s, e-1)
                    );
    }

    return maxLen;
}

// memoisation
// time complexity : better then recursive one
// space complexity : better then recursive one
int lpsMemo(string str, int s, int e, unordered_map<string, int> &visited){
    string key = to_string(s) + "_" + to_string(e);

    if(s >= str.length()-1 || e <= 0){
        return 0;
    }

    if(visited.count(key))
        return visited[key];

    char ch1 = str[s];
    char ch2 = str[e];

    int count = 0;
    if(ch1 == ch2)
        count = lpsMemo(str, s+1, e-1, visited) + 1;
    else
        count = max(lpsMemo(str, s+1, e, visited), lpsMemo(str, s, e-1, visited));

    visited[key] = count;
    return count;
}

int lpsUTIL(string str){
    unordered_map<string, int> visited;
    return lpsMemo(str, 0, str.length()-1, visited);
}

// DP
// time complexity : O(n^2)
// space complexity : O(n^2)
int longestPalindromicSubsequenceDP(string str){
    int n = str.length();

    // dp table
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // filling the initial values
    // every single element is a palindrome
    for(int i = 0; i < n; i++)
        dp[i][i] = 1;

    // filling vaues for every 2 element
    for(int i = 1; i < n; i++){
        dp[i-1][i] = 1;
        if(str[i] == str[i-1])
            dp[i-1][i] = 2;
    }

    // cout << "i" << endl;

    // finding palindromes of size grater than 2
    for(int k = 3; k <= n; k++){
        for(int i = 0; i < n-k+1; i++){
            int j = i + k - 1;

            // ki agar value iss subset ke starting index i, and ending index j equal h,
            // toh jitne bhi length ka palindrome hme i-1'th index and j-1'th index tk mila
            // h hm uss palindromic length me 2 add kr denge
            if(str[i] == str[j])
                dp[i][j] = dp[i+1][j-1] + 2;
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }

    // displays the table
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++)
    //         cout << dp[i][j] << "\t";
    //     cout << endl;
    // }

    return dp[0][n-1];
}

// Driver program
int main(){
    // string str = "BBABCBCAB";
    // string str = "agbdba";
    string str = "GEEKS FOR GEEKS";

    // int n = str.length()-1;
    // cout << longestPalindromicSubsequence(str, 0, n) << endl;
    cout << lpsUTIL(str) << endl;

    // cout << longestPalindromicSubsequenceDP(str) << endl;
	return 0;
}
