#include <bits/stdc++.h>
using namespace std;

string subwaySystem(string str1, string str2){
    int n = str1.length();
    int str1Count = 0;
    int str2Count = 0;

    for(int i = 0; i < n; i++){
        if(str1[i]=='1')
            str1Count++;
        else if(str1[i]=='0')
            str1Count--;

        if(str2[i]=='1')
            str2Count++;
        else if(str2[i]=='0')
            str2Count--;
    }

    if(str1Count == str2Count)
        return "same";
    return "different";
}

// Driver frunction
int main(){
    string str1 = "0100101100100111";
    string str2 = "0011000111010101";

    cout << subwaySystem(str1, str2) << endl;

    return 0;
}
/*
0010011101001011
0100011011001011
0100101100100111
0011000111010101
*/
