/*
    Construct Tree from given Inorder and Preorder traversals
    https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *constructBSTUtil( vector<int> inorder, vector<int> preorder,
                            unordered_map<int, int> &mp, int &si, int ss, int se
){
    if(si < 0 || si > inorder.size()-1)   return nullptr;
    if(ss > se) return nullptr;

    TreeNode *root = new TreeNode(preorder[si]);
    int mid = mp[si];
    si++;

    if(ss == se)    return root;

    cout << "asd" << endl;

    root->left  = constructBSTUtil(inorder, preorder, mp, si, ss, mid-1);
    root->right = constructBSTUtil(inorder, preorder, mp, si, mid+1, se);
    return root;
}

TreeNode *constructBST(vector<int> inorder, vector<int> preorder){
    int n = inorder.size();

    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++)
        mp[inorder[i]] = i;

    int index = 0;
    return constructBSTUtil(inorder, preorder, mp, index, 0, n-1);
}

void inorderTraversal(TreeNode *root){
    if(!root)   return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// Driver function
int main(){
    vector<int> inorder({5, 10, 12, 15, 18, 20, 24, 25, 30});
    vector<int> preorder({20, 15, 10, 5, 12, 18, 25, 24, 30});

    TreeNode *root = constructBST(inorder, preorder);
    inorderTraversal(root);

    return 0;
}
