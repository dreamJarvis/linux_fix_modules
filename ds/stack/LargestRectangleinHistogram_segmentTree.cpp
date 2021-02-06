// 84. Largest Rectangle in Histogram
/*
    methods :
    1) Using segment tree's (minimum range query) : O(nlog(n))
    2) using stack : O(n)

    References :

    segment :
        https://www.geeksforgeeks.org/segment-tree-set-1-range-minimum-query/?ref=rp

        https://leetcode.com/problems/largest-rectangle-in-histogram/discuss/28941/Segment-tree-solution-just-another-idea-O(N*logN)-Solution

    stack :
        https://www.youtube.com/watch?v=ZmnqCZp9bBs&t=397s

*/
#include <bits/stdc++.h>
using namespace std;

//============================== segment tree approach ==============================//
// tc : O(nlog(n))
class SegTreeNode {
public:
    int start, end;
    int min;

    // segment tree is a full binary tree
    SegTreeNode *left, *right;

    // constructor
    SegTreeNode(int start, int end){
        this->start = start;
        this->end = end;
        left = right = nullptr;
    }
};

// returns the minimum value in the given query
int query(SegTreeNode *root, vector<int> &heights, int start, int end){

    // no overlap btw the ranges
    if(root == nullptr || end < root->start || start > root->end)
        return -1;

    // total overlap btw the ranges
    if(start <= root->start && end >= root->end)
        return root->min;

    // partial overlap
    int leftMin = query(root->left, heights, start, end);
    int rightMin = query(root->right, heights, start, end);

    // return's minimum of them both
    if(leftMin == -1)   return rightMin;
    if(rightMin == -1)  return leftMin;

    return heights[leftMin] < heights[rightMin] ? leftMin : rightMin;
}

/* it calculates the maximum area w.r.t. the minimum value in this range
*/
int calculateMax(vector<int> &heights, SegTreeNode *root, int start, int end){
    if(start > end)
        return -1;

    // we have reached a leaf node
    if(start == end)
        return heights[start];

    /*
        compare btw, maximum rectange area to the left of the min value index,
        to the right of the min vaue index, and considering the min value index,
        return whichever is the largest area
    */

    // calculates the min index in this range
    int minIndex = query(root, heights, start, end);
    int leftMax = calculateMax(heights, root, start, minIndex-1);
    int rightMax = calculateMax(heights,root, minIndex+1, end);

    // total area with the minimum index value
    int minMax = heights[minIndex] * (end - start + 1);

    // returing the maximum of the total area
    return (max(max(leftMax, rightMax), minMax));
}

// building the segment tree
/* it's just like storing value in a binary tree,
after storing value at the curent node, we traversed to both of its children,
and the recursively storing every value down the tree

the segment Tree nodes will contain indexes to the original value mentioned in the histogram array (heights)
*/
SegTreeNode *buildSegmentTree(vector<int> &heights, int start, int end){
    if(start > end) return nullptr;

    /* every range possible is depicted by a node,
        which stores its starting and ending index
    */
    SegTreeNode *root = new SegTreeNode(start, end);

    /* this condition assings value to leaf nodes which are the
    original value of the hitograms*/
    if(start == end){
        root->min = start;
        return root;
    }

    else {
        int mid = (start + (end - start)/2);

        /*
            traversing to its children , and filling them with value, while recusing back,
            i.e. when we will start emptying the stack we will assing values to the current root index of this stack,
            i.e. current root node values will depend upon it's children stack, or its child nodes
        */
        root->left = buildSegmentTree(heights, start, mid);
        root->right = buildSegmentTree(heights, mid+1, end);

        root->min = heights[root->left->min] < heights[root->right->min] ? root->left->min : root->right->min;
        return root;
    }
}

// returns the largest rectqngular area btw histogram
int largestRectangleAreaST(vector<int> &heights){
    int n = heights.size();
    if(n== 0) return 0;

    // building the segment tree
    // head of the segment Tree, always starts with the 0'th index
    SegTreeNode *root = buildSegmentTree(heights, 0, n-1);

    // returns the calculated maximum rectangular area found
    return calculateMax(heights, root, 0, n-1);
}


//===================================  stack Method ====================================//
// tc : O(n)
int largestRectangleAreaStack(vector<int> &arr){
    int n = arr.size();
    stack<int> st;
    int maxArea = arr[0];
    int tp;
    int areaWithTop;

    int i = 0;
    while(i < n){
        if(st.empty() || arr[st.top()] <= arr[i])
            st.push(i++);

        else {
            tp = st.top();
            st.pop();

            areaWithTop = arr[tp]*(st.empty() ? i : (i - st.top() - 1));
            maxArea = max(maxArea, areaWithTop);
        }
    }

    while(!st.empty()){
        tp = st.top();
        st.pop();

        areaWithTop = arr[tp]*(st.empty() ? i : (i - st.top() - 1));
        maxArea = max(maxArea, areaWithTop);
    }

    return maxArea;
}

int main(){
    vector<int> histogram({12, 3, 5, 7, 23, 11, 12, 6});

    // cout << "Maximum area : " << largestRectangleAreaST(histogram) << endl;
    cout << "Maximum area : " << largestRectangleAreaStack(histogram) << endl;

    return 0;
}
