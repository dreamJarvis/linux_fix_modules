// leetcode 560
#include <bits/stdc++.h>
using namespace std;

int subArraySum(vector<int> &nums, int k){
    unordered_map<int, int> h;

    h[0] = 1;
    int sum = 0;
    int count = 0;

    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];

        if(h.count(sum-k)){
            count += h[sum-k];
        }

        h[sum] += 1;
    }

    return count;
}

// Driver function
int main(){
    vector<int> arr({-1, 2, -1, 2, -1});
    cout << subArraySum(arr, 0) << endl;
    return 0;
}
