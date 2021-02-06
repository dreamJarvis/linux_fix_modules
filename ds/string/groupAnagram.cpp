// leetcode : 49
// group anagram
#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs){
    // agr hm notice kre, toh hme pta chalega ki jo anagrams ho, chage unke words kisi bhi order me ho, lekin sort krne pr ek he word bayenge, kyuki they contain similar words
    // toh hme hr wo word jo sort hone pr similar word dega unhe ek sath store kr lete h

    // key : store srega hr anagram ka sorted version
    // value : store krega different anagrams
    unordered_map<string, vector<string>> m;

    // toh hm given array ke hr word pr jayenge , phir ussko sort krke dekhnege ki wo kiss anagram ko belong krta h, and usse uss anagram ki list me store kr denge
    for (auto s: strs){
        string sorted = s;
        sort(sorted.begin(), sorted.end());
        m[sorted].push_back(s);
    }

    // we will only sore the list of differnet anagrams made
    vector<vector<string>> grouped;
    for (auto &kv: m) {
        grouped.push_back(kv.second);
    }

    return grouped;
}

// Driver function
int main(){
    vector<string> str({"eat", "tea", "tan", "ate", "nat", "bat", "cat", "tac"});
    // vector<string> str({"","b",""});
    // vector<string> str({""});

    for(auto value:groupAnagrams(str)){
        for(auto items:value)
            cout << items << " ";
        cout << endl;
    }

    return 0;
}
