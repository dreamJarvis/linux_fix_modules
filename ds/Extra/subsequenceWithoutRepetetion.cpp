// leetcode 3. Longest Substring Without Repeating Characters
#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> visited{};

    int maxLength = 0;
    for(auto item:s){
        if(!visited.count(item))
            visited.insert(item);
        else{
            int len = visited.size();
            maxLength = max(maxLength, len);
            visited.clear();
            visited.insert(item);
        }
    }

    int temp =  visited.size();
    maxLength =  max(maxLength, temp);
    return maxLength;
}

// Driver function
int main(){
    // string str = "abcabcbb";
    string str = "aab";
    // string str = "bbbbb";
    // string str = "pwwkew";

    cout << lengthOfLongestSubstring(str) << endl;

    return 0;
}
