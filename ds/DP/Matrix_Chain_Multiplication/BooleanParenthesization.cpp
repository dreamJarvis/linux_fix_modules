/*
    Boolean Parenthesization
    https://practice.geeksforgeeks.org/problems/boolean-parenthesization/0

    725. Boolean Parenthesization (without mod = 1003)
    https://www.lintcode.com/problem/boolean-parenthesization/description

    https://www.youtube.com/watch?v=JbRsM2X2_pg
*/
#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

#define MOD 1003

// Memoisation : Bottom up
int util(string str, int i, int j, bool isTrue, unordered_map<string, int> &dp){
    string key = to_string(i) + to_string(j) + to_string(isTrue);

    if(i > j)
        return 0;

    if(i == j){
        if(isTrue)  return (str[i] == 'T');
        else        return (str[i] == 'F');
    }

    if(dp.count(key))
        return dp[key];

    int count = 0;
    for(int k = i+1; k <= j-1; k+=2){
        int lt = util(str, i, k-1, true, dp);
        int rt = util(str, k+1, j, true, dp);
        int lf = util(str, i, k-1, false, dp);
        int rf = util(str, k+1, j, false, dp);

        if(str[k] == '&'){
            if(isTrue)
                count += lt*rt;
            else
                count += lt*rf + lf*rt + lf*rf;
        }
        else if(str[k] == '|'){
            if(isTrue)
                count += lt*rf + lf*rt + rt*lt;
            else
                count += lf*rf;
        }
        else if(str[k] == '^'){
            if(isTrue)
                count += lf*rt + lt*rf;
            else
                count += lf*rf + lt*rt;
        }
    }

    dp[key] = count%MOD;
    return dp[key];
}

int ways(string exp){
    unordered_map<string, int> dp;
    int n = exp.length();
    return util(exp, 0, n-1, true, dp);
}

// top down
// tc : O((n^2)*k)
int countParenth(string symb, string oper) {
    int n = symb.length();

    int dpt[n][n];
    int dpf[n][n];

    memset(dpt, 0, sizeof(dpt));
    memset(dpf, 0, sizeof(dpf));

    for(int g = 0; g < n; g++){
        for(int i = 0, j = g; j < n; i++,j++){
            if(g == 0){
                if(symb[i] == 'T'){
                    dpt[i][j] = 1;
                    dpf[i][j] = 0;
                }
                else {
                    dpt[i][j] = 0;
                    dpf[i][j] = 1;
                }
            }else {
                for(int k = i; k < j; k++){
                    char op = oper[k];

                    int ltc = dpt[i][k]%MOD;
                    int rtc = dpt[k+1][j]%MOD;
                    int lfc = dpf[i][k]%MOD;
                    int rfc = dpf[k+1][j]%MOD;

                    if(op == '&'){
                        dpt[i][j] += (ltc*rtc)%MOD;
                        dpf[i][j] += ((lfc*rtc)%MOD + (ltc*rfc)%MOD + (lfc*rfc)%MOD)%MOD;
                    }
                    else if(op == '|'){
                        dpt[i][j] += ((ltc*rtc)%MOD + (lfc*rtc)%MOD + (ltc*rfc)%MOD)%MOD;
                        dpf[i][j] += (lfc*rfc)%MOD;
                    }
                    else {
                        dpt[i][j] += ((ltc*rfc)%MOD + (lfc*rtc)%MOD)%MOD;
                        dpf[i][j] += ((lfc*rfc)%MOD + (ltc*rtc)%MOD)%MOD;
                    }
                }
            }
        }
    }

    return dpt[0][n-1]%MOD;
}

int waysDP(string str){
    int n = str.length();

    string sym = "";
    string oper = "";

    for(int i = 0; i < n; i+=2)
        sym += str[i];

    for(int i = 1; i < n; i+=2)
        oper += str[i];

    return countParenth(sym, oper);
}

// Driver function
int main(){
    string exp = "T|T&F^T";
    // string exp = "T^T^T^F|F";

    cout << ways(exp) << endl;
    cout << waysDP(exp) << endl;

    return 0;
}
