/*
    leetcode 98. Validate Binary Search Tree
    https://leetcode.com/problems/validate-binary-search-tree/
    gfg : https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;

    TreeNode (int x){
        val = x;
        left = right = nullptr;
    }
};

// insertion
TreeNode *insert(TreeNode *root, int key){
    if(!root)   return (new TreeNode(key));

    if(key < root->val) root->left = insert(root->left, key);
    else                root->right = insert(root->right, key);
}

// is the binary tree a BST
bool isValidBST(TreeNode *root, int leftRange, int rightRange){
    if(!root)
        return true;

    if(root->val <= leftRange || root->val >= rightRange)
        return false;

    return (
        isValidBST(root->left, leftRange, root->val) &&
        isValidBST(root->right, root->val, rightRange)
    );
}

// traversal
void inOrder(TreeNode *root){
    if(!root)   return ;

    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

// Driver function
int main(){
    // TreeNode *root = new TreeNode(5);
    // root->left = new TreeNode(1);
    // root->right = new TreeNode(4);
    // root->right->left = new TreeNode(3);
    // root->right->right = new TreeNode(6);

    // TreeNode *root = new TreeNode(2);
    // root->left = new TreeNode(1);
    // root->right = new TreeNode(3);

    // TreeNode *root = new TreeNode(0);
    // root->left = new TreeNode(-1);

    // TreeNode *root = new TreeNode(10);
    // root->left = new TreeNode(5);
    // root->right = new TreeNode(15);
    // root->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(20);

    TreeNode *root = new TreeNode(2147483647);

    inOrder(root);

    cout << "\n" << isValidBST(root, INT_MIN, INT_MAX) << endl;

    inOrder(root);

    return 0;
}
/*
[2147483647]
*/
