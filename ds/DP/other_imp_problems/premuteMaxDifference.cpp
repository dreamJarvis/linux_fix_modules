#include <bits/stdc++.h>
using namespace std;

void permutations(string str, string ans, string &result){
    if(str.length() == 0){
        stringstream temp(ans);
        int x;
        temp >> x;

        // cout << x << endl;
        if(x%8 == 0){
            result = "YES";
            return;
        }
    }

    for(int i = 0; i < str.length(); i++){
        char ch = str[i];

        string restOfStrings = str.substr(0,i) + str.substr(i+1);
        permutations(restOfStrings, ans+ch, result);
    }
}

int main(){
    string str = "61";
    string result = "NO";
    permutations(str, "", result);

    cout << result << endl;

    return 0;
}