/*
    Construct Tree from given Postorder and Preorder traversals
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

TreeNode *constructBSTUtil( vector<int> postorder, vector<int> preorder,
                            unordered_map<int, int> &map, int start, int end
){
    static int preIndex = 0;

    if(preIndex > postorder.size()-1 || start > end)
        return nullptr;

    TreeNode *curr = new TreeNode(preorder[preIndex++]);

    if(start == end)    return curr;

    int mid = map[preorder[preIndex]];

    if(mid <= end){
        curr->left = constructBSTUtil(postorder, preorder, map, start, mid);
        curr->right = constructBSTUtil(postorder, preorder, map, mid+1, end);
    }

    return curr;
}

TreeNode *constructBST(vector<int> &postorder, vector<int> &preorder){
    int n = preorder.size();
    unordered_map<int, int> map;
    for(int i = 0; i < n; i++)
        map[postorder[i]] = i;

    return constructBSTUtil(postorder, preorder, map, 0, n-1);
}

void inorderTraversal(TreeNode *root){
    if(!root)   return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// Driver function
int main(){
    vector<int> preorder({20, 15, 10, 5, 12, 18, 25, 24, 30});
    vector<int> postorder({5, 12, 10, 18, 15, 24, 30, 25, 20});

    TreeNode *root = constructBST(postorder, preorder);
    inorderTraversal(root);

    return 0;
}
