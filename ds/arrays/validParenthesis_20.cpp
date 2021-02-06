// leetcode : 20
#include <bits/stdc++.h>
using namespace std;

// tc : O(n)
// sc : O(n/2)
bool isValid(string str) {
    stack<char> s;

    for(auto i:str){
        if(i=='(' || i=='{' || i=='[')
            s.push(i);
        else {
            if(s.empty())  return false;
            if( (i == ')' && s.top() == '(') || (i == '}' && s.top() == '{') || (i == ']' && s.top() == '[') )
                s.pop();
            else return false;
        }
    }

    return s.empty();
}

// Driver function
int main(){
    // string str = "({[]})[]{}";
    string str = "({[})";
    cout << isValid(str) << endl;
    return 0;
}
