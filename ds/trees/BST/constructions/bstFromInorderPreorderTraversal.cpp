/*
    Construct Tree from given Inorder and Preorder traversals
    https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/
    F:\Data-Strcutures\Interview_Prep\trees\binaryTrees\constructions\constructFromInorderPreorder.cpp
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

TreeNode *constructBSTUtil( vector<int> &inorder, vector<int> &preorder,
                            unordered_map<int, int> &map, int start, int end
){
    static int preIndex = 0;

    if(start > end) return nullptr;

    TreeNode *newNode = new TreeNode(preorder[preIndex++]);
    int key = newNode->val;

    if(start == end)    return newNode;

    int mid = map[key];

    newNode->left = constructBSTUtil(inorder, preorder, map, start, mid-1);
    newNode->right = constructBSTUtil(inorder, preorder, map, mid+1, end);

    return newNode;
}

TreeNode *constructBST(vector<int> &inorder, vector<int> &preorder){
    int n = inorder.size();
    unordered_map<int, int> map;

    for(int i = 0; i < n; i++)
        map[inorder[i]] = i;

    return constructBSTUtil(inorder, preorder, map, 0, n-1);
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
