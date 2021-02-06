// Backspace String Compare
#include <bits/stdc++.h>
using namespace std;

// time complexity : O(N)
// space complexity : O(N)
string backspaceStringCompare(string s){
    int len1 = s.length();

    // backspacing string 1
    stack<char> st;
    // st.push(s[0]);

    int index = 0;
    char ch;
    while(index <= len1){
        ch = s[index];

        if(ch == '#'){
            if(!st.empty()) st.pop();
        }else{
            st.push(ch);
        }

        index++;
    }

    // after backspacing an empty text, the text will continue empty.
    if(index == len1 && ch=='#')
        return "";

    string result="";
    while(!st.empty()){
        // char ch = ;
        result += st.top();
        st.pop();
    }

    return result;
}

bool backspaceStringCompareUTIL(string s, string t){
    string tempS = backspaceStringCompare(s);
    string tempT = backspaceStringCompare(t);

    // cout << tempS << "\t, " << tempT << endl;

    return tempS == tempT ? 1 : 0;
}

// time complexity : O(N)
// space complexity : O(1)
bool backspaceStringCompare2(string s, string t){
    int k = 0, p = 0;
    while(p <= s.length()){
        if(s[p] == '#'){
            k--;
            k = max(0, k);
        }
        else{
            s[k] = s[p];
            k++;
        }
        p++;
    }


}

// time complexity : O(N)
// space complexity : O(1)
// using 2 pointer method
bool backspaceStringCompare2(string s, string t){

    // jaha jaha pr hme '#' milega , waha waha pr hm k ko decrement kr denge (k--)
    int k=0, p = 0;
    while(p <= s.length()){
        if(s[p] == '#'){
            k--;
            k = max(0, k);
        }
        else{
            s[k] = s[p];
            k++;
        }
        p++;
    }

    int j=0;
    p = 0;
    while(p <= t.length()){
        if(t[p] == '#'){
            j--;
            j = max(0, j);
        }
        else{
            t[j] = t[p];
            j++;
        }
        p++;
    }

    if(k != j)  return false;

    while(k--){
        if(s[k] != t[k])    return false;
    }

    return true;
}

// Driver function
int main(){
    string s = "a#c";
    string t = "b";

    cout << backspaceStringCompareUTIL(s, t) << endl;

    return 0;
}
