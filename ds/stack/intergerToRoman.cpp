// 12. Integer to Roman
#include <bits/stdc++.h>
using namespace std;

// Method 1
// tc : O(n)
string intToRoman(int num) {
    string ans="";

    while(num > 0){

        // for num > 1000
        if(num >= 1000){
            int dv = num/1000;

            for(int i = 0; i < dv; i++)
                ans += "M";

            num %= 1000;
        }

        // for num  [500, 900)
        else if(num >= 500 && num < 1000){
            int dv = num/100;
            if(dv == 9){     // 900
                ans += "CM";
            }
            else {
                ans += 'D';     // 500

                // 600 - 800
                for(int i = 0; i < (dv%5); i++)
                    ans += 'C';
            }

            num %= 100;
        }

        // for num [100, 500)
        else if(num >= 100 && num < 500){
            int dv = num/100;

            if(dv == 4){
                ans += "CD";
            }

            // for 100 - 300
            else {
                for(int i = 0; i < dv; i++)
                    ans += 'C';
            }

            num %= 100;
        }

        // for [50, 100)
        else if(num >= 50 && num < 100){
            int dv = num/10;

            if(dv == 9){
                ans += "XC";
            }

            // for 50 - 80
            else {
                ans += 'L';

                for(int i = 0; i < (dv%5); i++)
                    ans += 'X';
            }

            num %= 10;
        }

        // for num [10, 50)
        else if(num >= 10 && num < 50){
            int dv = num/10;

            if(dv == 4){
                ans += "XL";
            }

            // for 10 - 30
            else {
                for(int i = 0; i < dv; i++)
                    ans += 'X';
            }

            num %= 10;
        }

        // for num [5, 10)
        else if(num >= 5 && num < 10){
            if(num == 9){
                ans += "IX";
            }

            // for 5 - 8
            else {
                ans +='V';
                for(int i =0; i < (num-5); i++){
                    ans += "I";
                }
            }

            num = 0;
        }

        // for 1 - 4
        else if(num < 5){
            if(num == 4){
                ans += "IV";
            }

            // for num 1 - 3
            else{
                for(int i = 0; i < num; i++)
                    ans += 'I';
            }
            num = 0;
        }
    }

    return ans;
}

// Method 2
string intToRomanII(int num) {
    string table[4][10] =
    {
        {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
        {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
        {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
        {"", "M", "MM", "MMM" }
    };

    string result;
    int count = 0;

    while(num > 0){
        int temp = num % 10;
        result = table[count][temp] + result;
        num /= 10;
        count++;
    }
    return result;
}

// Driver function
int main(){
    // int num = 48;
    // int num = 758;
    int num = 1994;

    cout << intToRoman(num) << endl;

    return 0;
}
