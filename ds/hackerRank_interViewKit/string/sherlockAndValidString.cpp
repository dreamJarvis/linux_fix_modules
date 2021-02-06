// sherlock and valid string
#include <bits/stdc++.h>
using namespace std;

string isValid(string s) {
    int n = s.size();
    unordered_map<char, int> freqCounter;
    unordered_map<int, int> freq;

    for(auto i:s){
        freqCounter[i]++;
    }

    for(auto i:freqCounter){
        freq[i.second]++;
    }

    set<pair<int, int>> st;
    for(auto i:freq){
        st.insert(make_pair(i.second, i.first));
    }

    // for(auto i:freqCounter)
    //     cout << i.first << " -- " << i.second << endl;
    // cout << endl;
    // for(auto i:freq)
    //     cout << i.first << " -- " << i.second << endl;
    // cout << endl;
    // for(auto i:st)
    //     cout << i.first << " -- " << i.second << endl;

    long mx = 0, mi=0;
    for(auto i:st){
        mx = i.first;
        mi = i.second;
    }

    cout << mx << ", " << mi << endl;

    int k = freq.size();
    if(k == 1)    return "YES";
    if(k > 2)   return "NO";

    // if(abs(freq[0] - freq[1]) > 1)   return "NO";
    for(auto i:freq){
        if(i.first != mi){
            if(i.second > 1 || (i.first > 1 && abs(i.first-mi) > 1) ){
                cout << i.second << ", " << i.first << ", " << abs(i.first-mi) << endl;
                return "NO";
            }
        }
    }

    return "YES";
}

// Driver function
int main(){
    string str = "aabbcd";

    cout << isValid(str) << endl;

    return 0;
}
/*
aabbcd
aaaabbcc, NO
abcdefghhgfedecba
aabbccddeefghi
aabbc

*/
