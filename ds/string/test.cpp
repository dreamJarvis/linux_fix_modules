#include<bits/stdc++.h>
using namespace std;

// longest common subsequences
// recursive solution
int lcs(string str1, string str2){
    if(str1.length()==0 || str2.length()==0)
        return 0;

    char ch1 = str1[0];
    char ch2 = str2[0];

    int count = 0;
    if(ch1 == ch2)  count = lcs(str1.substr(1), str2.substr(1)) + 1;
    else            count = max( lcs(str1.substr(1), str2), lcs(str1, str2.substr(1)) );

    return count;
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

// dp solution
int lcsDP(string a, string b){
    if(a.length() < b.length()){
        swap(a, b);
    }

    int aLength = a.length();
    int bLength = b.length();

    vector<vector<int>> dp(bLength+1, vector<int>(aLength+1, 0));   // dp table

    // fiiling the 1st row
    for(int i = 0; i <= aLength; i++)
        dp[0][i] = 0;

    // filling the 1st column
    for(int i = 0; i <= bLength; i++)
        dp[i][0] = 0;

    for(int i = 1; i <= bLength; i++){
        for(int j = 1; j <= aLength; j++){
            if(b[i-1] == a[j-1])    dp[i][j] = dp[i-1][j-1]+1;
            else                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[bLength][aLength];
}

// Driver program
int main(){
    string a = "abcdefpppopoiqp";
    string b = "cbfdlepoipipoqwepop";
    // string a = "abcdef";
    // string b = "hfcdle";

    clock_t t1 = clock();
    cout << lcs(a, b) << endl;
    t1 = clock() - t1;
    cout << "recursive : " << t1/60 << endl;

    clock_t t2 = clock();
    cout << lcsMemoUTIL(a, b) << endl;
    t2 = clock() - t2;
    cout << "memoisation : " << t2/60 << endl;

    clock_t t3 = clock();
    cout << lcsDP(a, b) << endl;
    t3 = clock() - t3;
    cout << "DP : " << t3/60 << endl;

    return 0;
}
