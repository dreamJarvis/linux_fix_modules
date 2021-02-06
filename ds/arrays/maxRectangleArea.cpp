// 84. Largest Rectangle in Histogram
#include <bits/stdc++.h>
using namespace std;

// TLE
// int largestRectangleArea(vector<int>& arr) {
//     int n = arr.size();
//
//     int ans = 0;
//     for(int i = 0; i < n; i++){
//         int count = 0;
//
//         // left side
//         for(int j = i; j >= 0; j--){
//             if(arr[i] > arr[j])
//                 break;
//             count++;
//         }
//
//         //right side
//         for(int j = i+1; j < n; j++){
//             if(arr[i] > arr[j])
//                 break;
//             count++;
//         }
//
//         int temp = arr[i]*count;
//         ans = max(ans, temp);
//     }
//
//     return ans;
// }

// method : segment trees
// tc : O(n*long(n))


// method : by using stack
// tc : O(n)
int largestRectangleArea(vector<int>& arr) {
    int n = arr.size();
    stack<int> s;
    int maxArea = 0;
    int tp;
    int areaWithTop;

    int i = 0;
    while(i < n){
        if(s.empty() || arr[s.top()] <= arr[i])
            s.push(i++);

        else{
            tp = s.top();
            s.pop();

            areaWithTop = arr[tp] * (s.empty() ? i : i - s.top() - 1);
            maxArea = max(maxArea, areaWithTop);
        }
    }

    while(!s.empty()){
        tp = s.top();
        s.pop();

        areaWithTop = arr[tp] * (s.empty() ? i : i - s.top() - 1);
        maxArea = max(maxArea, areaWithTop);
    }

    return maxArea;
}

// Driver function
int main(){
    // vector<int> arr({2, 1, 5, 6, 2, 3});
    vector<int> arr({3,6,5,7,4,8,1,0});

    cout << largestRectangleArea(arr) << endl;

    return 0;
}
/*
[3,6,5,7,4,8,1,0], 20
*/
