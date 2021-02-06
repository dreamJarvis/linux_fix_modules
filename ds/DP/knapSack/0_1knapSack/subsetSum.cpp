/*
    if there exist a subset with sum = k
*/
#include <bits/stdc++.h>
using namespace std;

// ==================================  memoised ============================ //
// tc : O(n*m)
// sc : O(n*m)
unordered_map<string, bool> dp;
bool subsetSumUtil(vector<int> &arr, int target, int n){
    string key = to_string(target) + '_' + to_string(n);

    if(n < 0 && target != 0)
        return false;

    if(target == 0)
        return true;

    if(dp.count(key))
        return dp[key];

    if(arr[n] > target)
        return subsetSumUtil(arr, target, n-1);
    else{
        dp[key]  = (
            subsetSumUtil(arr, target-arr[n], n-1) ||
            subsetSumUtil(arr, target, n-1)
        );
    }

    return dp[key];
}

bool subsetSum(vector<int> &arr, int target){
    return subsetSumUtil(arr, target, arr.size()-1);
}


// ====================== top down ======================= //
// tc : O(n*m)
// sc : O(n*m)
bool subsetSumDP(vector<int> &arr, int target){
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(target+1, false));

    // initialization
    for(int i = 0; i <= n; i++)
        dp[i][0] = true;

    for(int i = 1; i <= target; i++)
        dp[0][i] = false;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= target; j++){
            if(arr[i-1] <= j){
                dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][target];
}

// Driver function
int main(){
    // vector<int> arr({3, 34, 4, 12, 5, 2});
    // int target = 9;

    vector<int> arr({3, 34, 4, 12, 5, 2});
    int target = 30;

    // vector<int> arr({0,0,0,0,0,0,0,0,1});
    // int target = 1;

    // cout << subsetSum(arr, target) << endl;
    cout << subsetSumDP(arr, target) << endl;

    return 0;
}

/*
vector<int> arr({} 82, 1, 14, 42, 56, 56, 43, 63, 12, 78, 25, 79, 53, 44, 97, 74, 41, 14, 76, 73, 19, 11, 18, 33, 13, 96, 70, 32, 41, 89, 86, 91, 98, 90, 91, 46, 54, 15, 52, 41, 45, 59, 36, 60, 93, 6, 65, 82, 4, 30, 76, 9, 93, 98, 50, 57, 62, 28, 68, 42, 30, 41, 14, 75, 2, 78, 16, 84 })
B : 8214

[0,0,0,0,0,0,0,0,1]
1

vector<int> arr({ 82, 1, 14, 42, 56, 56, 43, 63, 12, 78, 25, 79, 53, 44, 97, 74, 41, 14, 76, 73, 19, 11, 18, 33, 13, 96, 70, 32, 41, 89, 86, 91, 98, 90, 91, 46, 54, 15, 52, 41, 45, 59, 36, 60, 93, 6, 65, 82, 4, 30, 76, 9, 93, 98, 50, 57, 62, 28, 68, 42, 30, 41, 14, 75, 2, 78, 16, 84 });
B = 8214;
*/
