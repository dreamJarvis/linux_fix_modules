// leetcode 85. Maximal Rectangle
#include <bits/stdc++.h>
using namespace std;

// method 1 : using maximum area histogram
// O(n)
int largestRectangleArea(vector<int> &arr){
    int n = arr.size();
    int lra = 0;
    stack<int> s;
    int i = 0;
    for(; i < n; i++){
        while(!s.empty() && arr[s.top()] > arr[i]){
            int tp = s.top();
            s.pop();

            int area = arr[tp]*(s.empty() ? i : i-s.top()-1);
            lra = max(lra, area);
        }

        s.push(i);
    }

    while(!s.empty()){
        int tp = s.top();
        s.pop();

        int area = arr[tp]*(s.empty() ? i : i-s.top()-1);
        lra = max(lra, area);
    }

    return lra;
}

// O(n^2)
int maximalRectangle(vector<vector<char>>& arr) {
    int row = arr.size();
    int col = arr[0].size();

    vector<vector<int>> subArr(row, vector<int>(col, 0));
    int lra = 0;

    for(int i = 0; i < col; i++){
        subArr[0][i] = arr[0][i]-'0';
        lra = max(lra, subArr[0][i]);
    }

    for(int i=1; i < row; i++){                     // O(n)
        for(int j = 0; j < col; j++){
            if(arr[i][j]-'0'){
                subArr[i][j] = subArr[i-1][j]+1;    // O(n)
            }
        }
    }

    for(int i = 0; i < row; i++){
        vector<int> temp;
        for(int j = 0; j < col; j++)
            temp.push_back(subArr[i][j]);

        lra = max(lra, largestRectangleArea(temp));
    }

    return lra;
}

// using kadanes algo


// Driver function
int main(){
    vector<vector<char>> arr({
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    });

    cout << maximalRectangle(arr) << endl;

    return 0;
}
