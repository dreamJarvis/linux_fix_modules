#include <bits/stdc++.h>
using namespace std;

int myCompare(string x, string y){
    string xy = x.append(y);
    string yx = y.append(x);

    return xy.compare(yx) > 0 ? 1 : 0;
}

void largestPermutation(vector<int> &arr){
    int n = arr.size();

    vector<string> num;
    for(auto value:arr)
        num.push_back(to_string(value));

    sort(num.begin(), num.end(), myCompare);

    for(auto value:num)
        cout << value;
    cout << endl;
}

// Driver function
int main(){
    vector<int> arr({54, 546, 548, 60});

    largestPermutation(arr);

    return 0;
}
