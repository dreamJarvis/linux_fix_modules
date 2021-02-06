#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> SortBinaryArray(vector<int> arr){
    int i = 0, j = arr.size()-1;

    while(i < j){
        if(arr[i] == 1){
            swap(arr[i], arr[j]);
            j--;
        }
        else
            i++;
    }

    return arr;
}

int main(){
    // vector<int> arr({1,0,1,1,0});
    vector<int> arr({1,0,1,1,1,1,1,0,0,0});

    for(auto &i:SortBinaryArray(arr))
        cout << i << " ";
    cout << endl;

    return 0;
}
