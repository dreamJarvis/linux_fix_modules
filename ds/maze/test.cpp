#include <bits/stdc++.h>
using namespace std;

int maximumArea(vector<int> &arr1, unordered_map<int, bool> &arr2){
    int sum = 0;
    int temp;
    for(int i = 0; i < arr1.size(); i++){
        int MaxDia = arr1[i];
        for(auto val: arr2){
            if(val.second){
                if(MaxDia < min(arr1[i], val.first)){
                    MaxDia = val.first;
                    temp = val.first;
                }
            }
        }
        sum += MaxDia;
        arr2[temp] = false;
    }

    return sum;
}

// Driver function
int main(){
    int testCases = 0;
    int n;

    cin >> testCases;

    int val1, val2;
    for(int i = 0; i < testCases; i++){
        vector<int> l1;
        vector<int> l2;
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> val1;
            l1.push_back(val1);
        }

        for(int j = 0; j < n; j++){
            cin >> val2;
            l2[val2] = true;
        }

        sort(l1.begin(), l1.end());
        sort(l2.begin(), l2.end());
        cout<< maximumArea(l1, l2) << endl;
    }

    return 0;
}
