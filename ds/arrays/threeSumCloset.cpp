// leetcode : 16
#include <bits/stdc++.h>
using namespace std;

int closestSum(vector<int> &arr, int target){
    if(arr.size() < 3)
        return -1;

    int n = arr.size();
    sort(arr.begin(), arr.end());

    int sbseBda = 0;
    for(int i = n-1; i > n-4; i--)
        sbseBda += arr[i];


    int nearest = sbseBda;
    int smallest = INT_MAX;

    for(int i = 0; i < n; i++){
        if(i == 0 or (i > 0 and arr[i-1] != arr[i])){
            int restOfSum = target - arr[i];

            int low = i + 1;
            int high = n - 1;

            while(low < high){

                int sum = arr[low] + arr[high] + arr[i];
                if(abs(target - sum) < smallest){
                    nearest = sum;
                    smallest = abs(target - sum);
                }

                if(arr[low] + arr[high] == restOfSum){
                    return sum;
                }
                else if(arr[low] + arr[high] > restOfSum){
                    high--;
                }
                else{
                    low++;
                }
            }
        }
    }

    return nearest;
}

// Driver function
int main(){
    vector<int> arr({1, 1, 1, 0});
    int target = -100;

    cout << closestSum(arr, target) << endl;

    return 0;
}
