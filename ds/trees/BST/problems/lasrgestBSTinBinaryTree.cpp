/*
    Find the largest BST subtree in a given Binary Tree
    https://www.geeksforgeeks.org/find-the-largest-subtree-in-a-tree-that-is-also-a-bst/?ref=rp
    leetcode 1373 :  Maximum Sum BST in Binary Tree
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Info{
public:
    int numBst;
    int minRange;
    int maxRange;
    int maxSum=0;
    bool isBST;
};

// to find the largest BST
// O(n)
int maxBst = INT_MIN;
int sumMax = 0;
Info largestBSTUtil(TreeNode *root){
    if(!root)
        return {0, INT_MAX, INT_MIN, 0, true};

    if(!root->left && !root->right)
        return {1, root->val, root->val, root->val, true};

    Info leftSubtree  = largestBSTUtil(root->left);
    Info rightSubtree = largestBSTUtil(root->right);

    Info bst;
    bst.minRange = min(root->val, min(leftSubtree.minRange, rightSubtree.minRange));
    bst.maxRange = max(root->val, max(leftSubtree.maxRange, rightSubtree.maxRange));

    if( leftSubtree.isBST && rightSubtree.isBST &&
        root->val > leftSubtree.maxRange && root->val < rightSubtree.minRange
    ){
        bst.isBST = true;
        bst.numBst = 1 + leftSubtree.numBst + rightSubtree.numBst;
        bst.maxSum = root->val + leftSubtree.maxSum + rightSubtree.maxSum;
        maxBst = max(maxBst, bst.numBst);
        sumMax = max(sumMax, bst.maxSum);
    }
    else {
        bst.isBST = false;
        bst.numBst = leftSubtree.numBst + rightSubtree.numBst;
        maxBst = max(maxBst, max(leftSubtree.numBst, rightSubtree.numBst));
        sumMax = max(
                        sumMax,
                        max(
                            leftSubtree.maxSum,
                            rightSubtree.maxSum
                        )
                    );
    }

    return bst;
}

// tc : O(n)
int largestBST(TreeNode *root){
    if(!root) return 0;
    Info res = largestBSTUtil(root);
    return maxBst;
}

// tc: O(n)
int largestBSTSum(TreeNode *root){
    if(!root)   return 0;
    largestBSTUtil(root);
    return sumMax;
}

// Driver function
int main(){
    // TreeNode *root = new TreeNode(5);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(4);
    // root->left->left = new TreeNode(1);
    // root->left->right = new TreeNode(3);

    // TreeNode *root = new TreeNode(50);
    // root->left = new TreeNode(30);
    // root->left->left = new TreeNode(5);
    // root->left->right = new TreeNode(20);
    // root->right = new TreeNode(60);
    // root->right->left = new TreeNode(45);
    // root->right->right = new TreeNode(70);
    // root->right->right = new TreeNode(70);
    // root->right->right->left = new TreeNode(65);
    // root->right->right->right = new TreeNode(80);

    // TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(4);
    // root->left->left = new TreeNode(2);
    // root->left->right = new TreeNode(4);
    // root->right = new TreeNode(3);
    // root->right->left = new TreeNode(2);
    // root->right->right = new TreeNode(5);
    // root->right->right->left = new TreeNode(4);
    // root->right->right->right = new TreeNode(6);

    // TreeNode *root = new TreeNode(4);
    // root->left = new TreeNode(3);
    // int sumMax = 0;
    // root->left->left = new TreeNode(1);
    // root->left->right = new TreeNode(2);

    // TreeNode *root = new TreeNode(-4);
    // root->left = new TreeNode(-2);
    // root->right = new TreeNode(-5);

    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    // cout << largestBST(root) << endl;
    cout << largestBSTSum(root) << endl;

    return 0;
}
