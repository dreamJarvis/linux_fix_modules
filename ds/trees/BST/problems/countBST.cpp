/*
    Count the Number of Binary Search Trees present in a Binary Tree
    https://www.geeksforgeeks.org/count-the-number-of-binary-search-trees-present-in-a-binary-tree/#:~:text=Count%20the%20Number%20of%20Binary%20Search%20Trees%20present%20in%20a%20Binary%20Tree,-Last%20Updated%3A%2023&text=Given%20a%20binary%20tree%2C%20the,Search%20Trees%20present%20in%20it.&text=Here%20each%20node%20represents%20a,there%20are%20total%207%20nodes.
*/
#include <bits/stdc++.h>
using namespace std;

// Node of a tree
struct TreeNode{
    int val;
    TreeNode *left, *right;

    TreeNode (int x){
        val = x;
        left = right = nullptr;
    }
};

// for storing previous nodes information
class Info {
public:
    int numBST;         // total numbers of bst until it
    int max;            // the max range
    int min;            // min range
    bool isBST;         // is a bst ?
};

// we are using bootom up approach
Info countBST(TreeNode *root){
    if(!root){
        return {0, INT_MIN ,INT_MAX, true};
    }

    if(!root->left && !root->right){
        return {1, root->val, root->val, true};
    }

    // ṣearching for the bst in left and right subtree
    Info L = countBST(root->left);
    Info R = countBST(root->right);

    // defining the range within whcich the current node should lie in
    Info var;
    var.min = min(root->val, min(L.min, R.min));
    var.max = max(root->val, max(L.max, R.max));

    // if the current node lies withing the current given range then it is a BST
    if(L.isBST && R.isBST && root->val > L.max && root->val < R.min){
        var.isBST = true;
        var.numBST = 1 + L.numBST + R.numBST;
    }
    else {
        var.isBST = false;
        var.numBST = L.numBST + R.numBST;
    }

    return var;
}

// Driver function
int main(){
    // TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);
    // root->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(7);

    TreeNode *root = new TreeNode(11);
    root->left = new TreeNode(8);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(5);
    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(6);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(8);

    Info res = countBST(root);
    cout << res.numBST << endl;

    return 0;
}
