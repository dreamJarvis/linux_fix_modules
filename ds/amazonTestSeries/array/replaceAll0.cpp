/*
    https://practice.geeksforgeeks.org/problems/replace-all-0s-with-5/1/?track=amazon-arrays&batchId=192
*/
#include <iostream>
#include <sstream>
using namespace std;

int replace0(int N){
    string temp = to_string(N);

    string res = "";
    for(auto &i:temp){
        if(i == '0')
            res += '5';
        else
            res += i;
    }

    int num;
    stringstream sn(res);
    sn >> num;

    return num;
}

// Driver function
int main(){
    int N = 1004;
    cout << replace0(N) << endl;
    return 0;
}
