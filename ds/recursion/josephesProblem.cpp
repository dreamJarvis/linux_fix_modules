/*
    josephes problems
    Game of Death in a circle
    https://practice.geeksforgeeks.org/problems/game-of-death-in-a-circle/0
*/
#include <bits/stdc++.h>
using namespace std;

int gameOfDeath(vector<int> &nums, int k, int index){
    if(nums.size() == 1){
        return nums[0];
    }

    index = (index+k)%(nums.size());
    nums.erase(nums.begin() + index);

    return gameOfDeath(nums, k, index);
}

// Driver function
int main(){
    int tc;
    cin >> tc;

    while(tc--){
        int n , k;
        cin >> n >> k;

        vector<int> nums(n);
        for(int i = 1; i <= n; i++)
            nums[i-1] = i;

        cout << gameOfDeath(nums, k-1, 0) << endl;
        // cout << nums[0] << endl;
    }

    return 0;
}
