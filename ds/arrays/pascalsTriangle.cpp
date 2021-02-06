// 118. Pascal's Triangle
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> arr(numRows);

    arr[0] = vector<int>({1});
    if(numRows == 1){
        return arr;
    }

    arr[1] = vector<int>({1, 1});
    if(numRows == 2){
        return arr;
    }

    for(int i = 2; i < numRows; i++){
        vector<int> col;
        int j;

        col.push_back(1);
        for(j = 0; j < arr[i-1].size()-1; j++){

            int sum = arr[i-1][j] + arr[i-1][j+1];
            col.push_back(sum);
        }
        col.push_back(1);

        arr[i] = col;
    }

    return arr;
}

// vector<vector<int>> generate(int numRows) {
//     vector<vector<int>> result(numRows);
//
//     vector<int> row;
//     for(int i = 0; i < numRows; i++){
//         row.push_back(1);
//
//         int temp = row[0], temp2 = row[0];
//         for(int j = 1; j < i; j++){
//             temp2 = row[j];
//             row[j] = row[j] + temp;
//             temp = temp2;
//         }
//
//         result.push_back(row);
//     }
//
//     return result;
// }

// vector<vector<int>> generate(int numRows) {
//     vector<vector<int>> result;
//     vector<int> row;
//
//     for(int i = 0; i < numRows; i++){
//          row.push_back(1);
//
//          for(int j = i - 1; j > 0; j--){
//              row[j] = row[j - 1] + row[j];
//          }
//
//          result.push_back(row);
//      }
//
//     return result;
// }

// Driver function
int main(){
    int n = 5;

    for(auto i:generate(n)){
        for(auto k:i)
            cout << k << " ";
        cout << endl;
    }

    return 0;
}
