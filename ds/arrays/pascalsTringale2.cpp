// leetcode : Pascal's Triangle II
#include <bits/stdc++.h>
using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> row;
    for(int i = 0; i <= rowIndex; i++){
        row.push_back(1);
        for(int j = i-1; j > 0; j--){
            row[j] = row[j]+row[j-1];
        }
    }

    return row;
}

// Driver function
int main(){
    int n = 3;

    for(auto i:getRow(n))
        cout << i << " ";
    cout << endl;

    return 0;
}
