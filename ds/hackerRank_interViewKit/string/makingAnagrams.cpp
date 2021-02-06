#include <bits/stdc++.h>
using namespace std;

int makeAnagram(string a, string b) {
    int str1[27] = {0};
    int str2[27] = {0};

    for(auto i: a)
        str1[i-'a']++;

    for(auto i:b)
        str2[i-'a']++;

    int deletions = 0;
    for(int i = 0; i < 27; i++){
       str1[i] = abs(str1[i] - str2[i]);
    }

    for(int i = 0; i < 27; i++){
        if(str1[i] != 0)
            deletions += str1[i];
    }

    return deletions;
}

// Driver function
int main(){
    string a = "cde";
    string b = "abc";

    cout << makeAnagram(a, b) << endl;

    return 0;
}
