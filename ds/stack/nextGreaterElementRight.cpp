// next greater Element to the right in given order of elements
#include<bits/stdc++.h>
using namespace std;

// tc : O(n)
vector<int> nextGreaterElement(int arr[], int n){
    vector<int> result(n, -1);
    stack<int> s;

    for(int i = 0; i < n; i++){
        if(i == 0 || s.empty()){
            s.push(i);
            continue;
        }

        while(!s.empty() && arr[i] > arr[s.top()]){
            // cout << arr[i] << " ";
            result[s.top()] = arr[i];
            s.pop();
        }

        s.push(i);
    }

    return result;
}

int main(){
    // int arr[] = {1, 3, 2, 4};
    // int arr[] = {4, 3, 2, 1};
    int arr[] = {7, 8, 1, 4};

    int n = sizeof(arr)/sizeof(arr[0]);

    for(auto i:nextGreaterElement(arr, n))
        cout << i << " ";
    cout << endl;

    return 0;
}
