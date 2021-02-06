// 567. Permutation in String
#include <bits/stdc++.h>
using namespace std;

// 12ms
bool checkInclusion(string s1, string s2) {
    int len1 = s1.length();
    int len2 = s2.length();

    if(len1 > len2) return false;

    // counts the frequency of every charecter in s1
    int freqCount[26] = {0};
    int tempCount[26] = {0};
    for(auto i:s1)  freqCount[i-'a']++;

    int counter = 0;
    for(int i = 0; i < len1; i++){
        int k = s2[i]-'a';
        if(freqCount[k]){
            tempCount[k]++;
            if(tempCount[k] <= freqCount[k])
                counter++;
        }
    }
    if(counter >= len1) return true;


    int i = 1, j = len1;
    while(j < len2){
        if(counter >= len1)
            return true;

        int k = s2[i-1]-'a';
        if(freqCount[k]){
            tempCount[k]--;
            if(tempCount[k] < freqCount[k])
                counter--;
        }

        k = s2[j]-'a';
        if(freqCount[k]){
            if(tempCount[k] < freqCount[k])
                counter++;
            tempCount[k]++;
        }

        i++;
        j++;
    }
    if(counter >= len1) return true;

    return false;
}

// 20ms
bool checkInclusionI(string s1, string s2){
    if(s1.size() > s2.size())   return false;

    vector<int> requiredCount(26,0);
    vector<int> totalCount(26,0);

    int i = 0;
    for(; i < s1.size(); i++){
        ++requiredCount[s1[i]-'a'];
        ++totalCount[s2[i]-'a'];
    }

    if(requiredCount == totalCount) return true;

    for(; i < s2.size(); i++){
        --totalCount[s2[i - s1.size()] - 'a'];
        ++totalCount[s2[i] - 'a'];

        if(totalCount == requiredCount) return true;
    }

    return false;
}

// 12ms
bool checkInclusionUTIL(int s1map[],int s2map[]){
    for(int i=0;i<26;i++)
        if(s1map[i]!=s2map[i])
            return false;
    return true;
}

bool checkInclusionII(string s1, string s2) {
    if(s2.length()<s1.length())
        return false;

    int i,s1map[26],s2map[26];

    memset(s1map,0,sizeof(s1map));
    memset(s2map,0,sizeof(s2map));

    for(i=0;i<s1.length();i++)
        s1map[s1[i]-'a']+=1;

    for(i=0;i<s1.length();i++)
        s2map[s2[i]-'a']+=1;

    if(checkInclusionUTIL(s1map,s2map))
        return true;

    i=0;
    while(i<(s2.length()-s1.length())){
        s2map[s2[i]-'a']-=1;
        s2map[s2[i+s1.length()]-'a']+=1;

        if(checkInclusionUTIL(s1map,s2map))
            return true;
        i++;
    }

    return false;
}

// Driver function
int main(){
    // string s1 = "ab";
    // string s2 = "eidboaoo";
    string s1 = "adc";
    string s2 = "dcda";
    // string s1 = "abcd";
    // string s2 = "abeabdfgabcd";

    cout << checkInclusion(s1, s2) << endl;

    return 0;
}
/*
"adc"
"dcda"

"ab"
"eidboaoo"
*/
