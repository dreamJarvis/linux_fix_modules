/*
    22. Three Sum Closest
    https://practice.geeksforgeeks.org/problems/product-array-puzzle0852/0/?track=amazon-arrays&batchId=192

    https://leetcode.com/problems/3sum-closest/
*/
#include <bits/stdc++.h>
using namespace std;

// O(n^2)
int threeSumClosest(vector<int> arr, int target){
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int maxSum = 0, diff = INT_MAX;
    for(int i = 0; i < n; i++){
        int num = arr[i];

        int s = i+1, e = n-1;
        while(s < e){
            int sum = (num + arr[s] + arr[e]);
            int tempDiff = abs(sum-target);

            if(tempDiff < diff){
                maxSum = sum;
                diff = tempDiff;
            }
            else if(tempDiff == diff){
                if(sum > maxSum)
                    maxSum = sum;
            }

            if(sum >= target)
                e--;
            else
                s++;
        }
    }

    return maxSum;
}

// Driver function
int main(){
    // vector<int> arr({-7, 9, 8, 3, 1, 1});
    // int target = 2;
    // vector<int> arr({5, 2, 7, 5});
    // int target = 13;
    vector<int> arr({96, -72, 48, 22, -91, -4, 91, 4, 37, 32, 75, 62, -96, -77, 38, 13, -80, 76, 18, 99, 31, 61, 71, 79, -32, 32, 60, 5, 18, 94, -98});
    int target = 254;

    cout << threeSumClosest(arr, target) << endl;

    return 0;
}
