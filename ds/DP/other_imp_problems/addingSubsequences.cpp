#include <bits/stdc++.h>
using namespace std;

int result = INT_MIN;
void subsequences(vector<int> &arr, int i, int size,string ans){
    if(i == size){
        int maxVal = INT_MIN;
        for(auto val : ans){
            int temp = val - '0';
            maxVal = max(maxVal, temp);
        }

        result += maxVal;
        return ;
    }

    int a = arr[0];
    string ch = to_string(a);
    vector<int> restOfString = vector<int>(arr.begin() + 1, arr.end());

    subsequences(restOfString, i+1, size, ans);
    subsequences(restOfString, i+1, size, ans+ch);
}

int main(){
    int n;
    vector<int> arr;

    cin >> n;

    int temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        arr.push_back(temp);
    }

    subsequences(arr,0,arr.size(),"");

    cout << result << endl;
    return 0;
}