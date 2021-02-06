#include <bits/stdc++.h>
using namespace std;

// find the maximum area
// Submission TLE
int maximumArea(vector<int> &arr1, vector<int> &arr2){
    int sum = 0;
    int temp = -1;


    for(int i = 0; i < arr1.size(); i++){

        int MaxDia = arr1[i];
        for(int j = 0; j < arr1.size(); j++){
            if(MaxDia > min(arr1[i], arr2[j])){
                MaxDia = arr2[j];
                temp = j;
            }
        }

        sum += MaxDia;

        if(temp != -1){
            arr2[temp] = INT_MAX;
        }
    }

    return sum;
}

// Driver function
int main(){
    int testCases = 0;
    int n;

    cin >> testCases;

    vector<int> l1;
    vector<int> l2;
    int val1, val2;

    for(int i = 0; i < testCases; i++){
        cin >> n;

        for(int j = 0; j < n; j++){
            cin >> val1;
            l1.push_back(val1);
        }
        
        for(int j = 0; j < n; j++){
            cin >> val2;
            l2.push_back(val2);
        }

        // sort(l1.begin(), l1.end());
        // sort(l2.begin(), l2.end());
        cout << maximumArea(l1, l2) << endl;
        l1.clear();
        l2.clear();
    }

    return 0;
}