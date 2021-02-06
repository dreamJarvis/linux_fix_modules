// leetcode 1309. Decrypt String from Alphabet to Integer Mapping
#include <bits/stdc++.h>
using namespace std;

string freqAlphabets(string s) {
    int n = s.length();

    string result="";
    int i = n-1;
    while(i >= 0){
        char temp = s[i];

        if(temp == '#'){
            int a = s[i-2] - '0';
            int b = s[i-1] - '0';
            int sum = a*10+b-1;
            result += ('a' + sum);

            i-=3;
            continue;
        }

        int index = s[i] - '0';
        if(index >= 1 && index <= 9){
            result+= ('a' + index-1);
        }

        i--;
    }

    reverse(result.begin(), result.end());
    return result;
}

// driver function
int main(){
    // string str = "10#11#12";
    string str = "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#";

    cout << freqAlphabets(str) << endl;

    return 0;
}
