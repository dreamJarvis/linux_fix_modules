// https://www.geeksforgeeks.org/next-smaller-element/
#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(int arr[], int n){
    vector<int> result(n, -1);

    stack<int> s;
    for(int i = 0; i < n; i++){
        if(i == 0|| s.empty()){
            s.push(i);
            continue;
        }

        while(!s.empty() && arr[i] < arr[s.top()]){
            result[s.top()] = arr[i];
            s.pop();
        }

        s.push(i);
    }

    return result;
}

// Driver function
int main(){
    // int arr[] = {4, 8, 5, 2, 25};
    int arr[] = {13, 7, 6, 12};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(auto i:nextSmallerElement(arr, n))
        cout << i << " ";
    cout << endl;

    return 0;
}
