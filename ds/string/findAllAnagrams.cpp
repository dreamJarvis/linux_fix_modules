// leetcode : 438.
// Find All Anagrams in a String
#include <bits/stdc++.h>
using namespace std;

// finding all anagrams
vector<int> findAnagrams(string s, string p) {
    if(p.size() > s.size()) return vector<int>();

    vector<int> result;

    // kyuki there are 26 alphbets, and hmare string alphabets se bne h, so hm hr element ki frequency string s and p me jitni h, ussko save kr lenge in arrays
    int pLetters[26] = {0};     // stores the frequency of charecters in string p
    int sLetters[26] = {0};     // stores the frequency of charecters in string s

    int pSize = p.size();       // size of smaller string

    // string s, p me hr charecter ki frequency store kr rhe h, but kyuki hme p ka anagram check krna h, toh hm ek time pr string s se p length ki string lenge, and uss p length me chk krenge ki anagram h ki nhi
    for(int i = 0; i < pSize; i++){
        pLetters[p[i] - 'a']++;
        sLetters[s[i] - 'a']++;
    }

    // string s me chk krna ki kitne anagram bn skte h
    int sSize = s.size();
    int i = 0;
    while(true){
        int j = 0;
        // checks if anagrams exist or not, for this size of s string , which starts from i
        for(j = 0; j < 26; ++j){
            if(sLetters[j] != pLetters[j])  break;
        }

        // if j == 26, it means we iterated the whole container array, that means every single charecter matched , so anagram exists at ith index
        if(j == 26) result.push_back(i);

        // if we reached the end of string s
        if(i == sSize - pSize)  break;

        // we are using window sliding technique here, so we have checked if we get an anagram starting from i'th index, now we have to check if the anagram exists for next i'th index, for the same string p, .'. we will remove the i'th index element and insert element present at (i+p)'th index, the elements in the middle remain same, we are just removing elements from the start, and adding it from the end
        sLetters[s[i]-'a']--;
        sLetters[s[i + pSize] - 'a']++;
        i++;
    }

    return result;
}

// Driver function
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    // string s = "cbaebabacd";
    // string p = "abc";

    string s = "abab";
    string p = "ab";

    for(auto index:findAnagrams(s, p))
        cout << index << " ";
    cout << endl;

    return 0;
}
/*
"cbaebabacd"
"abc"

"abab"
"ab"
*/
