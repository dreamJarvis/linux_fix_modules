/*
    Q) Queries for elements greater than K in the given index range using Segment Tree

    References :

    gfg : https://www.geeksforgeeks.org/queries-for-elements-greater-than-k-in-the-given-index-range-using-segment-tree/?ref=rp

    array of vectors : https://www.geeksforgeeks.org/array-of-vectors-in-c-stl/

*/
#include <bits/stdc++.h>
using namespace std;

/*
    time taken to traverse the query range : O(log(n))
    no of queries : q
    time taken by binary search for each query : O(log(n))
    total no of binary searches done : q*O(log(n))

    total time Complexity : O(log(n)*(q*(log(n))))
*/

// ======== performing queries ========== //
// performing queries on the qiven range
/*
    how do we find the no. of elements that are > k ?
    so now when we have an sorted array for each range , and we want to find the no. of elements > k
    so we can count it by looping it will take : O(n)
    or we can use binary search to find the element just smaller that it,
    so the difference btw its index and arr size will give us the count of total no of elements > k , tc : O(log(n))
*/
int query(vector<int> *tree, int index, int s, int e, int l, int r, int k){
    // out of bound
    if(r < s || l > e)
        return 0;

    // total overlap
    // query range completely lies in the segment Tree node
    if(s >= l && e <= r){
        // binary search to find the index of K
        int items = tree[index].size() - (lower_bound(tree[index].begin(), tree[index].end(), k) - tree[index].begin());

        return items;
    }

    // partially overlap
    // query range partially lies in the segment tree node
    int mid = (s + e)/2;
    return (
        query(tree, 2*index, s, mid, l, r, k) +
        query(tree, 2*index+1, mid+1, e, l, r, k)
    );
}

// function to perform queries : UTILITY function
// tc : O(q*log(n))
void performQueries(vector<vector<int>> &q, vector<int> tree[], int n){
    for(auto i:q){
        cout << query(tree, 1, 0, n-1, i[0]-1, i[1]-1, i[2]) << endl;
    }
}

// ==========================  consturcting segment tree ======================== //
// merge 2 vectors , in an sorted way
vector<int> merge(vector<int> &v1, vector<int> &v2){
    // final vector to return
    vector<int> v;

    int i = 0, j = 0;
    while(i < v1.size() && j < v2.size()){
        if(v1[i] <= v2[j]){
            v.push_back(v1[i]);
            i++;
        }
        else {
            v.push_back(v2[j]);
            j++;
        }
    }

    // the remaining elements are added to the resultant vector
    while(i < v1.size()){
        v.push_back(v1[i++]);
    }

    while(j < v2.size()){
        v.push_back(v2[j++]);
    }

    return v;
}

// build segment tree : UTILITY function
/* every i'th index represents an parent node and also a hild, and
    it also represents ans range in which it falls .
    so while constructing segment Tree, each node represents a range
    this range represents the elements in the original array.

    so for each i'th index in the segment tree,
    it will store all the element that lies in the range that represent it

    so how do we store it ?
    now we know the nodes in the tree that is
    height = 2 *( 2 * log(n)) - 1;

    what we dont know is the no. of elements stored in each node

    now if we take the nodes of the tree as row,
    elements stored in each row as col's
    then we can store the no. of elements for each node in it's i'th index in the segent tree

    we can use array of vector
    vector<int> arr[rowSize];

    array of vectors is two dimensional array with fixed number of rows where each row is vector of variable length.
    Each index of array stores a vector which can be traversed and accessed using iterators.

    here each row is node in the segent tree, and the no. of elements are stored in the vetor at each arrays index

    tc : O(log(n))
*/
void buildTree(vector<int> *tree, vector<int> &arr, int index, int s, int e){
    if(s == e){
        tree[index].push_back(arr[s]);
        return ;
    }

    int mid = (s+e)/2;
    buildTree(tree, arr, 2*index, s, mid);                  // we are given 1 bases indexing
    buildTree(tree, arr, 2*index+1, mid+1, e);

    // storing the final vector after merging the tow of its sorted child
    tree[index] = merge(tree[2*index], tree[2*index+1]);
}

// Driver function
int main(){
    vector<int> arr({7, 3, 9, 13, 5, 4});
    vector<vector<int>> query({
        {1, 4, 6},
        {2, 6, 8}
    });

    int n = arr.size();

    // Segment Tree :
    vector<int> tree[4*n+1];            // array of vectors

    // consturct a segment Tree
    buildTree(tree, arr, 1, 0, n-1);

    // performing all the given queries
    performQueries(query, tree, n);

    return 0;
}
