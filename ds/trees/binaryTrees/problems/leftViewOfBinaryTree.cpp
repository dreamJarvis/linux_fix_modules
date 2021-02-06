/*
    Print Left View of a Binary Tree
    https://www.geeksforgeeks.org/print-left-view-binary-tree/
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

// so level is the count of the level we are at, and maxLevel keeps the count of the level we have visited, so we dont print the values again when we visit the same level, because we visiting left nodes first, .'. when we visit the same level 2'nd time it is for the right sub-tree, or right node
void leftViewOfTree(TreeNode *root, int level){
    static int maxLevel = 0;            // keeps the count of the level we have already visited
    if(!root)   return;

    if(maxLevel < level){
        cout << root->val << " ";
        maxLevel = level;
    }

    leftViewOfTree(root->left, level+1);
    leftViewOfTree(root->right, level+1);
}

void inorderTraversal(TreeNode *root){
    if(!root)   return;
    inorderTraversal(root->left);
    cout << root->val << endl;
    inorderTraversal(root->right);
}

// Driver function
int main(){
    // TreeNode* root = new TreeNode(12);
    // root->left = new TreeNode(10);
    // root->right = new TreeNode(30);
    // root->right->left = new TreeNode(25);
    // root->right->right = new TreeNode(40);

    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(5);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(1);
    root->right->left->left = new TreeNode(6);
    root->right->left->right = new TreeNode(7);

    // inorderTraversal(root);

    leftViewOfTree(root, 1);

    return 0;
}
