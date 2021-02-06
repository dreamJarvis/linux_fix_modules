#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t){
    int sl=s.length();
    int tl=t.length();

    if(sl != tl)    return false;

    int alp[26]={0};

    for(int i=0; i<sl;i++)  alp[s[i]-'a']++;

    for(int j=0; j< tl; j++){
        if(!alp[t[j]-'a'])
            return false;

        alp[t[j]-'a']--;
    }

    for(int i=0;i<26;i++)
        if(alp[i])
            return false;

    return true;
};

static const auto speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
};

// Driver function
int main(){
    string s1 = "acavva";
    string s2 = "vavaac";

    cout << isAnagram(s1, s2) << endl;
    return 0;
}
