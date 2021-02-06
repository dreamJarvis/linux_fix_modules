// given an array of intergers , and an array of queries, find the maximum in each of those queries
#include <bits/stdc++.h>
using namespace std;

// update the range query
// tc : O(log(n))
void updateRangeQueryUitl(  vector<int> arr, vector<int> &segmentTree,
                            int ss, int se, int si, int index, int value)
{
    if(index < ss || index > se)
        return ;

    if(ss == se){
        arr[index] = value;
        segmentTree[si] = value;
        return;
    }

    if(ss != se){
        int mid = (ss + (se - ss)/2);

        if(index >= ss && index <= mid)
            updateRangeQueryUitl(arr, segmentTree, ss, mid, 2*si+1, index, value);
        else
            updateRangeQueryUitl(arr, segmentTree, mid+1, se, 2*si+2, index, value);

        // storing the minimum of it's children, at the parents node
        segmentTree[si] = min(segmentTree[2*si+1], segmentTree[2*si+2]);
    }
}

void updateRangeQuery(vector<int> arr, vector<int> &segmentTree, int index, int value){
    int n = arr.size();
    index--;

    if(index < 0 || index > n-1){
        cout << "Invalid" << endl;
        return ;
    }

    updateRangeQueryUitl(arr, segmentTree, 0, n-1, 0, index, value);
}

// to find the maximum of a given range
// tc : O(log(n))
int maximumRangeQueryUtil(  vector<int> arr, vector<int> &segmentTree,
                            int ss, int se, int si, int qs, int qe
){
    // full overlap
    if(qs <= ss && qe >= se)
        return segmentTree[si];

    // no overlap
    if(qs > se || qe < ss)
        return INT_MIN;

    // partial overlap
    int mid = (ss + (se - ss)/2);
    return max(
        maximumRangeQueryUtil(arr, segmentTree, ss, mid, 2*si+1, qs, qe),
        maximumRangeQueryUtil(arr, segmentTree, mid+1, se, 2*si+2, qs, qe)
    );
}

int maximumRangeQuery(vector<int> arr, vector<int> &segmentTree, int qs, int qe){
    int n = arr.size();

    qs--;
    qe--;
    if(qs < 0 || qe > n)
        return -1;

    return maximumRangeQueryUtil(arr, segmentTree, 0, n-1, 0, qs, qe);
}


// constructing segment tree for finding maximum int a given range
// tc : O(size_of_segment_tree_array)
int constructSTUtil(    vector<int> arr, vector<int> &segmentTree,
                        int ss, int se, int si
){
    if(ss == se){
        segmentTree[si] = arr[ss];
        return arr[ss];
    }

    int mid = (ss + (se - ss)/2);
    segmentTree[si] =  max(
                            constructSTUtil(arr, segmentTree, ss, mid, 2*si+1),
                            constructSTUtil(arr, segmentTree, mid+1, se, 2*si+2)
                        );
    return segmentTree[si];
}

void constructST(vector<int> arr, vector<int> &segmentTree){
    int n = arr.size();
    int height = (int)(ceil(log2(n)));
    int treeSize = 2*(int)pow(2, height) - 1;

    // segent tree construction
    vector<int> tree(treeSize, INT_MIN);
    segmentTree = tree;

    constructSTUtil(arr, segmentTree, 0, n-1, 0);
}

// Driver function
int main(){
    vector<int> arr({12, 3, 5, 7, 23, 11, 12, 6});
    vector<int> segmentTree;

    // consturct segment tree
    constructST(arr, segmentTree);

    // segment tree after construction
    // for(auto i:segmentTree)
    //     cout << i << ", ";
    // cout << endl;

    cout << maximumRangeQuery(arr, segmentTree, 2, 4) << endl;


    updateRangeQuery(arr, segmentTree, 2, -1);

    // // segment tree after construction
    // for(auto i:segmentTree)
    //     cout << i << ", ";
    // cout << endl;

    cout << maximumRangeQuery(arr, segmentTree, 1, 4) << endl;


    return 0;
}
