/*
    How to determine if a binary tree is height-balanced?
    https://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/
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

// find the height of the sub-tree
int height(TreeNode *root){
    if(!root)   return 0;

    return (
        max(
            height(root->left),
            height(root->right)
        ) + 1
    );
}

// checks if the tree is balanced or not
// tc : O(n^2)
bool isBalanced(TreeNode *root){
    if(!root) return true;

    // // it is top-down approach
    // if( (abs(height(root->left) - height(root->right)) <= 1) &&
    //     isBalanced(root->left) &&
    //     isBalanced(root->right)
    // )
    //     return true;

    // here we are checking bottom-up
    if( isBalanced(root->left) &&
        isBalanced(root->right) &&
        (abs(height(root->left) - height(root->right)) <= 1)
    )
        return true;
    return false;
}

// ================================= optimied ================================= //
// tc : O(n)
class BalancedHeight{
public:
    int height;
    bool balance;
};

BalancedHeight isBalancedOptimised(TreeNode *root){
    BalancedHeight val;
    if(root == nullptr){
        val.height = -1;
        val.balance = true;
        return val;
    }

    BalancedHeight leftPair = isBalancedOptimised(root->left);
    BalancedHeight rightPair = isBalancedOptimised(root->right);

    val.height = max(leftPair.height, rightPair.height) + 1;

    if(!leftPair.balance || !rightPair.balance){
        val.balance = false;
        return val;
    }

    val.balance = (abs(leftPair.height-rightPair.height) <= 1) ? true : false;
    return val;
}

// Driver function
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(6);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(8);

    if (isBalanced(root))
        cout << "Tree is balanced";
    else
        cout << "Tree is not balanced";

    // cout << height(root) << endl;

    return 0;
}
