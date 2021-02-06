/*
    Travelling Salesman Problem ( Hamiltonian Cycle )

    reference :
    https://www.geeksforgeeks.org/travelling-salesman-problem-set-1/
    https://www.youtube.com/watch?v=JE0JE8ce1V0
*/
#include <iostream>
#include <vector>
using namespace std;

#define INT_MAX 999999

// memoisation
// tc : O(N * 2^N)
// sc : O(N * 2^N)
// top-down approach --> (recursion + memoisation)
int tsmUtil(vector<vector<int>> &dist, int mask, int pos,
            vector<vector<int>> &dp, int N, int VISITED_ALL){
    if(mask == VISITED_ALL){
        return dist[pos][0];
    }

    // if this sub-route is already covered then return the distance
    if(dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;
    for(int city = 0; city < N; city++){
        // if this city is not visited, then visit it
        if((mask&(1<<city)) == 0){
            int newAns = dist[pos][city] +
                     tsmUtil(dist, (mask|(1<<city)), city, dp, N, VISITED_ALL);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int tsm(vector<vector<int>> &graph){
    const int N = graph.size();

    // dp table
    vector<vector<int>> dp((1<<N), vector<int>(N, -1));

    // initial mask and position value's indicating source postion is occupied
    int mask = 1, pos = 0;
    const int VISITED_ALL = (1<<N)-1;     // when the mask is full, ie. 11111..

    return tsmUtil(graph, mask, pos, dp, N, VISITED_ALL);
}

// Driver function
int main(){
    vector<vector<int>> graph({
        {0,  20, 42, 25},
        {20, 0,  30, 34},
        {42, 30, 0,  10},
        {25, 34, 10, 0}
    });

    cout << "Hamiltonian Distance :  " << tsm(graph) << endl;

    return 0;
}
