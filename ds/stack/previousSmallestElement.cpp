// https://www.geeksforgeeks.org/find-the-nearest-smaller-numbers-on-left-side-in-an-array/
#include <bits/stdc++.h>
using namespace std;

vector<int> previousSmallerElement(int arr[], int n){
    vector<int> result(n, -1);

    stack<int> s;
    for(int i = 0; i < n; i++){
        if(i == 0 || s.empty()){
            s.push(i);
            continue;
        }

        while(!s.empty() && arr[i] < arr[s.top()] ){
            s.pop();
        }

        if(!s.empty())
            result[i] = arr[s.top()];

        s.push(i);
    }

    return result;
}

// Driver function
int main(){
    int arr[] = {1, 6, 4, 10, 2, 5};
    // int arr[] = {1, 3, 0, 2, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(auto i:previousSmallerElement(arr, n))
        cout << i << " ";
    cout << endl;

    return 0;
}
