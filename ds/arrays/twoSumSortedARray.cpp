// leetcode : 167. Two Sum II - Input array is sorted
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &arr, int target){
    vector<int> result;

    int low = 0;
    int high = arr.size() - 1;

    while(low < high){
        int sum = arr[low] + arr[high];

        if(sum < target)
            low++;
        else{
            if(sum > target)
                high--;
            else{
                result.push_back(low+1);
                result.push_back(high+1);
                return result;
            }
        }
    }

    return result;
}

// Driver function
int main(){
    vector<int> arr ({2, 7, 11, 15});
    vector<int> result = twoSum(arr, 9);

    cout << result[0] << " " << result[1] << endl;

    return 0;
}
