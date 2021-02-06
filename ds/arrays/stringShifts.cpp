// leetcode 30 day challange : day 14
#include <bits/stdc++.h>
using namespace std;

// solution 1
string stringRotation(string s, vector<vector<int>>& rotation) {
    int n = s.length();
    for(auto & r : rotation) {
        int d = r[0], cnt = r[1] % n;
        if (d == 0) rotate(s.begin(), s.begin() + cnt, s.end());
        else rotate(s.begin(), s.begin() + n - cnt, s.end());
    }

    return s;
}

// solution 2
// time complexity : O(N)
// space complexity : O(N)
string stringShift2(string s,  vector<vector<int>>& rotation){
    int val = 0;

    for(auto item:rotation)
        val += (item[0] == 0) ? -item[1] : item[1];

    int len = s.length();
    val %= len;

    string result="";

    // right rotations
    if(val > 0) result = s.substr(len-val, val) + s.substr(0, len-val);
    // left rotations
    else        result = s.substr(-val, len+val) + s.substr(0, -val);

    return result;
}

// Driver function
int main(){
    string s = "abcdefg";
    vector<vector<int>> matrix{{1,1}, {1,1}, {0,2}, {1,3}};

    string result = stringShift2(s, matrix);
    cout << result << endl;

    return 0;
}
