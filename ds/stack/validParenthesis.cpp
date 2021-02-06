// 1249. Minimum Remove to Make Valid Parentheses
#include <bits/stdc++.h>
using namespace std;

/*
Runtime: 108 ms, faster than 30.90%
Memory Usage: 13.7 MB, less than 8.50%
*/
// tc : 2*O(n)
string minRemoveToMakeValid(string s) {
    int n = s.size();

    stack<int> open;
    stack<int> close;
    vector<int> del(n,0);

    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            // del[i] = -1;
            open.push(i);
        }
        else if(s[i] == ')' && !open.empty()){
            // del[open.top()] = 0;
            // cout << i << ", " << open.top() << endl;
            open.pop();
        }
        else if(s[i] == ')' && open.empty()){
            // del[i] = -1;
            // cout << i << endl;
            close.push(i);
        }
    }

    string result="";
    for(int i = n-1; i >= 0; i--){
        if(!open.empty() && i == open.top())
            open.pop();
        else if(!close.empty() && i == close.top())
            close.pop();
        else
            result += s[i];
    }

    reverse(result.begin(), result.end());
    return result;
}

/*
*/
string minRemoveToMakeValidII(string s) {
    if(s.size()==0 || s=="()")
        return s;

    int n = s.size();
    stack<int> st;
    for(int i = 0; i < n; i++){
        if(s[i]>='a' && s[i] <='z')
            continue;

        if(s[i] == '('){
            st.push(i);
        }
        else{
            if(!st.empty()){
                st.pop();
            }
            else {
                s[i] = '@';
            }
        }
    }

    while(!st.empty()){
        s[st.top()] = '@';
        st.pop();
    }

    string result="";
    for(int i = 0; i < n; i++){
        if(s[i] != '@')
            result += s[i];
    }

    return result;
}

// Driver function
int main(){
    // string str = "lee(t(c)o)de)";
    // string str = "a)b(c)d";
    // string str = "(a(b(c)d)";
    string str = "))((";


    cout << minRemoveToMakeValidII(str) << endl;

    return 0;
}
