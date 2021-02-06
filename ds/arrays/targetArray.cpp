// leetcode : 1389
#include <bits/stdc++.h>
using namespace std;

vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
    int n = nums.size();
    // vector<int> target(n, -1);
    vector<int> target;

    for(int i = 0; i < n; i++){
        // if(target[index[i]]==-1){
        //     target[index[i]] = nums[i];
        // }
        // else{
        //     for(int j = n-1; j >= index[i]; j--){
        //         target[j] = target[j-1];
        //     }
        //     target[index[i]] = nums[i];
        // }
        target.insert(target.begin()+index[i], nums[i]);
    }

    return target;
}

// Driver function
int main(){
    // vector<int> nums({0, 1, 2, 3, 4});
    // vector<int> index({0, 1, 2, 2, 1});

    vector<int> nums({1, 2, 3, 4, 0});
    vector<int> index({0, 1, 2, 3, 0});

    for(auto item:createTargetArray(nums, index))
        cout << item << " ";
    cout << endl;

    return 0;
}
