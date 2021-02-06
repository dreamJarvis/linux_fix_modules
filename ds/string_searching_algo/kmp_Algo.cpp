// implementation of KMP algorithm
#include <bits/stdc++.h>
using namespace std;

void computeLPSArray(char *par, int M, int *lps);

// prints occurences of txt[] in pat[]
void KMPSearch(char *pat, char *txt){
    int M = strlen(pat);
    int N = strlen(txt);

    // create lps[] that will hold the longest prefix suffix values for pattern
    int lps[M];

    // preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0;  //  index for txt[]
    int j = 0;  //  index for pat[]

    while(i < N){
        if(pat[j] == txt[i]){
            j++;
            i++;
        }

        if(j == M){
            cout << "pattern found at index : " << i-j << endl;     // i - M
            j = lps[j - 1];
        }

        // mismatch after j matches
        else if(i < N && pat[j] != txt[i]){
            // do not match lps[0...lps[j-1]] charecters, they will match anyway
            if(j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
}


// fiils the length of all the suffix == prefix substrings
void computeLPSArray(char *pat, int M, int *lps){
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0;     //  lps[0] is always 0

    // the loop calculates lip[i] for i = 1 to M-1
    int i = 1;
    while(i < M){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else {              //  (pat[i] != pat[len])
            if(len != 0)
                len = lps[len - 1];
            else{           //  if len == 0
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Driver function
int main(){
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";

    KMPSearch(pat, txt);

    return 0;
}
