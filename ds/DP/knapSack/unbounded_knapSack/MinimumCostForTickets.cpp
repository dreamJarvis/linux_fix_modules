/*
    983. Minimum Cost For Tickets
    https://leetcode.com/problems/minimum-cost-for-tickets/
*/
#include <bits/stdc++.h>
using namespace std;

#define MAX INT_MAX-1


// ======================================= Memoisation =================================== //
unordered_map<string, int> dp;
int util(vector<int> &days, vector<int> &costs, int *reference, int n, int range){
    string key = to_string(n);

    if(n >= days.size())
        return 0;

    if(range > days[days.size()-1])
        return 0;

    if(range > days[n])
        return util(days, costs, reference, n+1, range);

    if(dp[key])
        return dp[key];

    int totalCost = MAX;
    for(int i = 0; i < 3; i++){
        totalCost = min(
            totalCost,
            costs[i] + util(days, costs, reference, n+1, (days[n]+reference[i]))
        );
    }

    dp[key] = totalCost;
    return dp[key];
}

int mincostTickets(vector<int> &days, vector<int> &costs){
    int n = days.size();
    int reference[] = {1, 7, 30};

    return util(days, costs, reference, 0, 0);
}

// ================================== tabulation ============================= //
// O(n)
int mincostTicketsDP(vector<int>& days, vector<int>& costs){
    int n = days.size();
    int dp[366];
    memset(dp, 0, sizeof(dp));

    for(auto &day:days)
        dp[day] = costs[0];

    for(int i = 1; i <= days[n-1]; i++){
        if(!dp[i])
            dp[i] = dp[i-1];
        else{
            dp[i] = dp[i-1] + costs[0];

            int j = max(0, i-7);
            dp[i] = min(dp[i], dp[j] + costs[1]);

            j = max(0, i-30);
            dp[i] = min(dp[i], dp[j] + costs[2]);
        }
    }

    return dp[days[n-1]];
}

// Driver function
int main(){
    vector<int> days({1, 4, 6, 7, 8, 20});
    vector<int> costs({2, 7, 15});

    // vector<int> days({1,2,3,4,5,6,7,8,9,10,30,31});
    // vector<int> costs({2, 7, 15});

    cout << mincostTicketsMemo(days, costs) << endl;
    // cout << mincostTickets(days, costs) << endl;

    return 0;
}
/*
days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
*/
