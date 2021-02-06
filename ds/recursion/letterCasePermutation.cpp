/*
    784. Letter Case Permutation
    https://leetcode.com/problems/letter-case-permutation/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(string S, vector<string> &result, int pos){
        if(pos == S.length()+1){
            return ;
        }

        // insert every permutation
        result.push_back(S);

        for(int i = pos; i < S.length(); i++){
            char ch = S[i];

            // for smaller-case
            if(ch >= 'a' && ch <= 'z'){
                char k = ch - 32;
                S[i] = k;
                helper(S, result, i+1);
                S[i] = ch;
            }

            // for larger-case
            else if(ch >= 'A' && ch <= 'Z'){
                char k = ch + 32;
                S[i] = k;
                helper(S, result, i+1);
                S[i] = ch;
            }
        }
    }

    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        string str="";
        helper(S, result, 0);
        return result;
    }
};

// Driver function
int main(){
    // string str = "a1b2";
    // string str = "3z4";
    string str = "1234";
    // string str = "C";

    Solution s;

    for(auto &i:s.letterCasePermutation(str)){
        cout << i <<endl;
    }

    return 0;
}
