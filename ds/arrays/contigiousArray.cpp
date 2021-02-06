#include <bits/stdc++.h>
using namespace std;

// contigious sub-array
// time complexity : O(n^2)
// space complexity : O(1)
int contigiousSubarray(vector<int> &arr){
    int n = arr.size();
    int maxLen = 0;

    for(int i = 0; i < n; i++){
        int count0 = 0;
        int count1 = 0;
        int j = 0;
        for(j = i; j < n; j++){
            if(count0 == count1 && count0 && count1){
                maxLen = max(maxLen, (j-i));
            }

            if(arr[j] == 0) count0++;
            if(arr[j] == 1) count1++;
        }

        if(count0 == count1)
            maxLen = max(maxLen, j-i);
    }

    return maxLen;
}

// time complexity : O(N)
// space complexity : O(N)
int findMaxLength(vector<int>& arr){
    int n = arr.size();
    int maxLen = 0;

    unordered_map<int, int> itemIndex;

    int count = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == 0)   count--;
        else if(arr[i] == 1)  count++;

        arr[i] = count;
    }

    itemIndex[0] = -1;
    for(int i = 0; i < n; i++){
        if(itemIndex.count(arr[i])){
            maxLen = max(maxLen, (i - itemIndex[arr[i]]) );
        }else{
            itemIndex[arr[i]] = i;
        }
    }

    return maxLen;
}

int findMaxLength2(vector<int>& nums) {
    // [-1, -2, -3, -2, -1, -2, -1, -2, -3, -2, -1, 0, 1]
    // [ 0,  0,  0,  1,  1,  0,  1,  0,  0,  1,  1, 1, 1]
    int k = nums.size();
    int rc = 0;
    for(int i = 0; i < k; ++i){
        if (nums[i] == 0)
            rc -= 1;
        else
            rc += 1;

        nums[i] = rc;
    }

    unordered_map<int, int> lookup;
    int maxLen = 0;
    for(int i = 0; i < k; ++i){
        if (nums[i] == 0){
            maxLen = max(maxLen, i)+1;
        }
        else if (lookup.find(nums[i]) == lookup.end()){
            lookup[nums[i]] = i;
        }
        else{
            maxLen = max(maxLen, i - lookup[nums[i]]);
        }
    }

    return maxLen;
}

// Driver function
int main(){
    vector<int> arr({0,1,0});

    // cout << contigiousSubarray(arr) << endl;
    cout << findMaxLength(arr) << endl;

    return 0;
}
// [0,1,1,0,1,1,1,0]
