#include <bits/stdc++.h>
using namespace std;

// time complexity : O(n^2)
// space complexity : O(n^2)
int divisibleByK(vector<int> &arr, int k){
    multiset<pair<int, int>> sumByK;
    int count = 0;

    int n = arr.size();
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int sum = arr[i] + arr[j];

            sumByK.insert(make_pair(i, j));

            if(sum%k == 0){
                // cout << i << ", " << j << " : " << sum << endl;
                count++;
            }
        }
    }

    int index = 0;
    for(auto value:sumByK){
        for(int i = 0; i < n; i++){
            int sum = arr[value.first] + arr[value.second] + arr[i];

            if(i > value.first && i > value.second){
                if(sum%k == 0){
                    // cout << value.first << ", " << value.second << ", " << i << " : " << sum << endl;
                    count++;
                }
            }
        }
    }

    return count;
}

// Driver function
int main(){
    vector<int> arr({2, 1, 3, 4, 5, 7});
    int k = 5;

    cout << divisibleByK(arr, k) << endl;

    return 0;
}
