// 84. Largest Rectangle in Histogram
#include <bits/stdc++.h>
using namespace std;

// method I
// O(n)
int largestRectangleArea(vector<int>& arr) {
    int n = arr.size();
    stack<int> s;
    int maxHistogramArea = 0;
    int i = 0;

    for(; i < n; i++){
        while(!s.empty() && arr[s.top()] > arr[i]){
            int tp = s.top();
            s.pop();

            int area = arr[tp] * (s.empty() ? i : (i - s.top() - 1));
            maxHistogramArea = max(maxHistogramArea, area);
        }

        s.push(i);
    }

    while(!s.empty()){
        int tp = s.top();
        s.pop();

        int area = arr[tp] * (s.empty() ? i : (i - s.top() - 1));
        maxHistogramArea = max(maxHistogramArea, area);
    }

    return maxHistogramArea;
}

// method II
// tc : 3*O(n)
/*
    for the current Histogram to expand the elements to it's left, right should be greater
    then the current Histogram, cause then only it would be fully contained in btw them

    so, we will find the next smallar element index to the left of our current Histogram,
    and next smaller element index to the right of our current Histogram.

    these left and right smaller elements indexes will provide us with the bound under which our Histogram can expand,
*/
int largestRectangleAreaII(vector<int> &arr){
    int n = arr.size();
    int maxArea = 0;

    if(n == 0)  return maxArea;

    /* stores left and right next smaller indexs of the element at i'th index
        we have initialized every value with -1 in the nsl, bacause if we can't find the next smaller to the left that means ,
        current histogram goes all the way to the left, */

    // similarly we have initialized nsr with n, as if we can't find an element smaller than the current to its right,
    // then it means it goes all the way

    /* ans also while calculating the area btw smaller index we are exculing the length provided by these indexes,
    as our area is contained within then, then when our  element covers the full index of left,
    -1 helps us include the left index
    similarly for the nsr, n helps us include the right index,
    when our element goed all the way right */
    vector<int> nsl(n, -1);
    vector<int> nsr(n, n);

    // next smallest elements intdex to the left
    stack<int> s;
    for(int i = n-1; i >= 0; i--){                        // O(n)
        while(!s.empty() && arr[i] < arr[s.top()]){
            nsl[s.top()] = i;
            s.pop();
        }

        s.push(i);
    }

    // next smallest elements intdex to the right
    stack<int> p;
    for(int i = 0; i < n; i++){                         // O(n)
        while(!s.empty() && arr[i] < arr[s.top()]){
            nsr[s.top()] = i;
            s.pop();
        }

        s.push(i);
    }

    // to find the area contained btw the left and right indexes
    for(int i = 0; i < n; i++){                         // O(n)
        int area = arr[i]*(nsr[i]-nsl[i]-1);
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

// Driver function
int main(){
    // vector<int> arr({2, 1, 5, 6, 2, 3});
    // vector<int> arr({1, 1});
    vector<int> arr({1});
    // vector<int> arr({9, 0});
    // vector<int> arr({2, 4});

    // cout << largestRectangleArea(arr) << endl;

    cout << maximalAreaHistogram(arr) << endl;

    return 0;
}
