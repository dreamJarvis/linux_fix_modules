#include <bits/stdc++.h>
using namespace std;

void largestNumber(vector<int> arr, string ans){
    if(ans.length() == 0){
        cout << ans << endl;
        return ;
    }

    vector<int> temp = arr;
    for(int i = 0; i < arr.size(); i++){
        temp.erase(temp.begin()+i);
        largestNumber(temp, ans + to_string(arr[i]));
    }
}

// Driver function
int main(){
    vector<int> arr({3, 30, 34, 5, 9});

    largestNumber(arr, "");

    return 0;
}
