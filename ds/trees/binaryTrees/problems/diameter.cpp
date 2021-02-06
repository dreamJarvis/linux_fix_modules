/*
    Diameter of a Binary Tree
    https://www.geeksforgeeks.org/diameter-of-a-binary-tree/
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

// tc : O(n^2)
int diameter(TreeNode *root){
    if(!root)   return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int leftSubTree = diameter(root->left);
    int rightSubTree = diameter(root->right);

    return (
        max(
            max(leftSubTree, rightSubTree),
            (leftHeight + rightHeight + 1)
        )
    );
}

// =================  optimied =============== //
// tc : O(n)
class Diameter {
public:
    int height;
    int maxDia;
};

// bottom-up approach
// we first reach the leaf nodes and then start incrementing height
Diameter dia(TreeNode *root){
    Diameter val;
    if(!root){
        val.height = 0;
        val.maxDia = 0;
        return val;
    }

    Diameter leftDia = dia(root->left);
    Diameter rightDia = dia(root->right);

    val.height = max(leftDia.height, rightDia.height) + 1;
    val.maxDia = max(
                        (leftDia.height + rightDia.height),
                        max(leftDia.maxDia, rightDia.maxDia)
                );

    return val;
}

// Driver function
int main(){
    // TreeNode* root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->right->right = new TreeNode(6);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);
    // root->right->left = new TreeNode(8);

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << dia(root).maxDia << endl;

    return 0;
}
