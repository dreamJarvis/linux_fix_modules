/*
    887. Super Egg Drop
    https://leetcode.com/problems/super-egg-drop/

    sol : https://leetcode.com/problems/super-egg-drop/discuss/792736/CPP-Explained-Recursive-greatermemoization-greateroptimization-greaterDP-oror-Well-Explained-oror-Easy-to-unserstand
*/
#include <bits/stdc++.h>
using namespace std;

// bottom up
// tc : O((N*K) *(log(N)))
// sc : O(N*K)
unordered_map<string, int> dp;
int superEggDrop(int K, int N) {
    string key = to_string(K) + to_string(N);

    if(K == 1)
        return N;

    if(N == 0 || N == 1)
        return N;

    if(dp.count(key))
        return dp[key];

    int ans = INT_MAX, temp;
    int low = 1, high = N;

    while(low <= high){
        int mid = (low + high)/2;
        int down = superEggDrop(K-1, mid-1);
        int up   = superEggDrop(K, N-mid);

        temp = 1 + max(down, up);

        if(down < up)
            low = mid + 1;
        else
            high = mid - 1;

        ans = min(ans, temp);
    }

    dp[key] = ans;
    return dp[key];
}

// Top down
// tc : O((N*K) *(log(N)))
// sc : O(N*K)
int superEggDropDP(int K, int N) {
    int dp[K+1][N+1];

    for(int i = 1; i <= K; i++){
        dp[i][1] = 1;
        dp[i][0] = 0;
    }

    for(int j = 1; j <= N; j++)
        dp[1][j] = j;

    for(int i = 2; i <= K; i++){
        for(int j = 2; j <= N; j++){
            dp[i][j] = INT_MAX;

            int ans = INT_MAX, temp;
            int low = 1, high = j;

            while(low <= high){
                int mid = (low + high)/2;
                int down = dp[i-1][mid-1];
                int up   = dp[i][j-mid];

                temp = 1 + max(down, up);

                if(down < up)
                    low = mid + 1;
                else
                    high = mid - 1;

                ans = min(ans, temp);
            }

            dp[i][j] = ans;
        }
    }

    return dp[K][N];
}

// Driver function
int main(){
    int K = 1, N = 2;
    // int K = 2, N = 6;
    // int K = 3, N = 14;

    cout << superEggDropDP(K, N) << endl;

    return 0;
}
