// leetcode : 1046
// Last Stone Weight
#include <bits/stdc++.h>
using namespace std;

// solution : 1
// time complexity: n*(nlog(n))
int lastStoneWeight(vector<int> &arr){
    int n = arr.size();

    sort(arr.begin(), arr.end());

    int ptr_1 = n-1, ptr_2 = n-2;       // last 2 greatest element
    while(ptr_1 != ptr_2 && ptr_2 >= 0){
        if(arr[ptr_1] == arr[ptr_2])
            arr[ptr_2] = 0;
        else{
            arr[ptr_2] = (arr[ptr_1] - arr[ptr_2]);
        }

        sort(arr.begin(), arr.end());
        ptr_1--;
        ptr_2--;
    }

    return arr[0];
}

// solution : 2
// time complexity : n*m
// m : time taken by priority_queue to set the element orderwise
int lastStoneWeightOptimised(vector<int>& stones) {
    priority_queue<int> s;

    for (int x : stones)
        s.push(x);

    while (s.size() > 1){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if (a - b != 0 || s.empty())
            s.push(a - b);
    }

    return s.top();
}

// Driver function
int main(){
    vector<int> stones({2, 7, 4, 1, 8, 1});

    cout << lastStoneWeightOptimised(stones) << endl;
    // lastStoneWeight(stones);

    return 0;
}
