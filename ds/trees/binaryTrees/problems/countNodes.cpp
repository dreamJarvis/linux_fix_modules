// count nodes
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

// count all the nodes in an tree
int countNodes(TreeNode *root){
    if(!root)   return 0;

    return (
        countNodes(root->left) +
        countNodes(root->right) + 1
    );
}

// count all the full nodes in an tree
int countFullNodes(TreeNode *root){
    if(!root || !root->left || !root->right)   return 0;
    return (
        countFullNodes(root->left) +
        countFullNodes(root->right) + 1
    );
}

// Driver function
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(6);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(8);

    cout << countNodes(root) << endl;
    cout << countFullNodes(root) << endl;

    return 0;
}
