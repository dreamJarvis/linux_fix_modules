// leetcode : 566 ( reshape matrix )
#include <bits/stdc++.h>
using namespace std;

bool reshapeMatrix(vector<vector<int>> &arr, int r, int c){
    int row = arr.size();
    int col = arr[0].size();

    int givenNoOfElements = row*col;
    int requiredElements = r*c;

    vector<vector<int>> result(r, vector<int>(c, 0));
    if(givenNoOfElements == requiredElements){
        for(int i = 0; i < row*col; i++ ){
            int temp = arr[i/col][i%col];
            result[i/c][i%c] = temp;
        }

        arr = result;
        return true;
    }
    else    return false;
}

// Driver function
int main(){
    // input
    vector<vector<int>> arr({
                {1, 2},
                {3, 4}
    });

    int r = 1, c = 4;

    if(!reshapeMatrix(arr, r, c)){
        r = arr.size();
        c = arr[0].size();
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
