// leetcode 167
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& n1, int ta){
    const auto n2 = n1;
    map<int, int> ma;

    for(size_t i = 0; i < n1.size(); i++){
        ma[n1[i]] = 0;
    }

    // ye current n1 ke index pe jo value h, ussko target se minus krdega, aor jo value bachegi ussko wo ussi index pr store kra dega.
    // ab map me wo stoarge ke (target - n1[i])th value pr -> current index + 1 store kra dega
    for(size_t i = 0; i < n1.size(); i++){
        n1[i] = target - n1[i];
        storage[n1[i]] = i + 1;
    }


    // ------------------ in test cases ko chla kr dekh le ------------------- //
    // for(auto val:ma)
    //     cout << val.first << " -> " << val.second << endl;
    // cout << endl;
    //
    // for(auto val:n1)
    //     cout << val << endl;
    // cout << endl;
    //
    // for(auto val:n2)
    //     cout << val << endl;
    // cout << endl;
    // --------------------------------------------------------------------//

    // ab jis jis number ka 9 ke sath complimentry exist krta hoga , unke complementary waha saved honge
    // aor ye loop sbse pehle complimentary ko return kr dega
    for(size_t i = 0; i < n2.size(); i++){
        if(ma[n2[i]] != 0)
            return vector<int>{i+1, ma[n2[i]]};
    }

    return vector<int>();
}

// Driver function
int main(){
    vector<int> arr ({2, 7, 11, 15});
    vector<int> result = twoSum(arr, 9);

    cout << result[0] << " " << result[1] << endl;
    return 0;
}
