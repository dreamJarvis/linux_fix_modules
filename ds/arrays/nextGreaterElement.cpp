// To print next greater element for every elment in the array
#include <bits/stdc++.h>
using namespace std;

// to find the next greater element for the given element 
void nextGreaterElement(vector<int> &arr){
    int n = arr.size();
    stack<int> s;

    // push the 1st element to the stack
    s.push(arr[0]);

    // iterate for the rest of the elements
    for(int i = 1; i < n; i++){
        if(s.empty()){
            s.push(arr[i]);
            continue;
        }

        // if the stack is not empty, then pop the element from the stack, if popped element is smaller than next, then
        // 1 --> print the pair
        // 2 --> keep popping while elements are smaller and stack is not empty
        while(!s.empty() && s.top() < arr[i]){
            cout << s.top() << "-->" << arr[i] << endl;
            s.pop();
        }

        // push next to stack so that we can find next greater for it
        s.push(arr[i]);
    }

    // after iterating over the loop, the remaining elements in stack do not have the next greater element in stack, so print -1 for them
    while(!s.empty()){
        cout << s.top << " --> " << -1 << endl;
        s.pop();
    }
}

// Driver function
int main(){
    vector<int> arr({3, 5, 1, 5, 10, 23, 6});
    nextGreaterElement(arr);
    return 0;
}
