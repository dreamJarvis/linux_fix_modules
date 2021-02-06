// 315. Count of Smaller Numbers After Self
#include <bits/stdc++.h>
using namespace std;

vector<int> countSmaller(vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++){
        int count = 0;
        for(int j = i; j < nums.size(); j++)
            if(nums[i] > nums[j])
                count++;
        nums[i] = count;
    }

    return nums;
}

// Driver function
int main(){
    vector<int> arr({5, 2, 6, 1});

    for(auto i:countSmaller(arr))
        cout << i << " ";
    cout << endl;

    return 0;
}
