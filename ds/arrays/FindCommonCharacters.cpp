// 1002. Find Common Characters
#include <bits/stdc++.h>
using namespace std;

vector<string> commonChars(vector<string>& A) {
    vector<string> result;

    int freq[27] = {0};
    for(auto &i:A[0])
        freq[i-'a']++;

    for(int i = 1; i < A.size(); i++){
        int temp[27] = {0};

        for(auto &j:A[i])
            temp[j-'a']++;

        for(int i = 0; i < 27; i++){
            freq[i] = min(freq[i], temp[i]);
        }
    }

    for(int i = 0; i < 27; i++){
        string ch="";
        ch += (i+'a');

        for(int j = 0; j < freq[i]; j++){
            result.push_back(ch);
        }
    }

    return result;
}

// Driver function
int main(){
    // fast I/O
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // vector<string> arr({"bella","label","roller"});
    vector<string> arr({"cool", "lock", "cook"});

    for(auto i:commonChars(arr))
        cout << i << " ";
    cout << endl;

    return 0;
}
/*
"cat","bt","hat","tree"
"atach"

words = ["hello","world","leetcode"], chars = "welldonehoneyr"
*/
