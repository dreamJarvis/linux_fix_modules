#include <bits/stdc++.h>
using namespace std;

// Approach 1
// longest common prefix
// horizontal scanning :worst cast :  O(s), s = sum of all the strings
string longestCommonPrefixHorizontalScanning(vector<string> &strs){
    string prefix = strs[0];
    int len = strs.size();

    for(int i = 1; i < len; i++){
        string temp =  "";
        int size = min(prefix.length(), strs[i].length());

        for(int j = 0; j < size; j++){
            if(prefix[j] != strs[i][j]){
                break ;
            }
            else
                temp += strs[i][j];
        }
        prefix = temp;
    }

    return prefix;
}

// Approach 2
// vertical scanning
// worst case : O(s), s -> sun of all the charecters
// best case is better then horizontal scanning, cause here it will iterate to the shorest string size
string longestCommonPrefixVerticalScanning(vector<string> &str){
    if(str.size() == 0)   return "";

    for(int i = 0; i < str[0].length(); i++){
        char ch = str[0][i];

        for(int j = 1; j < str.size(); j++){
            if(i == str[j].length() || str[j][i] != ch)
                return str[0].substr(0, i);
        }
    }

    return str[0];
}

// ---------------------- divide and concquer method ------------------------------- //
// Approach 3
// worst case : O(s)
// best casr : O(minLen * n)
// space complexity : O(m * logn)
string commonPrefix(string left, string right){
    int minLength = min(left.length(), right.length());

    for(int i = 0; i < minLength; i++){
        if(left[i]  != right[i])
            return left.substr(0, i);
    }

    return minLength == left.length() ? left : right;
}

string divideAndConquer(vector<string> &str, int l, int r){
    if(l == r)
        return str[l];
    else{
        int mid = (l+r)/2;
        string lcpLeft = divideAndConquer(str, l, mid);
        string lcpRight = divideAndConquer(str, mid + 1, r);
        return commonPrefix(lcpLeft, lcpRight);
    }
}

string divideAndConquerUTIL(vector<string> &str){
    if(str.size() == 0) return "";
        return divideAndConquer(str, 0, str.size()-1);
}

// Approach 4 : Binary Search

// Driver function
int main(){
    vector<string> strs ({"flower","flow","flight"});
    // cout << longestCommonPrefixHorizontalScanning(strs) << endl;
    // cout << longestCommonPrefixVerticalScanning(strs) << endl;
    cout << divideAndConquerUTIL(strs) << endl;
    return 0;
}
