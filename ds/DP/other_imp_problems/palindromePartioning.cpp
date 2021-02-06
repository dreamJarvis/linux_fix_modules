// 131. Palindrome Partitioning
// https://www.youtube.com/watch?v=4ykBXGbonlA&t=168s
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str){
    int st = 0, end = str.length()-1;
    while(st <= end){
        if(str[st] != str[end])
            return false;

        st++;
        end--;
    }

    return true;
}

bool partition(string str, vector<string> ans, vector<vector<string>> &result){
    if(str.length()==0)
        return true;

    for(int i = 1; i < str.length(); i++){
        result.push_back(ans);
        ans.clear();

        string temp = str.substr(i);
        if(isPalindrome(temp) && partition(str.substr(i))){
            ans.push_back(temp);
        }else
            ans.clear();
    }

    return true;
}

vector<vector<string>> partitionUTIL(string str) {
    vector<vector<string>> ()
}

// Driver function
int main(){
    string str = "aab";

    return 0;
}
