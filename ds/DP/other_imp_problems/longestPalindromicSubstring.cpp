// To count all the palindromic substrings in a given string
#include <bits/stdc++.h>
using namespace std;

// retuns the length of the longest palindromic substring
// time complexity : O(n^2)
// space complexity : O(n)
string lps(string str){
    int n = str.length();
    vector<int> lpsSize(n, 0);

    int maxPal = 0;
    int start = 0, end;
    for(int i = 0; i < n; i++){
        int left = i-1, right = i+1;
        while(left >= 0 && right < n && str[left] == str[right]){
            lpsSize[i]++;
            left--;
            right++;
        }

        if(maxPal < lpsSize[i]){
            maxPal = lpsSize[i];
            start = left+1;
            end = right-1;
        }
    }

    string result="";
    for(int i = start; i <= end; i++)
        if(str[i] != '#' && str[i] != '@' && str[i] != '$')
            result += str[i];

    return result;
}

string lpsUtil(string str){
    int n = str.length();

    // extreme cases
    if(n < 2) return str;

    string newStr="@";
    for(auto i:str){
        newStr += '#';
        newStr += i;
    }
    newStr += "#$";

    return lps(newStr);
}

// DP solution
// time complexity : O(n^2)
// space complexity ; O(n^2)
string lpsDP(string str){
    int n = str.length();

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

                if(k > maxLen){
                    maxLen = k;
                    start = i;
                }
            }
        }
    }

    return str.substr(start, maxLen);
}

string manachersAlgo(string str){
    int n = str.length();
    vector<int> lps(n);

    int c = 0, r = 0;
    int maxLen = 0, start = 0, end;

    for(int i = 1; i < n; i++){
        int mirr = 2*c - i;

        if(i < r)
            lps[i] = min(r - i, lps[mirr]);

        while(str[i + (lps[i] + 1)] == str[i - (lps[i] + 1)])
            lps[i]++;

        if(i + lps[i] > r){
            c = i;
            r = i + lps[i];
        }

        if(lps[i] > maxLen){
            maxLen = lps[i];
            start = i - lps[i];
            end = r;
        }
    }

    string result="";
    for(int i = start; i <= end; i++)
        if(str[i] != '#' && str[i] != '@' && str[i] != '$')
            result += str[i];

    return result;
}

// manachers Algorithm
string manachersUTIL(string str){
    int n = str.length();

    // extreme cases
    if(n < 2) return str;

    string newStr="@";
    for(auto i:str){
        newStr += '#';
        newStr += i;
    }
    newStr += "#$";

    return manachersAlgo(newStr);
}

// Driver function
int main(){
    string  str = "aaaabbaa";
    // string  str = "cbbd";

    // cout << lpsUtil(str) << endl;
    cout << manachersUTIL(str) << endl;

    return 0;
}
