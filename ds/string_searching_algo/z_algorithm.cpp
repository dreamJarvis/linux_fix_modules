// z algorithm implementation
#include <bits/stdc++.h>
using namespace std;

// to fill array for given string str[]
vector<int> constructSuffixArray(string str){
    int n = str.length();

    // to store the suffix length of every charecter amtching with prefix
    vector<int> lps(n, 0);
    int left, right, k;

    // [left, right] make a window which mathes with prefix of s
    left = right = 0;

    for(int i = 0; i < n; i++){
        // if i > R nothing matches so we will calculate lps[i] using naive way
        if(i > right){
            left = right = i;

            // right - left in starting, so it will start checking from 0'th index
            while(right < n && str[right - left] == str[right])
                right++;

            lps[i] = right - left;
            right--;
        }
        else{
            // k = i-left so k corresponds to number which matches in [left, right] interval
            k = i - left;

            // if lps[k] is less then remaining interval then lps[i] will be equal to lps[k],
            if(lps[k] < right - i + 1)
                lps[i] = lps[k];

            // ex str = "aaaaaa" and i = 2, R is 5, L is 0
            else{
                left = i;
                while(right < n && str[right - left] == str[right])
                    right++;

                lps[i] = right - left;
                right--;
            }
        }
    }

    return lps;
}

void search(string text, string pattern){
    string concat = pattern + "$" + text;
    int l = concat.length();

    // construct Z array
    vector<int> lps;
    lps = constructSuffixArray(concat);

    // now looping through lps array for matching condition
    for(int i = 0; i < l; i++)
        //if lps[i] (matched region) is qual to pattern length we got the pattern
        if(lps[i] == pattern.length())
            cout << "Pattern found at index " << i - pattern.length() - 1 << endl;
}

// Driver function
int main(){
    string text = "GEEKS FOR GEEKS";
	string pattern = "GEEK";

    search(text, pattern);

    return 0;
}
