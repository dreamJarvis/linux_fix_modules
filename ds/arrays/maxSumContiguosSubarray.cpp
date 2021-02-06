// Find the contiguous subarray within an array, A of length N which has the largest sum.
#include <bits/stdc++.h>
using namespace std;

// kadanes algo: O(n)
int maxSum(vector<int> &arr){
    int n = arr.size();
    int currSum = arr[0];
    int maxSum = arr[0];

    for(int i = 1; i < n; i++){
        currSum = max(currSum+arr[i], arr[i]);
        maxSum = max(currSum, maxSum);
    }

    return maxSum;
}

// divide & conquer : O(nlog(n))
int maxSubArraySum_DC(vector<int> arr){
    int n = arr.size();
    if(n==1){
        return arr[0];
    }

    int m = n/2;
    int left_MSS = maxSubArraySum_DC(vector<int>(arr.begin(), arr.begin()+m));
    int right_MSS = maxSubArraySum_DC(vector<int>(arr.begin()+m, arr.end()));

    int leftSum = INT_MIN, rightSum = INT_MIN, sum = 0;

    // calculates the sum --> right-ward
    for(int i = m; i < n; i++){
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }

    sum = 0;

    // calculates the sum --> left-ward
    for(int i = (m-1); i >= 0; i--){
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }

    // returns the max sum, by considering left, right and itself in the equation
    int ans = max(leftSum, rightSum);
    return max(ans, leftSum+rightSum);
}

// brute force algorithm : O(n^2)
int maxSum_2(vector<int> &arr){
    int n = arr.size();
    int ans = INT_MIN;

    for(int i = 0; i < n; i++){
        int sum = arr[i];
        for(int j = i+1; j < n; j++){
            sum += arr[j];
            if(sum > ans)
                ans = sum;
        }
    }

    return ans;
}

// brute force algorithm : O(n^3)
int maxSumBruteForce(vector<int> &arr){
    int n = arr.size();
    int ans = INT_MIN;
    for(int sub_array_size = 1; sub_array_size < n; sub_array_size++){
        for(int start_index = 0; start_index < n; start_index++){
            if(start_index + sub_array_size > n)
                break;
            int sum = 0;
            for(int i = start_index; i < (start_index+sub_array_size); i++)
                sum += arr[i];
            ans = max(ans, sum);
        }
    }

    return ans;
}

// Driver function
int main(){
    vector<int> arr({1, 2, 3, 4, -10});
    // cout << maxSum_2(arr) << endl;
    // cout << maxSumBruteForce(arr) << endl;
    cout << maxSubArraySum_DC(arr) << endl;
    return 0;
}
