/*
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

TreeNode *constructBSTUtil( vector<int> &inorder, vector<int> &postorder,
                            unordered_map<int, int> &map, int start, int end, int &index
){
    if(start > end)
        return nullptr;

    TreeNode *root = new TreeNode(postorder[index--]);
    int key = root->val;

    if(start == end)    return root;

    int mid = map[key];

    root->right = constructBSTUtil(inorder, postorder, map, mid+1, end, index);
    root->left  = constructBSTUtil(inorder, postorder, map, start, mid-1, index);

    return root;
}

TreeNode *constructBST(vector<int> &inorder, vector<int> &postorder){
    int n = inorder.size();

    unordered_map<int, int> map;
    for(int i = 0; i < n; i++)
        map[inorder[i]] = i;

    int preIndex = n-1;
    return constructBSTUtil(inorder, postorder, map, 0, n-1, preIndex);
}

void inorderTraversal(TreeNode *root){
    if(!root)   return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// Driver function
int main(){
    // vector<int> inorder({5, 10, 12, 15, 18, 20, 24, 25, 30});
    // vector<int> postorder({5, 12, 10, 18, 15, 24, 30, 25, 20});
    // vector<int> inorder({9, 3, 15, 20, 7});
    // vector<int> postorder({9, 15, 7, 20, 3});
    vector<int> inorder({-1});
    vector<int> postorder({-1});

    TreeNode *root = constructBST(inorder, postorder);
    inorderTraversal(root);

    return 0;
}
