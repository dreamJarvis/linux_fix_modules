// 901. Online Stock Span
#include <bits/stdc++.h>
using namespace std;

// using brute force
// tc : O(n^2)
vector<int> stockSpan(vector<int> &arr){
    int n = arr.size();
    vector<int> result(n, 0);

    for(int i = 0; i < n; i++){
        int span = 0;
        for(int j = i; j >= 0; j--){
            if(arr[j] > arr[i])
                break;
            span++;
        }
        result[i] += span;
    }

    return result;
}

// using stack
// tc : O(n)
vector<int> stockSpanII(vector<int> &arr){
    int n = arr.size();

    vector<int> result(n, 1);
    stack<int> s;

    for(int i = 0; i < n; i++){
        if(i == 0 || s.empty()){
            s.push(i);
            continue;
        }

        while(!s.empty() && arr[i] >= arr[s.top()]){
            int tp = s.top();
            s.pop();

            result[i] = s.empty() ? i+1 : (i - s.top());
        }
        s.push(i);
    }

    return result;
}

// Driver function
int main(){
    vector<int> arr({100, 80, 60, 70, 60, 75, 85});
    // vector<int> arr({10, 4, 5, 90, 120, 80});

    for(auto i:stockSpanII(arr))
        cout << i << " ";
    cout << endl;

    return 0;
}
