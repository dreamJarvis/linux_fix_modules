/*
    22. Generate Parentheses
    https://leetcode.com/problems/generate-parentheses/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
        l --> no. of left bracket's in our string
        r --> no. of right bracket's in our string
    */
    void helper(string str, int n, int l, int r, vector<string> &result){
        if(l < 0 || r < 0)
            return ;

        if(l == 0 && r == 0){
            result.push_back(str);
            return ;
        }

        if(l > 0){
            helper(str+'(', n, l-1, r, result);
        }

        /*
        this line means, that we should have more open brackets then the close ones,
        in our string, at any given time, in order to generate vaid parentheses string

        if we dont have open brackets, then we cannot include close brackets yet
        the below condition states that,
        the no. of close brackets >  no. of open brackets,
        it just tell's us that we have an open bracket to close
        */
        if(r > l){
            helper(str+')', n, l, r-1, result);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string str = "";

        helper(str, n, n, n, result);
        return result;
    }
};

// Driver function
int main(){
    int n = 3;

    Solution s;
    for(auto i:s.generateParenthesis(n))
        cout << i << endl;

    return 0;
}
