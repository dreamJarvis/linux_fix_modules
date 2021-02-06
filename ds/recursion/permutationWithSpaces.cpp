/*
    Permutation with Spaces
    https://practice.geeksforgeeks.org/problems/permutation-with-spaces/0
*/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

void helper(string str, string ans, int index, set<string> &st){
    if(str.length() == 0){
        string temp = "("+ans+")";
        st.insert(temp);
        return;
    }

    char ch = str[0];
    str.erase(str.begin());

    string temp = ans;
    temp += " ";

    helper(str, ans+=ch, index+=1, st);
    helper(str, temp+=ch, index+=1, st);
}

void placingSpaces(string str){
    string ans = "";
    set<string> st;
    ans += str[0];
    helper(str.substr(1), ans, 1, st);

    for(auto i:st)
        cout << i;
    cout << endl;
}

int main(){
	//code
	int tc;
	cin >> tc;

	while(tc--){
	    string str;
	    cin >> str;

	    placingSpaces(str);
	}

	return 0;
}
