/*
    Maximize The Cut Segments
    https://practice.geeksforgeeks.org/problems/cutted-segments/0
    https://www.techiedelight.com/rot-cutting/
*/
#include <iostream>
#include <unordered_map>
#include <climits>
#include <cstring>
using namespace std;

// ======================================== Memo ==================================== //
// tc : O(n*L)
// sc : O(n*L)
int util(int L, int *segments, int n, unordered_map<string, int> &dp){
    string key = to_string(L) + '_' + to_string(n);

    // base cases
    if(n < 0)
        return INT_MIN;

    if(L == 0)
        return 0;

    if(segments[n] > L)
        return util(L, segments, n-1, dp);
    else{
        if(!dp[key]){
            dp[key] = max(
                    1 + util(L-segments[n], segments, n, dp),
                    util(L, segments, n-1, dp)
                );
        }
    }

    return dp[key];
}

int maxSegments(int L, int segments[]){
    unordered_map<string, int> dp;
    return util(L, segments, 2, dp);
}

// ====================================== Top Down ==========================================//
// tc : O(n*L)
// sc : O(n*L)
int maxSegmentCut(int L, int segs[]){
    int dp[4][L+1];
    memset(dp, 0, sizeof(dp));

    // initialization
    for(int i = 0; i <= L; i++)
        dp[0][i] = INT_MIN;

    for(int i = 0; i < 4; i++)
        dp[i][0] = 0;

    for(int i = 1; i < 4; i++){
        for(int j = 1; j <= L; j++){
            if(j-segs[i-1] >= 0)
                dp[i][j] = max(dp[i-1][j], 1 + dp[i][j-segs[i-1]]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[3][L];
}

// Driver function
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--){
        int l;
        cin >> l;

        int arr[3];
        for(int i = 0; i < 3; i++)
            cin >> arr[i];

        cout << maxSegments(l, arr) << endl;
        // cout << maxSegmentsTopDown(arr, l, 3) << endl;
    }

    return 0;
}
