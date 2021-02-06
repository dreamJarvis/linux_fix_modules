#include <bits/stdc++.h>
using namespace std;

vector<int> commonPrefix(string str){
    int n = str.length();

    vector<int> prefixes;
    prefixes.push_back(n);

    string prefix = "", suffix = "";
    prefix = str.substr(0,1);
    suffix = str.substr(1);

    for(int i = 1; i < n; i++){
        if(prefix == suffix.substr(0, prefix.length()))
            prefixes.push_back(prefix.length());

        prefix += str[i];
        suffix = suffix.substr(1);
    }

    return prefixes;
}

// Driver function
int main(){
    string str = "abcabcd";

    vector<int> result = commonPrefix(str);
    int sum = 0;
    for(auto i:result)
        sum += i;

    cout << sum << endl;

    return 0;
}
