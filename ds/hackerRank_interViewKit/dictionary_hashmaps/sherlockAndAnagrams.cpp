// hackerRank : sherlock and Anagrams
// solution : https://medium.com/@carlosbf/sherlock-and-anagrams-solution-6ed20bf7c815
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

// Method : 1

unordered_map<char, int> primes_map;    // maps each carecter from 'a'-'z' with prime no.
void init_primes();                     // initializes the charecters with prime no.

/*
    First step :

    First counting all occurrences anagrammatic substrings, there are
    (n *(n-1)/2) -1 substrings in any string of length n,
    we can use 2 for loops to get the substrings of all lengths.
    Now to count them we can assign a unique key to each substring such that the same value is returned for any anagrammatic string. We can achieve that by assigning a prime integer to each ascii character and multiplying the values. The result modulo some large prime integer will be our unique key. For each occurrence of this key we add one in an unordered map. After this we have an unordered map with the number of occurrences of all substrings.

    Second step :

    Second we can iterate in this unordered map and count the number of pairs that can be formed with the anagrammatic strings that occur at least twice. We can count the pairs of k anagrammatic occurrences of a string with the formula:
    k*(k-1)/2 . We do this for all entries with at least 2 occurrences and add the result.
*/
int sherlockAndAnagrams(string s){
    int n;
    long key;
    int result;
    const char *s_chars;
    unordered_map<long, int> map;

    result = 0;
    n = s.size();
    init_primes();      // assinging prime numbers to all the charectres from a - z
    s_chars = s.c_str();    // returns a pointer to an array that contains a null-terminated sequence of charecters representing the current value of basic_string object

    // considering each sub-string of every length
    for(int len = 1; len <= n; len++){
        for(int i = 0; i <= n - len; i++){
            int j = i + len - 1;            // length of the sub-string
            key = 1;                        // initializing key with 1

            /*
            it provides us with the unique key for every substring
            and substrings with same charecters with euqal frequency will result in having the same key,
            thus incrementing those substrings value which have same charecters with same frequency

            here we obtain the prime number mapped to every charecter and multiply them together so that we get a unique number, but because this number will grow with the length of substring, .'. we have to contain it with applying modulus

            and beause anagramaticall substring wil have same charecter same number of time , their multiplication will also be same, thus the key made will be same to
            */
            for(int k = i; k <= j; k++){
                key = (primes_map[s_chars[k]] * key) % MOD;
            }

            map[key]+=1;
        }
    }

    /*

    now all those substring(or those substrings with same charecters with same frequency) whose frequency is >= 2, in those cases, now because we have to find the pair, and the
    the frequency tells the no of substrings that are available,

    so if we are given k choices and we can only choose 2, how many choices can we make ?
    by applying mathematical combination, nCr i.e kC2 = k*(k-1)/2 choices

    so we will have k*(k-1)/2 substrings pairs if we have k substrings of idetical charecters and frequency
    */
    for(auto i:map){
        int val = i.second;
        if(val >= 2)
            result += (val*(val-1)/2);
    }

    return result;
}

// Helper function
// it proves each
void init_primes(){
    primes_map['a']= 2;
    primes_map['b']= 3;
    primes_map['c']= 5;
    primes_map['d']= 7;
    primes_map['e']= 11;
    primes_map['f']= 13;
    primes_map['g']= 17;
    primes_map['h']= 19;
    primes_map['i']= 23;
    primes_map['j']= 29;
    primes_map['k']= 31;
    primes_map['l']= 37;
    primes_map['m']= 41;
    primes_map['n']= 43;
    primes_map['o']= 47;
    primes_map['p']= 53;
    primes_map['q']= 59;
    primes_map['r']= 61;
    primes_map['s']= 67;
    primes_map['t']= 71;
    primes_map['u']= 73;
    primes_map['v']= 79;
    primes_map['w']= 83;
    primes_map['x']= 89;
    primes_map['y']= 97;
    primes_map['z']= 101;
}

// Method 2 : by sorting and searching
int anagram(string str){
    int n = str.size();

    int countOfAnagrams = 0;
    int len = 1;

    for(int i = 0; i < str.size()-1; i++){
        vector<string> substrings(0);

        for(int j = 0; j < str.size()-i; j++){
            string temp = str.substr(j, len);
            sort(temp.begin(), temp.end());
            substrings.push_back(temp);
        }

        for(int x = 0; x < substrings.size(); x++){
            for(int y = x+1; y < substrings.size(); y++){
                if(substrings[x] == substrings[y])  countOfAnagrams++;
            }
        }

        len++;
    }

    return countOfAnagrams;
}

// Driver function
int main(){
    string s = "cdcd";
    // cout << sherlockAndAnagrams(s) << endl;
    cout << anagram(s) << endl;
    return 0;
}
