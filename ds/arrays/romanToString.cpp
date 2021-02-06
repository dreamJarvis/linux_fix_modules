// leetcode : 13 Roman to integer
#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
    int result = 0;
    for(int i = 0; i < s.size(); i++){
        switch(s[i]){
            case 'I':
                if(s[i + 1] == 'V')
                {
                    result += 4;
                    i++;
                    break;
                }
                if(s[i + 1] == 'X')
                {
                    result += 9;
                    i++;
                    break;
                }
                result += 1;
                break;

            case 'V':
                result += 5;
                break;

            case 'X':
                if(s[i + 1] == 'L')
                {
                    result += 40;
                    i++;
                    break;
                }
                if(s[i + 1] == 'C')
                {
                    result += 90;
                    i++;
                    break;
                }
                result += 10;
                break;

            case 'L':
                result += 50;
                break;

            case 'C':
                if(s[i + 1] == 'D')
                {
                    result += 400;
                    i++;
                    break;
                }
                if(s[i + 1] == 'M')
                {
                    result += 900;
                    i++;
                    break;
                }
                result += 100;
                break;

            case 'D':
                result += 500;
                break;

            case 'M':
                result += 1000;
                break;
        }
    }
    return result;
}

// Driver function
int main(){
    string str = "MCMXCIV";
    cout << romanToInt(str) << endl;
    return 0;
}
