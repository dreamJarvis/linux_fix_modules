// leetcode : 16
// 4ms solution
#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int> &nums, int target){
    int sol, left, m;
    int diff = INT_MAX;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i++){
        left = target - nums[i];

        int low = i + 1;
        int high = nums.size() - 1;

        while(low < high){
            int sum = nums[low] + nums[high];
            if(abs(left - sum) < diff){
                diff = abs(left - sum);     //  just another way of subtracting sum of 3 arr[i] from target
                sol = nums[i] + sum;        //  solution, nearest sum bhejna h

                if(diff == 0)   // agr diff  == 0 h, toh yhi break krde, kyki target sum mil gaya 
                    return sol;

            }
            else if(sum > left)
                high--;
            else
                low++;
        }
    }

    return sol;
}

// Driver function
int main(){
    vector<int> arr({1, 1, 1, 0});
    int target = -100;

    cout << threeSumClosest(arr, target) << endl;

    return 0;
}
