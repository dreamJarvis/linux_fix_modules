/*
    17. Subarray with given sum
    https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/0/?track=amazon-arrays&batchId=192#
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> subarraySum(int arr[], int n, int s){
    bool flag = false;
    int si = 0, ei = 0;
    int sum = 0;
    while(si < n){
        if(sum < s){
            sum += arr[ei];
            ei++;
        }
        else if(sum > s){
            sum -= arr[si];
            si++;
        }
        else if(sum == s){
            flag = true;
            break;
        }
    }

    if(!flag)   return vector<int>({-1});
    return vector<int>({si+1, ei});
}

vector<int> subarraySumII(int arr[], int n, int target){
    int sum = 0;
    int s = 0, e = 0;
    bool flag = false;
    for(int i = 0; i < n; i++){
        while(e < n && sum < target){
            sum += arr[e];
            e++;
        }

        if(sum == target){
            flag = true;
            s = i;
            break;
        }

        sum -= arr[i];
    }

    return flag == true ? vector<int>({s+1, e}) : vector<int>({-1});
}

// Driver function
int main(){
    int arr[] = {1,2,3,7,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int s = 12;

    // int arr[] = {1,2,3,4,5,6,7,8,9,10};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // int s = 15;

    for(auto &i:subarraySum(arr, n, s))
        cout << i << " ";
    cout << endl;

    return 0;
}
