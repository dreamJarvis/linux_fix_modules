// 85. Maximal Rectangle
#include <bits/stdc++.h>
using namespace std;

void maximalRectangle(vector<vector<char>>& arr) {
    int row = arr.size();
    int col = arr[0].size();

    // dp table
    vector<vector<int>> rw(row, vector<int>(col, 0));
    vector<vector<int>> cw(row, vector<int>(col, 0));
    vector<vector<int>> maxSq(row, vector<int>(col, 0));

    for(int i = 0; i < col; i++){
        cw[0][i] = (arr[0][i]-'0');
    }

    // for(int i = 0; i < row; i++){
    //     for(int j = 0; j < col; j++)
    //         cout << cw[i][j] << " ";
    //     cout << endl;
    // }

    for(int i = 1; i < row; i++){
        for(int j = 0; j < col; j++){
            if(arr[i][j]-'0')
                cw[i][j] = cw[i-1][j] + (arr[i][j]-'0');
        }
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++)
            cout << cw[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    for(int i = 0; i < row; i++){
        rw[i][0] = (arr[i][0]-'0');
    }

    int side = 0;
    for(int i = 0; i < row; i++){
        int count = arr[i][0]-'0';
        for(int j = 1; j < col; j++){
            count++;
            if(arr[i][j]-'0' == 0){
                count = 0;
            }
            rw[i][j] = count ;
        }
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++)
            cout << rw[i][j] << " ";
        cout << endl;
    }

    cout << endl;

    int maxSquare = 0;
    for(int i = 1; i < row; i++){
        for(int j = 1; j < col; j++){

        }
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++)
            cout << maxSq[i][j] << " ";
        cout << endl;
    }

    cout << maxSquare << endl;
}

// Driver function
int main(){
    vector<vector<char>> arr({
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    });

    maximalRectangle(arr);

    return 0;
}
