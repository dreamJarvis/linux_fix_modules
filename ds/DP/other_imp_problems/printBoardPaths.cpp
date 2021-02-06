#include <bits/stdc++.h>
using namespace std;

// print all the paths
void countSteps(int n, int k, int sum, string str){
    // ** hme sum ki value hmesha n se choti chahiye, tbhi loop kaam kregi ussme

    // ek jb n ke braber hoga
    if(sum == n){
        cout << str.substr(0, str.length()-1) << endl;
        return ;
    }

    // dusra jb sum n ko cross kr jayega
    if(sum > n){
        return ;
    }

    // ye hr path pr jayega
    for(int i = 1; i <= k; i++){
        string temp = to_string(i) + "_";
        countSteps(n, k, sum+i, str+temp);
    }
}

// Driver function
int main(){
    int n = 6;
    int steps = 3;

    countSteps(n, steps, 0, "");

    return 0;
}
