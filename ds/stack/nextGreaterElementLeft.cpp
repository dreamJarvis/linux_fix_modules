// next greater Element to the left
// previous greater element
#include<bits/stdc++.h>
using namespace std;

// tc : O(n)
vector<int> previousGreaterElement(int arr[], int n){
    vector<int> result(n, -1);

    stack<int> s;
    for(int i = n-1; i >= 0; i--){
        if(i == n-1 || s.empty()){
            s.push(i);
            continue;
        }

        while(!s.empty() && arr[i] > arr[s.top()]){
            result[s.top()] = arr[i];
            s.pop();
        }

        s.push(i);
    }

    return result;
}

int main(){
    // int arr[] = {10, 4, 2, 20, 40, 12, 30};
    // int arr[] = {10, 20, 30, 40};
    int arr[] = {40, 30, 20, 10};

    int n = sizeof(arr)/sizeof(arr[0]);

    for(auto i:previousGreaterElement(arr, n))
        cout << i << " ";
    cout << endl;

    return 0;
}
