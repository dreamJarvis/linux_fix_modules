// 1252. Cells with Odd Values in a Matrix
#include <bits/stdc++.h>
using namespace std;

// brute force solution
// time complexity : O(n*m)
// space complexity : O(n*m)
int oddCells(int n, int m, vector<vector<int>>& indices) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<int>> result(n, vector<int>(m, 0));

    // updating the matrix bu indices values
    for(int i = 0; i < indices.size(); i++){
        int row = indices[i][0];
        int col = indices[i][1];

        // updating the row
        for(int i=0; i < m; i++){
            result[row][i] += 1;
        }

        for(int i = 0; i < n; i++){
            result[i][col] += 1;
        }
    }

    // calculating the odd value cells
    int count = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(result[i][j]%2!=0)
                count++;

    return count;
}

// time complexity : O(n*m)
// space complexity : O(n + m)
int oddCells4(int n, int m, vector<vector<int>>& indices) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unordered_map<int, int> rows, cols;
    for(int i = 0; i < n; i++)
        rows[i]=0;
    for(int i = 0; i < m; i++)
        cols[i]=0;

    for(auto &p : indices){
        // rows
        if(rows.count(p[0])){
            rows[p[0]]++;
        }else
            rows[p[0]]=1;

        // cols
        if(cols.count(p[1])){
            cols[p[1]]++;
        }else{
            cols[p[1]]=1;
        }
    }

    int count = 0;
    for(auto &r:rows){
        for(auto &c:cols){
            if((r.second+c.second)%2!=0)    count++;
        }
    }

    return count;
}

// editorial solution
int oddCells2(int n, int m, vector<vector<int>>& indices) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<int>>v(n,vector<int>(m,0));
    for(int i=0;i<indices.size();i++)
    {
        for(int j=0;j<m;j++)
        {
            v[indices[i][0]][j]++;
        }
        for(int j=0;j<n;j++)
        {
            v[j][indices[i][1]]++;
        }
    }
    int x=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v[i][j] &1)
                x++;
        }
    }
    return x;
}

// optimised
// time complexity : O(n)
// space complexity : O(1)
// youtube link : https://www.youtube.com/watch?v=Z49SHHLzq4w
int oddCells3(int n, int m, vector<vector<int>>& indices) {
    int odds = 0;
    unordered_set<int> rows{};
    unordered_set<int> cols{};
    for (const auto & p : indices){
        // hr barr jb p[0] ki vlaue even times aayegi, tb tb wo values ko delete krta rhega
        if(rows.count(p[0]) == 0){
            rows.insert(p[0]);
        }
        else{
            rows.erase(p[0]);
        }
        // Same for columns
        if(cols.count(p[1]) == 0){
            cols.insert(p[1]);
        }
        else{
            cols.erase(p[1]);
        }
    }

    return rows.size() * (m - cols.size()) + cols.size() * (n - rows.size());
}


// Driver frunction
int main(){
    int n = 2, m = 3;
    vector<vector<int>> indices({
                    {0,1},
                    {1,1}
    });

    cout << oddCells4(n, m, indices) << endl;

    return 0;
}
