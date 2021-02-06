/*
    leetcode 94. Binary Tree Inorder Traversal
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

TreeNode *insert(TreeNode *root, int key){
    if(!root)   return (new TreeNode(key));

    if(key < root->val) root->left = insert(root->left, key);
    else                root->right = insert(root->right, key);
}

void inorder(TreeNode *root, vector<int> &result){
    if(!root)   return;

    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right, result);
}

vector<int> inorderTraversal(TreeNode *root){
    vector<int> result;
    if(!root)   return result;
    inorder(root, result);
    return result;
}

// Driver function
int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    for(auto i:inorderTraversal(root))
        cout << i << " ";
    cout << endl;

    return 0;
}
