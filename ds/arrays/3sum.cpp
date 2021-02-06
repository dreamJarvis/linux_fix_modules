#include <bits/stdc++.h>
using namespace std;

// 3 sum
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;

    int target = 0;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    // yah pe low high wala logic array ke hr element pr lgega
    for(int i = 0; i < n; i++){
        if(i == 0 || i > 0 and nums[i] != nums[i-1]){
            int sum = target - nums[i];
            int low = i + 1;
            int high = n - 1;

            // while loop, wo sare 2 elemnts lake dega jinka sum apne target - nums[i] ke brabr h
            while(low < high){
                if(nums[low] + nums[high] == sum){
                    result.push_back({nums[i], nums[low], nums[high]});

                    // skipping the duplicates
                    while(low < high and nums[low] == nums[low + 1]) low++;
                    while(low < high and nums[high] == nums[high - 1]) high--;

                    low++;
                    high--;
                }
                else if(nums[low] + nums[high] > sum) high--;
                else low++;
            }
        }
    }

    return result;
}

int main(){
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(arr);

    for(auto val:result){
        for(auto value:val)
            cout << value << " ";
        cout << endl;
    }

    return 0;
}
