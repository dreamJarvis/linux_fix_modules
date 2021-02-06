// 46. Permutations
#include <bits/stdc++.h>
using namespace std;

void permuteUTIL(vector<int>& nums, vector<vector<int>> &result, int pos){
    if(pos == nums.size()){
        result.push_back(nums);
    }

    for(int i = pos; i < nums.size(); i++){
        swap(nums[pos], nums[i]);
        permuteUTIL(nums, result, pos+1);
        swap(nums[pos], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;

    permuteUTIL(nums, result, 0);
    return result;
}

// Driver function
int main(){
    // vector<int> arr({1, 2, 3});
    vector<int> arr({0, -1, 1});

    vector<vector<int>> result = permute(arr);
    for(auto i:result){
        for(auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
