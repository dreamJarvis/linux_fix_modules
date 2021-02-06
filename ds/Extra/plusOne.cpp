// leetcode 66 : Plus one
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();

    vector<int> result;
    int sum = 0, carry = 1;
    while(n){
        sum = digits[n-1] + carry;
        result.push_back(sum%10);
        carry = sum/10;
        n--;
    }

    if(carry)
        result.push_back(carry);

    reverse(result.begin(), result.end());

    return result;
}

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    digits[n-1]++;
    bool check = false;
    for(int i=n-1; i>=0; i--){
        if (check) digits[i]++;
        check = (digits[i] >=10)?true:false;
        digits[i] = (digits[i] >=10)?0:digits[i];
        if (!check) break;
    }
    vector<int> res{1};
    if (check){
        digits.insert(digits.begin(), res.begin(), res.end());
    }

    return digits;
}

// Driver frunction
int main(){
    vector<int> arr({1, 2, 4});

    for(auto i:plusOne(arr))
        cout << i << " ";
    cout << endl;

    return 0;
}
