// leetcode 11. Container With Most Water
#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& arr) {
    int n = arr.size();

    stack<int> s;
    s.push(0);

    int maxArea = 0;

    int i = 1;
    int area=0;
    for(i = 1; i < n; i++){
        int tp = s.top();
        if(arr[tp] >= arr[i]){
            area = arr[i]*(i-tp);
            maxArea = max(maxArea, area);

            cout << area << endl;
        }
        else if(arr[tp] < arr[i]){
            area = arr[tp]*(i-tp);
            maxArea = max(maxArea, arr[tp]*(i-tp));

            cout << area << endl;

            cout << "i : " << i << endl;

            s.push(i);
        }
    }

    int l = s.top();
    s.pop();

    while(!s.empty()){
        int tp = s.top();
        s.pop();
        for(int j = i-1; j > l; j--){
            if(arr[j] > arr[tp]){
                maxArea = max(maxArea, arr[tp]*(j-tp));
                cout << arr[tp]*(j-tp) << endl;
            }
            else{
                maxArea = max(maxArea, arr[j]*(j-tp));
                cout << arr[j]*(j-tp) << endl;
            }
        }
    }

    return maxArea;
}

// Driver function
int main(){
    // vector<int> arr({1,8,6,2,5,4,8,3,7});
    // vector<int> arr({/1, 1});
    vector<int> arr({1,2,3,4,5,6,7,8,9,10});


    cout << maxArea(arr) << endl;

    return 0;
}
/*
1, 1 : 0

1,2,3,4,5,6,7,8,9,10 : 25
*/
