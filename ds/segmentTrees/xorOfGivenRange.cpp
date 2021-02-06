// XOR of given range
/*
We have an array arr[0 . . . n-1]. There are two type of queries

Find the XOR of elements from index l to r where 0 <= l <= r <= n-1
Change value of a specified element of the array to a new value x. We need to do arr[i] = x where 0 <= i <= n-1.

Leetcode : https://leetcode.com/problems/xor-queries-of-a-subarray/submissions/
*/
#include <bits/stdc++.h>
using namespace std;

// tc:  O(nlog(n))
int RXQ(vector<int> &arr, vector<int> &st, int ss, int se, int si, int qs, int qe){
    // total overlap
    if(qs <= ss && qe >= se)
        return st[si];

    // no overlap
    if(qs > se || qe < ss)
        return -1;

    // partial overlap
    int mid = (ss + (se - ss)/2);

    int left = RXQ(arr, st, ss, mid, 2*si+1, qs, qe);
    int right = RXQ(arr, st, mid+1, se, 2*si+2, qs, qe);

    if(left == -1)  return right;
    if(right == -1) return left;
    return (left ^ right);
}

int constuctST(vector<int> &arr, vector<int> &st, int ss, int se, int si){
    // filling the leaf nodes, and returing them
    if(ss == se){
        st[si] = arr[ss];
        return st[si];
    }

    int mid = (ss + (se - ss)/2);
    st[si] = (constuctST(arr, st, ss, mid, 2*si+1) ^ (constuctST(arr, st, mid+1, se, 2*si+2)));
    return st[si];
}

vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    int n = arr.size();
    int x = (int)(ceil(log2(n)));
    int stHeight = 2*(int)pow(2, x) - 1;

    vector<int> st(stHeight, 0);

    constuctST(arr, st, 0, n-1, 0);

    vector<int> ans;
    for(auto i:queries){
        int qs = i[0];
        int qe = i[1];

        int result = RXQ(arr, st, 0, n-1, 0, qs, qe);
        ans.push_back(result);
    }

    return ans;
}

// Efficient algorithm
// tc : O(n)
vector<int> xorQueries(vector<int>& A, vector<vector<int>>& queries) {
    vector<int> res;
    for (int i = 1; i < A.size(); ++i)
        A[i] ^= A[i - 1];

    for (auto &q: queries)
        res.push_back(q[0] > 0 ? A[q[0] - 1] ^ A[q[1]] : A[q[1]]);

    return res;
}

// Driver function
int main(){
    vector<int> arr({1, 3, 4, 8});
    vector<vector<int>> queries({
        {0, 1},
        {1, 2},
        {0, 3},
        {3, 3}
    });

    vector<int> result = xorQueries(arr, queries);

    for(auto i:result)
        cout << i <<" ";
    cout << endl;

    return 0;
}
