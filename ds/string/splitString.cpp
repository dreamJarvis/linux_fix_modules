// leetcode : 1221
#include <bits/stdc++.h>
using namespace std;

int balancedStringSplit(string s) {
    int lCount = 0, rCount = 0;

    int i = 0;
    int count = 0;
    while(i < s.length()){
        if(lCount && rCount && lCount == rCount){
            count++;
            lCount = 0;
            rCount = 0;
            cout << i << endl;
        }
        if(s[i]=='L')  lCount++;
        if(s[i]=='R')  rCount++;
        i++;
    }

    if(lCount && rCount && lCount == rCount)
        count++;

    return count;
}

// Driver function
int main(){
    string str = "RLLLLRRRLR";

    cout << balancedStringSplit(str) << endl;

    return 0;
}
