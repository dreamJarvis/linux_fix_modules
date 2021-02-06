#include <bits/stdc++.h>
using namespace std;

vector<bool> processQueries(int arr[], int n, vector<pair<int, int>> &queries, int q){
    vector<bool> ans;

    int left[n];
    int right[n];

    // initialize first left index as that index only
    left[0] = 0;
    int lastIncr = 0;

    for(int i = 1; i < n; i++){
        /*
            if current value is greater than previous,
            update last increasing
        */
        if(arr[i] > arr[i-1])
            lastIncr = i;
        left[i] = lastIncr;
    }

    right[n-1] = n-1;
    int firstDecr = n-1;

    for(int i = n-2; i >= 0; i--){
        /*
            if current value is greater then next,
            update the first decreasing
        */
        if(arr[i] > arr[i+1])
            firstDecr = i;
        right[i] = firstDecr;
    }


    // for(int i = 0; i < n; i++)
    //     cout << arr[i] << " ";
    // cout << endl;
    //
    // for(int i = 0; i < n; i++)
    //     cout << left[i] << " ";
    // cout << endl;
    //
    // for(int i = 0; i < n; i++)
    //     cout << right[i] << " ";
    // cout << endl;

    for(int i = 0; i < q; i++){
        int st = queries[i].first;
        int end = queries[i].second;

        if(right[st] >= left[end])
            ans.push_back(true);
        else
            ans.push_back(false);
    }

    return ans;
}

// Driver function
int main(){
    // int arr[] = {2,3,2,4,4,6,3,2};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // vector<pair<int, int>> queries;
    // queries.push_back({0, 2});
    // queries.push_back({1, 3});
    // queries.push_back({3, 3});

    int arr[] = {5, 4, 3, 2, 6, 7, 5, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<pair<int, int>> queries;
    queries.push_back({0, 5});

    for(auto i:processQueries(arr, n, queries, queries.size())){
        if(i)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    cout << endl;

    return 0;
}
