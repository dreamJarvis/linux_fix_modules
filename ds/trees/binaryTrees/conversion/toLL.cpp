/*
    Flatten a binary tree into linked list

    leetcode : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
    gfg : https://www.geeksforgeeks.org/flatten-a-binary-tree-into-linked-list/
*/
#include <bits/stdc++.h>
using namespace std;

// tree node
struct TreeNode{
    int val;
    TreeNode *left, *right;

    TreeNode(int x){
        val = x;
        left = right = nullptr;
    }
};

// tc : O(n)
void flatten(TreeNode *root){
    if(!root || !root->left && !root->right)
        return;

    if(root->left != nullptr){
        flatten(root->left);

        TreeNode *tmpRight = root->right;
        root->right = root->left;
        root->left = nullptr;

        TreeNode *t = root->right;
        while(t->right != nullptr)
            t = t->right;

        t->right = tmpRight;
    }

    flatten(root->right);
}

void inorderTraversal(TreeNode *head){
    if(!head)   return;

    inorderTraversal(head->left);
    cout << head->val << " ";
    inorderTraversal(head->right);
}

// Driver function
int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);


    // inorderTraversal(root);
    // cout << "\n";


    flatten(root);

    // right traversal
    while(root){
        cout << root->val << " ";
        root = root->right;
    }

    // inorderTraversal(root);

    return 0;
}
