// leetcode : 18
#include <bits/stdc++.h>
using namespace std;

// four sums function
// use 3 sum logic
// time complexity : O(N^3)
vector<vector<int>> fourSum(vector<int> &arr, int target){
    vector<vector<int>> results;

    sort(arr.begin(), arr.end());

    for(int i = 0; i < (int)arr.size() - 3; i++){
        // if condition to skip duplicates x 1's
        if(i==0 || arr[i] != arr[i-1]){
                for(int j = i + 1; j < (int)arr.size() - 2; j++){
                    // if condition to skip duplicates x2's
                    if(j==i+1 || arr[j] != arr[j-1]){
                        int twoSumTar = target - arr[i] - arr[j];
                        int low = j + 1;
                        int high = (int)arr.size() - 1;

                        while(low < high){
                            if(arr[low] + arr[high] == twoSumTar){
                                results.push_back({arr[i], arr[j], arr[low], arr[high]});

                                while(low < high and arr[low] == arr[low + 1])    low++;
                                while(low < high and arr[high] == arr[high - 1])  high--;

                                low++;
                                high--;
                            }else if(arr[low] + arr[high] > twoSumTar)  high--;
                            else    low++;
                        }
                    }
                }
            }
    }

    return results;
}
// Driver function
int main(){
    vector<int> arr({-1, 0, 1, 2, -1, -4});
    int target = -1;
    vector<vector<int>> result = fourSum(arr, target);

    for(auto val:result){
        for(auto value:val)
            cout << value << " ";
        cout << endl;
    }

    return 0;
}
