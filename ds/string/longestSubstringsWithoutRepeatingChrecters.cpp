// longest substring without repeating carecters
#include <bits/stdc++.h>
using namespace std;

// O(n^2)
int lengthOfLongestSubstring(string s) {
    int n = s.length();

    int i = 0;
    int length = 0, maxLength = 0;
    while(i < n){
        maxLength = max(maxLength, length);
        length = 0;
        unordered_map<char, bool> visited;

        int j = i;
        while(!visited.count(s[j])){
            visited[s[i]] = true;
            length++;
            j++;

            if(j >= n)  return max(maxLength, length);
        }

        i++;
    }

    return maxLength;
}

// sliding window approach : O(n)
int lengthOfLongestSubstring2(string str){
    int n = str.length();

    int ptr_1 = 0, ptr_2 = 0;

    unordered_map<char, bool> visited;

    int maxLen = 1;
    while(ptr_2 < n){
        if(ptr_1 == ptr_2){
            visited[str[ptr_2]] = true;
            ptr_2++;
        }
        else if(visited[str[ptr_2]]){
            maxLen = max(maxLen, ptr_2 - ptr_1);
            // length--;
            // visited[str[ptr_2]] = false;
            visited[str[ptr_1]] = false;
            ptr_1++;
        }
        else{
            // length++;
            visited[str[ptr_2]] = true;
            ptr_2++;
        }

        // cout << ptr_1 << " - " << ptr_2 << endl;
    }

    maxLen = max(maxLen, ptr_2 - ptr_1);
    return maxLen;
}

// efficient solution : O(n)
int lengthOfLongestSubstring3(string s) {
    vector<int> dict(256, -1);
    int maxLen = 0, start = -1;

    for(int i = 0; i < s.length(); i++){
        if(dict[s[i]] > start)
            start = dict[s[i]];

        dict[s[i]] = i;
        maxLen = max(maxLen, i - start);
    }

    return maxLen;
}

// driver funtion
int main(){
    // string str = "abcabcbb";
    // string str = "bbbbbb";
    string str = "dvdf";
    // string str = " ";

    cout << lengthOfLongestSubstring3(str) << endl;

    return 0;
}
