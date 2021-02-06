// 503. Next Greater Element II
#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();

    vector<int> result(n, -1);
    stack<int> s;

    for(int i = 0; i < n; i++){
        if(i == 0 || s.empty()){
            s.push(i);
            continue;
        }

        while(!s.empty() && nums[i] > nums[s.top()]){
            result[s.top()] = nums[i];
            s.pop();
        }

        s.push(i);
    }

    for(int i = 0; i < n; i++){
        while(!s.empty() && nums[i] > nums[s.top()]){
            result[s.top()] = nums[i];
            s.pop();
        }
    }

    return result;
}

vector<int> nextGreaterElementsII(vector<int>& nums) {
    int n = nums.size();

    vector<int> result(n, -1);
    stack<int> s;

    for(int i = 0; i < n; i++){
        if(i == 0 || s.empty()){
            s.push(i);
            continue;
        }

        while(!s.empty() && nums[i] > nums[s.top()]){
            result[s.top()] = nums[i];
            s.pop();
        }

        s.push(i);
    }

    int i = 0;
    while(!s.empty() && i < n){
        while(nums[s.top()] < nums[i]){
            result[s.top()] = nums[i];
            s.pop();
        }

        i++;
    }

    return result;
}

vector<int> nextGreaterElementsIII(vector<int>& nums) {
    int n = nums.size();

    vector<int> result(n, -1);
    stack<int> s;
    s.push(0);

    for(int i = 0; i < 2*n-1; i++){
        while(!s.empty() && nums[i%n] > nums[(s.top()%n)]){
            result[s.top()%n] = nums[i%n];
            s.pop();
        }

        s.push(i);
    }

    return result;
}

// Driver function
int main(){
    // vector<int> arr({1, 2, 1});
    // vector<int> arr({5, 4, 3, 2, 1});
    vector<int> arr({1, 2, 3, 4, 3});

    // for(auto i:nextGreaterElements(arr))
    //     cout << i << " ";
    // cout << endl;

    for(auto i:nextGreaterElementsIII(arr))
        cout << i << " ";
    cout << endl;

    return 0;
}
/*

*/
