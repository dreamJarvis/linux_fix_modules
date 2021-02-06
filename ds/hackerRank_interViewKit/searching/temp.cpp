/*Consider n machines which produce same type of items but at different rate i.e., machine 1 takes a1 sec to produce an item, machine 2 takes a2 sec to produce an item. Given an array which contains the time required by ith machine to produce an item. Considering all machine are working simultaneously, the task is to find minimum time required to produce m items.

reference : https://www.geeksforgeeks.org/minimum-time-required-produce-m-items/
hackerRank : minimum Time required
*/
#include <bits/stdc++.h>
using namespace std;

// brute force
long minTimeReq(vector<long> &arr, long goal){
    int n = arr.size();
    long t = 0;

    while(true){
        long task = 0;

        for(int i = 0; i < n; i++)
            task += (t/arr[i]);

        if(task >= goal)
            return t;

        t++;
    }

    return t;
}

// efficient method uing binary search
int findWorkDone(vector<long> &arr, int time){
    int n = arr.size();
    long ans = 0;
    for(auto i:arr)
        ans += (time/i);

    return ans;
}

long binarySearch(vector<long> &arr, int goal, int high){
    long low = 1;

    while(low < high){
        long mid = (low+high)/2;

        long workDone = findWorkDone(arr, mid);

        if(workDone < goal)
            low = mid+1;
        else
            high = mid;
    }

    return high;
}

long minTimeReqEffecient(vector<long> &arr, int goal){
    int n = arr.size();

    // maximum time required to get work done
    long maxTime = INT_MIN;
    for(auto i:arr)
        maxTime = max(maxTime, i);

    return binarySearch(arr, goal, maxTime*goal);
}

// Driver function
int main(){
    // vector<long> arr({2, 3, 2});
    // long goal = 10;
    vector<long> arr({2, 3});
    long goal = 5;
    // vector<long> arr({1, 3, 4});
    // long goal = 10;

    // cout << minTimeReq(arr, goal) << endl;
    cout << minTimeReqEffecient(arr, goal) << endl;

    return 0;
}
/*
*/
