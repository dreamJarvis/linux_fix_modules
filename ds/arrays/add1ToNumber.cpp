// interviweBit
#include <bits/stdc++.h>
using namespace std;

vector<int> addOne(vector<int> arr){
    if(arr.size()==0)   return arr;
    int n = arr.size();

    vector<int> result;

    int sum = arr[n-1] + 1;
    result.push_back(sum%10);
    int carry = sum/10;

    for(int i = n-2; i >= 0; i--){
        sum = arr[i] + carry;
        result.push_back(sum%10);
        carry = sum/10;
    }

    if(carry){
        result.push_back(carry);
    }

    reverse(result.begin(), result.end());

    int i=0;
    for(;i<n;i++)
        if(result[i] != 0)
            break;

    result = vector<int>(result.begin()+i, result.end());
    return result;
}

int main(){
    vector<int> arr({0, 1, 8, 9});

    for(auto value:addOne(arr))
        cout << value << " ";
    cout << endl;

    return 0;
}
