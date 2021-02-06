#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<string> arr("1 1", "3 4", "2 5");

    sort(arr.begin(), arr.end());

    for(auto i:arr){
        cout << i << endl;
        
    }

    return 0;
}
