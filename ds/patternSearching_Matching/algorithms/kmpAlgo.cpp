// KMP Algorithm implemntation
#include <bits/stdc++.h>
using namespace std;

void computeLPSArray(string, vector<int>&);

bool KMPSearch(string pattern, string text){
    int m = pattern.length();
    int n = text.length();

    vector<int> lps(m,0);
    computeLPSArray(pattern, lps);      // computes all the equal prefixs and suffixes in the array

    int i = 0;      // index for text
    int j = 0;      // index for pattern

    bool patternFound = false;
    while(i < n){
        if(pattern[j] == text[i]){
            j++;
            i++;
        }

        if(j == m){
            cout << "found pattern at index : " << i-j << endl;
            patternFound = true;
            j = lps[j-1];
        }

        else if(i < n && pattern[j] != text[i]){
            if(j != 0)
                j = lps[j-1];
            else
                i++;
        }
    }

    return patternFound;
}

// compute lps[] for given pattern pat[0....M-1]
void computeLPSArray(string pat, vector<int> &lps){
    int n = pat.length();
    // lps[0] = 0;

    int i = 1;
    int j = 0;
    while(i < n){
        if(pat[i] == pat[j]){
            j++;
            lps[i] = j;
            i++;
        }
        else {
            if(j != 0){
                j = lps[j-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Driver function
int main(){
    string txt = "ABABDABACDABABCABAB";
    string pat = "ABABCABAB";

    cout << KMPSearch(pat, txt) << endl;

    return 0;
}
