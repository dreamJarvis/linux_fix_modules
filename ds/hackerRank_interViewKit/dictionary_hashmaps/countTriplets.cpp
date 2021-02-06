// hackerRank : count triplets
// solution : https://www.youtube.com/watch?v=tBFZMaWP0W8
#include <bits/stdc++.h>
using namespace std;

// solution : 1
// time complexity : O(n)
// space complexity : 2*O(n)

/*
    so what are the information we recived from the question
    there has to be 3 elements, who should be in a Geometric progression, i.e.
    a, ar, a*r*r........a*r^n
    or
    a/r, a, a*r,....
    and also there indexes should be in increaseing order, i.e. i < j < k

    constraints:
    1 <= n <= 10^5
    1 <= r <= 10^9
    1 <= arr[i] <= 10^9

    so, yes constraints are quite large, so we will use long insead of int
    because of the constraints on indexes, we have to make sure that we dont take any value of wrong index

    in the solution below, we take 2 maps,
    rightElements and leftElements
    rightElements : it constraints all the unique elements and their frequency
    leftElements : it is empty
    now what is their function

    for every current i'th elements we will check if a number arr[i]/r is present in the leftElements map,
    and an element arr[i]*r is present in the rightElements map
    we will do that by traversing the whole array given to us

    ans while we traverse we will shift the current element from the rightElements side to the leftElements, as we are literally leaving the element behind

    ex : {1, 3, 9, 9, 27, 81}
    r = 3

    rightElements: [ [1:1], [3:1], [9:2], [27:1], [81:1]];
    leftElements : []

    now we traverse
        for i = 0 to n

        i == 0
        currentElement = arr[0];

        rightElements[arr[0]]--;    // so we dont take this as next element by mistake

        totalTriplets += leftElements[arr[0]/r] + rightElements[arr[0]*r];

        leftElements[arr[0]]++;

        // leftElements : [[1:1]]
        // rightElements : [[1:0], [3:1], [9:2], [27:1], [81:1]]


        i == 1
        currentElement = arr[1];

        rightElements[arr[1]]--;    // so we dont take this as next element by mistake

        totalTriplets += leftElements[arr[1]/r] + rightElements[arr[1]*r];

        leftElements[arr[1]]++;

        // leftElements : [[1:1], [3:1]]
        // rightElements : [[1:0], [3:0], [9:2], [27:1], [81:1]]

        .
        .
        .

        similarly
        i == n-1
        currentElement = arr[n-1];

        rightElements[arr[n-1]]--;    // so we dont take this as next element by mistake

        totalTriplets += leftElements[arr[n-1]/r] + rightElements[arr[n-1]*r];

        leftElements[arr[n-1]]++;

        // leftElements : [[1:1], [3:1], [9:2], [27:1], [81:1]
        // rightElements : [[1:0], [3:0], [9:0], [27:0], [81:0]]
*/
long countTriplets(vector<long> arr, long r) {
    int n = arr.size();

    // storing frequency of all the elements
    unordered_map<long, long> leftElements;
    unordered_map<long, long> rightElements;
    for(auto i:arr)
        rightElements[i]++;

    // to count the total number of triplets
    long totalTriplets = 0;

    // gp : a/r, a, ar
    for(long i = 0; i < n; i++){
        rightElements[arr[i]]--;

        // we do this because, id we have arr { 1, 4, 12} ,r = 3
        // then for i = 1, 4/3 == 1, which will be available in the left array, and 4*3 == 12, but we know we should have 1, 3, 9 instead of 1, 4, 12,.
        // so we simply put an condition that the arr[i]%r == 0, so we only consider them as triplets if thay all are divisible by r
        if(arr[i]%r == 0)
            totalTriplets += (leftElements[arr[i]/r] * rightElements[arr[i]*r]);

        leftElements[arr[i]]++;
    }

    return totalTriplets;
}


// solution : 2
#define lli long long int

long countTriplets2(vector<long> arr, long r) {
    map<lli, lli> map_c, map_b;

    lli count = 0;
    lli n = arr.size();

    // here a number can be an A or a B or a C from
    // Geometric progression triplet (A, B, C) with
    // ratio r.
    for (int i = 0; i < n; i++) {
        // number is a C the update the final count
        count += map_c[arr[i]];

        // number is a B
        // add number of Bs that exist into into Cs
        map_c[arr[i] * r] += map_b[arr[i]];

        // number is an A
        // this means add the count of it being B
        map_b[arr[i] * r]++;
    }

    return count;
}

// Driver function
int main(){
    // vector<long> arr({1, 4, 12});
    // int r = 3;

    // vector<long> arr({1, 4, 16, 64});
    // int r = 4;

    // vector<long> arr({1, 2, 2, 4});
    // int r = 2;

    // vector<long> arr({1, 3, 9, 9, 27, 81});
    // int r = 3;

    // vector<long> arr({1, 5, 5, 25, 125});
    // int r = 5;

    vector<long> arr({  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1, 1, 1, 1, 1, 1
                    });
    int r = 1;

    cout << countTriplets(arr, r) << endl;
    cout << countTriplets2(arr, r) << endl;

    return 0;
}
/*
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/
