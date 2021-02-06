/*
    Find distance between two nodes of a Binary Tree
    https://www.geeksforgeeks.org/find-distance-between-two-nodes-of-a-binary-tree/
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

// O(n)
int height(TreeNode *root){
    if(!root)   return 0;

    return(
        max(
            height(root->left),
            height(root->right)
        ) + 1
    );
}

// O(n)
TreeNode *lca(TreeNode *root, TreeNode *n1, TreeNode *n2){
    if(!root)
        return nullptr;

    if(root == n1 || root == n2)
        return root;

    TreeNode *leftSubTree = lca(root->left, n1, n2);
    TreeNode *rightSubTree = lca(root->right, n1, n2);

    if(leftSubTree == n1 && rightSubTree == n2 ||
        leftSubTree == n2 && rightSubTree == n1)
        return root;

    return (!leftSubTree ? rightSubTree : leftSubTree);
}

// tc : O(n)
int distanceBetweenNodes(TreeNode *root, TreeNode *n1, TreeNode *n2){
    if(!root)   return 0;

    TreeNode *commonNode = lca(root, n1, n2);       // O(n)
    int leftDist = height(commonNode->left);        // O(n)
    int rightDist = height(commonNode->right);      // O(n)

    return (leftDist + rightDist);
}

// Driver function
int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left->right = new TreeNode(8);

    TreeNode *n1 = root->left->right;
    TreeNode *n2 = root->right->left->right;

    cout << distanceBetweenNodes(root, n1, n2) << endl;

    return 0;
}
