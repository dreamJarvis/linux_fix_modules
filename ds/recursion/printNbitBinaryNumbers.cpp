/*
    Print N-bit binary numbers having more 1s than 0s
    https://practice.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1
*/
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void helper(string str, int bit1, int bit0, vector<string> &result, int N){
        // base case
        if(bit0 > N/2 || bit1 > N){
            return;
        }

        if(str.length() == N){
            result.push_back(str);
            return ;
        }

        helper(str+'1', bit1+1, bit0, result, N);

        // no. of 0's should be less than no. of 1's in the prefix
        if(bit1 && bit0 < bit1)
            helper(str+'0', bit1, bit0+1, result, N);
    }

	vector<string> NBitBinary(int N){
        vector<string> result;
        string str="";

        helper(str, 0, 0, result, N);

        return result;
	}
};

// Driver function
int main(){
    int n = 4;

    Solution s;
    for(auto &i:s.NBitBinary(n))
        cout << i << " ";
    cout << endl;

    return 0;
}
