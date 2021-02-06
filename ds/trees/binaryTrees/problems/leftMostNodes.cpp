// to find the left Most Node
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

TreeNode *LMN(TreeNode *root){
    if(!root->left)   return root;
    return LMN(root->left);
}

// Driver function
int main(){
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(12);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(25);
    root->left->right = new TreeNode(30);
    root->right->left = new TreeNode(36);

    cout << LMN(root)->val << endl;

    return 0;
}
