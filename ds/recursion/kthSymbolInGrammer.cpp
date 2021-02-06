/*
    779. K-th Symbol in Grammar
    https://leetcode.com/problems/k-th-symbol-in-grammar/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int kthGrammar(int N, int K) {
        // base case
        if(N==1 && K==1)
            return 0;

        // hypothesis and induction
        int mid = pow(2, N-1)/2;
        if(K <= mid)
            return (kthGrammar(N-1, K));
        return (!kthGrammar(N-1, K-mid));
    }
};

// Driver function
int main(){
    int N = 4, K = 5;

    Solution s;
    cout << s.kthGrammar(N, K) << endl;
    return 0;
}
