/*
    84. Largest Rectangle in Histogram
    https://leetcode.com/problems/largest-rectangle-in-histogram/
*/
#include <bits/stdc++.h>
using namespace std;

// int largestRectangleArea(vector<int>& heights){
//     int n = heights.size();
//
//     int maxArea = 0;
//     stack<int> s;
//     int i;
//     for(i = 0; i < n; i++){
//         int area = 0;
//         while(!s.empty() && heights[i] < heights[s.top()]){
//             int tp = s.top();
//             s.pop();
//             area = heights[tp]*(s.empty() ? i : (i-s.top()-1));
//             maxArea = max(maxArea, area);
//         }
//
//         s.push(i);
//     }
//
//     while(!s.empty()){
//         int tp = s.top();
//         s.pop();
//         int area = heights[tp]*(s.empty()? i : (i-s.top()-1));
//         maxArea = max(area, maxArea);
//     }
//
//     return maxArea;
// }

int largestRectangleArea(vector<int> &arr){
    int n = arr.size();

    int maxArea = 0;

    if(n == 0)  return maxArea;

    vector<int> nsl(n, -1);
    vector<int> nsr(n, n);

    stack<int> s;
    for(int i = n-1; i >= 0; i--){
        while(!s.empty() && arr[i] < arr[s.top()]){
            nsl[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    stack<int> p;
    for(int i = 0; i < n; i++){
        while(!s.empty() && arr[i] < arr[s.top()]){
            nsr[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    for(int i = 0; i < n; i++){
        int area = arr[i]*(nsr[i]-nsl[i]-1);
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main(){
    vector<int> heights({2, 1, 5, 6, 2, 3});
    // vector<int> heights({1, 1});

    cout << largestRectangleArea(heights) << endl;

    return 0;
}
