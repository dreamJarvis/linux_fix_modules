// https://leetcode.com/problems/largest-rectangle-in-histogram/
// using segment Tree approach
#include <bits/stdc++.h>
using namespace std;

// A utility function to find minimum of three integers
int max(int x, int y, int z)
{ return max(max(x, y), z); }

// utility function to get minimum of 2 numbers in hist[]
int minVal(int *hist, int i, int j){
    if(i == -1) return j;
    if(j == -1) return i;
    return ((hist[i] < hist[j]) ? i:j);
}

// a utility function to get the middle index from corner indexes
int getMid(int s, int e){
    return (s + (e - s)/2);
}

/*
    a recursive function to get index of minimum value in given range of indexes.
    hist  --> input array for which the segment Tree is built
    st    --> pointer to segment tree
    index --> index of current node in the segment tree.
              Initially 0 is passed as root is always at index 0
    ss & se --> starting and ending indexes of segment represented by current node, i.e. st[index]
                i.e. the index will represent the value it will store for this range [ss, se]
    qs & qe --> starting and ending of query range
*/
int RMQUtil(int *hist, int *st, int ss, int se, int qs, int qe, int index){
    // if our query lies in the range, then return minimum of this segment
    // full overlap
    if(qs <= ss && qe >= se)
        return st[index];

    // if segments of this node is outside the given range
    // no overlap
    if(se < qs || ss > qe)
        return -1;

    // partial overlap
    int mid = getMid(ss, se);
    return minVal(
        hist,
        RMQUtil(hist, st, ss, mid, qs, qe, 2*index+1),
        RMQUtil(hist, st, mid+1, se, qs, qe, 2*index+2)
    );
}

// return index of minimum element in range from index qs(query start) to q(query end)
int RMQ(int *hist, int *st, int n, int qs, int qe){
	// Check for erroneous input values
	if (qs < 0 || qe > n-1 || qs > qe){
		cout << "Invalid Input";
		return -1;
	}

	return RMQUtil(hist, st, 0, n-1, qs, qe, 0);
}

// recusivley constructing the segment tree of range minimum query
int constructSTUtil(int hist[], int ss, int se, int *st, int si){
    /*
        store the indexes of orginal element at the leaf nodes,
        which are the element in the original array
    */
    if(ss == se)
        return (st[si] = ss);

    /* the current index, i.e. the parent will store minimum values in it's whole sub-tree */
    int mid = getMid(ss, se);
    st[si] = minVal(
        hist,
        constructSTUtil(hist, ss, mid, st, 2*si+1),
        constructSTUtil(hist, mid+1, se, st, 2*si+2)
    );

    return st[si];
}

// constuct segment tree for the given array, --> range minimum query
int *constuctST(int hist[], int n){
    int x = (int)(ceil(log2(n)));                   // height of the tree
    int maxSize = 2*(int)pow(2, x) - 1;             // maximum size of the segment tree

    // constructing the segment treee array
    int *st = new int[maxSize];

    // filling the segment tree array
    constructSTUtil(hist, 0, n-1, st, 0);

    return st;
}

// to find the maximum rectangular area recursvely
// tc : O(n * log(n))
int getMaxAreaRec(int *hist, int *st, int n, int l, int r){
    // base case
    if(l > r)   return INT_MIN;
    if(l == r)  return hist[l];

    /* find the index of the minimum value in the given range
       takes O(log(n)) -- for every recursion
    */
    int m = RMQ(hist, st, n, l, r);

    /* Return maximum of the following 3 possible cases
        1) maximum area in the left of min value (not including the min)
        2) maximum area in the right of min value (not include the min)
        3) maximum area including min
    */

    return max(
        getMaxAreaRec(hist, st, n, l, m-1),            // maximum area to the left
        getMaxAreaRec(hist, st, n, m+1, r),            // maximum area to the right
        ((r-l+1)*(hist[m]))
    );
}

// finding max area
int getMaxArea(int hist[], int n){
    int *st = constuctST(hist, n);          // O(n)

    return getMaxAreaRec(hist, st, n, 0, n-1);  // O(log(n))
}

// Driver function
int main(){
    int hist[] = {12, 3, 5, 7, 23, 11, 12, 6};
    int n = sizeof(hist)/sizeof(hist[0]);

    cout << "Maximum area : " << getMaxArea(hist, n) << endl;

    return 0;
}
