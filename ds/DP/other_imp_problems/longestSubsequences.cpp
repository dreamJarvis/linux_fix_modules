// 1143. Longest Common Subsequence
#include <bits/stdc++.h>
using namespace std;

// Longest common Subsequence
// recursive approach
int lcs(string str1, string str2){
    if(str1.length()==0 || str2.length()==0)
        return 0;

    char s1 = str1[0];
    char s2 = str2[0];

    int maxLength = 0;
    if(s1 == s2)
        maxLength = lcs(str1.substr(1), str2.substr(1)) + 1;
    else
        maxLength = max(lcs(str1.substr(1), str2), lcs(str1, str2.substr(1)));

    return maxLength;
}

int lcsUTIL(string a, string b){
    if(a.length() < b.length())
        swap(a, b);

    return lcs(a, b);
}

// memoisation : storing the repating values
int lcsMemo(string a, string b, int i, int j, unordered_map<string, int> &visited){
    string key = to_string(i) + to_string(j);

    if(i >= a.length() || j >= b.length())
        return 0;

    if(visited.count(key))
        return visited[key];

    char ch1 = a[i];
    char ch2 = b[j];

    int count = 0;
    if(ch1 == ch2)  count = lcsMemo(a, b, i+1, j+1, visited) + 1;
    else            count = max(lcsMemo(a, b, i+1, j, visited), lcsMemo(a, b, i, j+1, visited));

    visited[key] = count;
    return count;
}

int lcsMemoUTIL(string a, string b){
    unordered_map<string, int> visited;
    if(a.length() < b.length())
        swap(a, b);

    return lcsMemo(a, b, 0, 0, visited);
}

// Pure DP
int lcsDP(string str1, string str2){
    int n1 = str1.length();
    int n2 = str2.length();

    vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1)); // initializing 2d array

    for(int i = 0; i <= n1; i++)
        dp[i][0] = 0;

    for(int i = 0; i <= n2; i++)
        dp[0][i] = 0;

    for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= n2; j++){
            if(str1[i-1]==str2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // for(int i = 0; i <= n1; i++){
    //     for(int j = 0; j <= n2; j++)
    //         cout << dp[i][j] << "\t";
    //     cout << endl;
    // }

    return dp[n1][n2];
}

// Driver function
int main(){
    // string str1=  "abcde";
    // string str2 = "ace";
    // string str1 = "abc";
    // string str2 = "def";
    // string a = "abcdef";
    // string b = "hfcdle";

    string a = "abcdefpppopoiqp";
    string b = "cbfdlepoipipoqwepop";

    clock_t t1 = clock();
    cout << lcsUTIL(a, b) << endl;
    t1 = clock() - t1;
    cout << "recursive : " << t1 << endl;

    clock_t t2 = clock();
    cout << lcsMemoUTIL(a, b) << endl;
    t2 = clock() - t2;
    cout << "memoisation : " << t2 << endl;

    clock_t t3 = clock();
    cout << lcsDP(a, b) << endl;
    t3 = clock() - t3;
    cout << "DP : " << t3 << endl;

    return 0;
}
