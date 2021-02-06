#include <bits/stdc++.h>
using namespace std;

void permute(string str, int pos){
    if(pos == str.length()){
        cout << str << endl;
        return ;
    }

    for(int i = pos; i < str.length(); i++){
        char ch = str[i];
        swap(str[i], str[pos]);
        permute(str, pos+1);
        swap(str[i], str[pos]);             // using backtracking
    }
}

// Driver function
int main(){
    string str = "abc";

    permute(str, 0);

    return 0;
}
