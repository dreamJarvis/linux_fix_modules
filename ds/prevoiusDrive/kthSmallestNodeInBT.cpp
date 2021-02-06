// Find the kth smallest node in a binary search tree.
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};

// tc : O(N) -> no of nodes
// sc : O(N)
TreeNode *kthSmallestUtil(TreeNode *root, vector<TreeNode *> &arr){
    if(!root)   return nullptr;

    if(root->left)
        kthSmallestUtil(root->left, arr);

    arr.push_back(root);

    if(root->right)
        kthSmallestUtil(root->right, arr);
}

int kthSmallest(TreeNode *root, int k){
    if(!root)   return -1;
    vector<TreeNode *> res;
    kthSmallestUtil(root, res);
    return res[k-1]->val;
}


// tc : O(N)
// sc : O(1)
void kthSmallestIIUtil(TreeNode *root, int &c, int &res, int k){
    if(!root || c >= k)
        return ;

    kthSmallestIIUtil(root->left, c, res, k);

    c++;
    if(c == k){
        res = root->val;
        return ;
    }

    kthSmallestIIUtil(root->right, c, res, k);
}

int kthSmallestII(TreeNode *root, int k){
    if(!root)   return -1;
    int res = -1, c = 0;
    kthSmallestIIUtil(root, c, res, k);
    return res;
}

// void inorder(TreeNode *root){
//     if(!root)   return;
//
//     inorder(root->left);
//     cout << root->val << " ";
//     inorder(root->right);
// }

// Driver function
int main(){
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(25);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->right->left = new TreeNode(24);
    root->right->right = new TreeNode(30);

    int k = 3;
    cout << kthSmallestII(root, k)<< endl;

    return 0;
}
