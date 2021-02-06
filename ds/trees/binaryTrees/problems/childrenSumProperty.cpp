/*
    Check for Children Sum Property in a Binary Tree
    https://www.geeksforgeeks.org/check-for-children-sum-property-in-a-binary-tree/
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

// t : O(n)
int isSumProperty(TreeNode *root){
    int left = 0, right = 0;
    if(!root || !root->left && !root->right)
        return true;
    else {
        if(root->left)
            left = root->left->val;
        if(root->right)
            right = root->right->val;

        // only if the current nodes satisfies the children sum property, then only we will proceed to the childrens
        if((root->val == left + right) &&
            isSumProperty(root->left)  &&
            isSumProperty(root->right)
        )
            return true;
        else
            return false;
    }
}

// Driver function
int main(){
    struct TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(12);

    if(isSumProperty(root))
        cout << "The given tree satisfies the children sum property ";
    else
        cout << "The given tree does not satisfy the children sum property ";

    return 0;
}
