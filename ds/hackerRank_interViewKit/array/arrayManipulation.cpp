// hackerRank : ArrayManipulation
#include <bits/stdc++.h>
using namespace std;

// // brute force : we will add number in the range specified in every query
// TLE
// tc: O(n*m + n), n -> the largest number, m --> size of the query
// long arrayManipulation(int n, vector<vector<int>> queries) {
//     int querySize = queries.size();
//     int maxValue = INT_MIN;
//
//     int result[n] = {0};
//     for(int i = 0; i < querySize; i++){
//         for(int j = queries[i][0]; j < queries[i][1]; j++){
//             result[j] += queries[i][2];
//             maxValue = max(maxValue, result[j]);
//         }
//     }
//
//     return maxValue;
// }

// using prefix-array sum technique:
/*  In this technique we will first set out markers..
    what markers ?
    just go along you will understand at the end of it
    okay...
    So, as i was saying, when we go through each query, we get the starting index & ending index
    as told in the question, it's inclusize [x, y]
    Now coming back to marker analogy, what we do is, we initialize an array of size n + 1, i.e. 1 + the
    n, lets call it arr[]
    Now we iterate through each query , and we add the value of that query to..
        arr[starting_index] += value;
    and we subtract the same value for the ending index to,
        arr[ending_index + 1] -= value;

    why are we doing all these ?
    well you see when we apply prefix sum to arr[] after iterating it through the query, what it does is it starts adding values from the starting_index to the end of the array

    but then if it adds tha value to the end, it defiles the purpose of having an range, it will add value irrespective of the range and our answer will be incorrect

    yeah exactly !!, so inorder to correct it, what we did was we subtracted the vaue of this particular query at arr[ending_index + 1], so that when the prefix sum, whose is just adding the values irrespective of the range, goes across the range, i.e. it reaches ending_index + 1 index of array, which has -ve value, .'. when the range is crossed no value will be added.

    this is the whole reason why we add and subtracted value in array, to provide addition of value in range

    lets take an example:
    int n = 5,
    starting_index  ending_index    value
        1,              2,           100
        2,              5,           100
        3,              4,           100

    now acc. to our algo we will create an array of 6 size, initialize it with 0
    0  1  2  3  4  5  6             --> index
    0, 0, 0, 0, 0, 0, 0             --> values

    while iterating through each query we will perform adding and subtracting of value at relative positions acc. to the algo

    while iterating through 1'st query
    0   1   2    3   4  5  6           --> index
    0, 100, 0, -100, 0, 0, 0           --> values

    as we observed that we added the value of 1st query at the starting_index,
    i.e. arr[1] += 100, and
    subtracted value at :
        arr[3] -= 100

    doing the same thing for all the queries
    we will get

    for 2'nd query:
    0    1     2      3    4   5    6
    0,  100,  100,  -100,  0,  0, -100

    for 3'rd query:
    0    1     2    3   4    5    6
    0,  100,  100,  0,  0, -100, -100

    now, applying prefix sum
    0, 100, 200, 200, 200, 100, 0

    so, max sum is 200
*/

// tc : O(m + n)
long arrayManipulation(int n, vector<vector<int>> queries) {
    int querySize = queries.size();
    vector<long> arr(n+2, 0);

    for(int i = 0; i < querySize; i++){
        arr[queries[i][0]] += queries[i][2];
        arr[queries[i][1] + 1] -= queries[i][2];
    }

    long maxValue = arr[0];
    for(int i = 1; i < n+2; i++){
        arr[i] += arr[i-1];
        maxValue = max(maxValue, arr[i]);
    }

    // to display the resultant array
    // for(auto i:arr)
    //     cout << i << " ";
    // cout << endl;

    return maxValue;
}

// Driver function
int main(){
    // int n = 10;
    // vector<vector<int>> queries({
    //     {1, 5, 3},
    //     {4, 8, 7},
    //     {6, 9, 1}
    // });
    int n = 5;
    vector<vector<int>> queries({
        {1, 2, 100},
        {2, 5, 100},
        {3, 4, 100}
    });
    // int n = 10;
    // vector<vector<int>> queries({
    //     {2, 6, 8},
    //     {3, 5, 7},
    //     {1, 8, 1},
    //     {5, 9, 15}
    // });

    cout << arrayManipulation(n, queries) << endl;

    return 0;
}
/*
10 4
2 6 8
3 5 7
1 8 1
5 9 15
*/
