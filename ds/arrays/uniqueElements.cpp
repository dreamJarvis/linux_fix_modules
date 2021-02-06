// print unique elements in an array
#include <bits/stdc++.h>
using namespace std;

// Driver function
int main(){ 
    vector<int> arr ({1,2,3,4,5,5,4,6,5});
    unordered_map<int, bool> h;                     // can be done better by sets
    
    for(auto val : arr){
        if(h.count(val)){
            h[val] = false;
        }
        else 
            h[val] = true;
    }

    for(auto val : h){
        if(val.second)
            cout << val.first << " ";
    }
    cout << endl;

    return 0;
}