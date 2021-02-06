#include <bits/stdc++.h>
using namespace std;

// time complexity : O(n^2)
// space complexity : O((n^2)*m)
void divisibleByK(vector<int> &arr, int si, int size, int sum, int k, string ans, int &count){
    // base case: jaha pe recursion break hoga
    if(si > arr.size())
        return ;

    // ya phir jaha hme koi condition satisfy hone pe kuch kaam krna pdega
    if((size == 2 && sum%k == 0) || (size == 3 && sum%k == 0)){
        // cout << ans << endl;
        count++;
    }

    // recursive case: jo hamare sub-problems ka kaam krega
    for(int i = si; i < arr.size(); i++)
        divisibleByK(arr, i+1, size+1, sum+arr[i], k, ans+","+to_string(i), count);
}

// Driver function
int main(){
    vector<int> arr({2, 1, 3, 4, 5, 7});
    int k = 5;

    int count = 0;
    divisibleByK(arr, 0, 0, 0, k, "", count);

    cout << count << endl;

    return 0;
}
