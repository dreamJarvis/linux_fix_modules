// reference : https://www.geeksforgeeks.org/minimum-time-required-produce-m-items/
#include <bits/stdc++.h>
using namespace std;

// brute force
long minTime(vector<long> arr, long goal) {
    int n = arr.size();

    int t = 0;
    while(true){
        int items = 0;
        for(int i = 0; i < n; i++)
            items += (t / arr[i]);

        if(items >= goal)
            return t;

        t++;
    }

    return t;
}

// efficient method
long findItems(vector<long> &arr, long time){
    long ans = 0;
    for(auto i:arr)
        ans += (time/i);
    return ans;
}

long bs(vector<long> &arr, long goal, long high){
    long low = 1;

    // doing binary search to find the minimum time
    while(low < high){
        long mid = (low+high)/2;

        // Calculates the no. of items that can be produced in mid time
        long item = findItems(arr, mid);

        if(item < goal)
            low = mid+1;
        else
            high = mid;
    }

    return high;
}

// retuns the maximum time required to produce m items
long maxTime(vector<long> &arr, long goal){
    long maxValue = INT_MIN;

    // finding the machine with the maximum time
    for(auto i:arr)
        maxValue = max(maxValue, i);

    return bs(arr, goal, maxValue*goal);
}

long minTimeEfficient(vector<long> arr, long goal){
    return maxTime(arr, goal);
}


int main(){
    vector<long> arr({2, 3, 2});
    long goal = 10;
    // vector<long> arr({2, 3});
    // long goal = 5;
    // vector<long> arr({1, 3, 4});
    // long goal = 10;

    // cout << minTime(arr, goal) << endl;
    cout << minTimeEfficient(arr, goal) << endl;


    return 0;
}
