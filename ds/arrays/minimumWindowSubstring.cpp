// 76. Minimum Window Substring
#include <bits/stdc++.h>
using namespace std;

// brute force solution
// time complexity : O(n^2)
string minWindow(string str, string t){
    int len1 = str.length();
    int len2 = t.length();

    unordered_map<char, int> totalChar;
    for(auto i:t)
        totalChar[i]++;

    int minLen = INT_MAX, index = 0;
    for(int i = 0; i < len1; i++){

        unordered_map<char, int> temp;

        for(int j = i; j < len1; j++){

            if(totalChar.count(str[j])){
                if(temp.count(str[j]))
                    temp[str[j]]++;
                else
                    temp[str[j]] = 1;
            }

            bool flag = true;
            for(auto k:totalChar){
                if(temp[k.first] < k.second){
                    flag = false;
                    break;
                }
            }

            // agr hme t mil gaya i -- j ki beech me
            if(flag){
                if(minLen > (j-i+1)){
                    minLen = j-i+1;
                    index = i;
                }
            }
        }
    }

    return minLen <= len1 ? str.substr(index, minLen) : "";
}


// **********  optimised solution ************** //
// time complexity : O(n+m)
// space complexity : O(m)
// 16ms
string minWindowOptimised(string str, string text){
    if(str.empty() || text.empty()) return "";

    int totalFreq[256] = {0};           // tells the frequency of every charecter
    int window[256] = {0};              // counts the frequency

    for(auto i:text) totalFreq[i]++;    // counting freq of each charecter

    int minLength = INT_MAX;
    int index = 0;
    int letterCounter = 0;

    for(int slow=0, fast=0; fast < str.length(); fast++){
        if(totalFreq[str[fast]]){
            window[str[fast]]++;
            if(window[str[fast]] <= totalFreq[str[fast]])
                letterCounter++;
        }

        while(letterCounter >= text.length()){
            if(totalFreq[str[slow]]){
                window[str[slow]]--;
                if(window[str[slow]] < totalFreq[str[slow]]){
                    letterCounter--;
                }
            }

            if(fast - slow + 1 < minLength){
                minLength = fast - slow + 1;
                index = slow;
            }

            slow++;
        }
    }

    return minLength <= str.length() ? str.substr(index, minLength) : "";
}

// 16ms
string minWindowOptimisedII(string s, string t) {
    vector<int> count(128,0);
    for(char c:t)   count[c]++;

    int remain = t.size();
    int left = 0, right = 0, minStart = 0, minLen = INT_MAX;

    while(right < s.size()) {
        // count[s[right]]--;
        if(--count[s[right++]] >= 0) remain--;
        // right++;
        while(remain == 0){
            if(right - left < minLen){
                minStart = left;
                minLen = right - left;
            }
            // count[s[left]]++;
            if(++count[s[left++]] > 0) remain++;
            // left++;
        }
    }
    return minLen < INT_MAX ? s.substr(minStart, minLen) : "";
}

// Driver function
int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << minWindowOptimised(s, t) << endl;

    return 0;
}
