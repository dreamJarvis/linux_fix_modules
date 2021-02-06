// Segment Trees
#include <bits/stdc++.h>
using namespace std;

// A utility function to get the middle index from corner indexes
int getMid(int s, int e) {  return s + (e-s)/2; }

/*
    A recursive function to get the sum of values in the given range of array.
    st --> pointer to segment tree
    si --> index of root node in the segment
    ss --> starting index of the current node
    se --> ending index of the current node
    qs --> starting index of the given node
    qe --> ending index of the given node
*/
int getSumUtil(int *st, int ss, int se, int qs, int qe, int si){
    // if current co-ordinates are sub-set of the given co-ordinates, then return the sum of the segment
    if(qs <= ss && qe >= se)    return st[si];

    if(se < qs || ss > qe)  return 0;

    int mid = getMid(ss, se);   // next root lake dega

    int leftChildSum = getSumUtil(st, ss, mid, qs, qe, 2*si+1);
    int rightChildSum = getSumUtil(st, mid+1, se, qs, qe, 2*si+2);

    return (leftChildSum + rightChildSum);
}

int getSum(int *st, int n, int qs, int qe){
    if(qs < 0 || qe > n-1 || qs > qe)   return -1;

    return getSumUtil(st, 0, n-1, qs, qe, 0);
}

/*
    A recursive function to update the nodes whoch have the given index in their given rane
    i    --> index of the element to be updateed. This index is in the input array
    diff --> value to be added to all nodes which have i in range
*/
void updateValueUtil(int *st, int ss, int se, int i, int diff, int si){
    // if the input lies outside the range of this segment
    if(i < ss || i > se)    return ;

    // if the input is in the range of this node, then update the vlaues of the node and its children
    st[si] = st[si] + diff;

    if(se != ss){
        int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*si+1);
        updateValueUtil(st, mid+1, se, i, diff, 2*si+2);
    }
}

void updateValue(int arr[], int *st, int n, int i, int new_val){
    if(i < 0 || i > n-1)    return;

    int diff = new_val - arr[i];
    arr[i] = new_val;

    updateValueUtil(st, 0, n-1, i, diff, 0);
}

// A recursive function that constructs segment tree for arrays[ss....se].
// si is index of current node in the segment tree st
int constructSTUtil(int arr[], int ss, int se, int *st, int si){
    // when there is 1 element left in the recusion, i.e. starting index == ending index
    // store it at i'th index
    if(ss == se){
        st[si] = arr[ss];
        return arr[ss];
    }

    // if there are more then one elements, then recur for left and right subtrees and store the sum of values in this node
    int mid = getMid(ss, se);
    int leftElement = constructSTUtil(arr, ss, mid, st, 2*si+1);
    int rightElement = constructSTUtil(arr, mid+1, se, st, 2*si+2);

    st[si] = leftElement + rightElement;
    return st[si];
}


// to constuct segment tree from given array
int *constructST(int arr[], int n){
    int x = (int)(ceil(log2(n)));            // height of segment tree
    int max_size = 2*((int)pow(2,x))-1;      // max size of segment trees
    int *st = new int[max_size];             // initializing new array

    constructSTUtil(arr, 0, n-1, st, 0);
    return st;
}

// Driver function
int main(){
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    int *st = constructST(arr, n);

    cout << "sum of values in given range = " << getSum(st, n, 1, 3) << endl;

    // update arr[1] = 10, and update corresponding setgment
    updateValue(arr, st, n, 1, 10);

    cout << "Update sum of values in given range = " << getSum(st, n, 1, 3) << endl;

    return 0;
}
