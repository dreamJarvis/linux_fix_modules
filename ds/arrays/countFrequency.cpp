// print unique elements in an array
#include <bits/stdc++.h>
using namespace std;

// Driver function
int main(){ 
    // hello my name hello my my asdf hgftb name exit
    string str;
    vector<string> words;
    unordered_map<string, int> h;                     // can be done better by sets

    // inserting words
    cin >> str;
    while(str != "exit"){
        words.push_back(str);
        cin >> str;
    }

    // counting thefrequencies
    for(auto val : words){
        if(h.count(val))
            h[val] += 1;
        else
            h[val] = 1;
    }

    // printing the unique values
    cout << "\n\n";
    for(auto i : h)
        cout << i.first << " --> " << i.second << endl;

    return 0;
}