// leetcode 22. Generate Parentheses
// link for vedio turotial : https://www.youtube.com/watch?v=sz1qaKt0KGQ&t=618s
#include <bits/stdc++.h>
using namespace std;

// solution 1
void generate(int n, int l, int r, string paren, vector<string>& parens){
    if(l == n && r == n){
        // if(isValid(paren))
        parens.push_back(paren);
    }
    else {
        if(l < n)
            generate(n, l+1, r, paren+'(', parens);
        if(r < l)
            generate(n, l, r+1, paren+')', parens);
    }
}

vector<string> generateParenthesis(int n){
    vector<string> parens;
    string paren;

    generate(n, 0, 0, paren, parens);
    return parens;
}

// solution 2
vector<string> generateParenthesis2(int n){
    if(!n){
        return {""};
    }

    vector<string> parens;
    for(int i = 0; i < n; i++){
        for(string l: generateParenthesis2(i)){
            for(string r: generateParenthesis2(n- 1- i)){
                cout << "left : " << l << "\t, right : " << r << ", n : " << n << endl;

                parens.push_back('(' + l + ')' + r);
            }
        }
    }

    return parens;
}

// Driver Function
int main(){
    int n = 3;

    for(auto i:generateParenthesis(n))
        cout << i << endl;

    return 0;
}
