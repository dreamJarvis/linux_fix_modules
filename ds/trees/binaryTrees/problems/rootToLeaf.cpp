/*
    Given a binary tree, print all root-to-leaf paths
    https://www.geeksforgeeks.org/given-a-binary-tree-print-all-root-to-leaf-paths/
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;

    TreeNode(int x){
        val = x;
        left = right = nullptr;
    }
};

// tc : O(n)
void rootToLeaf(TreeNode *root, string ans){
    if(!root->left && !root->right){
        ans += to_string(root->val);
        cout << ans << endl;
        return;
    }

    ans+=(to_string(root->val) + "-->");
    rootToLeaf(root->left, ans);
    rootToLeaf(root->right, ans);
}

// Driver function
int main() {
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(2);

    rootToLeaf(root, "");

    return 0;
}
