#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int> &arr){
    int n = arr.size();

    vector<int> result;
    int carry = 0;
    int sum = arr[n-1]+1;
    carry = sum/10;
    result.push_back(sum%10);

    for(int i = n-2; i >= 0; i--){
        sum = arr[i] + carry;
        result.push_back(sum%10);
        carry = sum/10;
    }

    if(carry)
        result.push_back(carry);

    reverse(result.begin(), result.end());
    return result;
}

int main(){
    vector<int> arr({9, 9, 9});
    for(auto val:plusOne(arr))
        cout << val << " ";
    cout << endl;
    return 0;
}
