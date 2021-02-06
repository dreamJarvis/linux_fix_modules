/*
    Find k-th smallest element in BST
    https://www.geeksforgeeks.org/find-k-th-smallest-element-in-bst-order-statistics-in-bst/
    https://www.geeksforgeeks.org/kth-largest-element-in-bst-when-modification-to-bst-is-not-allowed/
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

// tc : O(n), sc : O(1)
void helper(TreeNode *root, int &c, int &res, int k){
    if(!root || c > k){
        return ;
    }

    helper(root->right, c, res, k);
    c++;

    if(c == k){
        res = root->val;
        return ;
    }

    helper(root->left, c, res, k);
}

int kthLargest(TreeNode *root, int k){
    int c = 0;
    int res = -1;
    helper(root, c, res, k);
    return res;
}

// Driver function
int main(){
    // TreeNode *root = new TreeNode(11);
    // root->left = new TreeNode(8);
    // root->right = new TreeNode(10);
    // root->left->left = new TreeNode(5);
    // root->left->left->left = new TreeNode(4);
    // root->left->left->right = new TreeNode(6);
    // root->right->left = new TreeNode(9);
    // root->right->right = new TreeNode(8);

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    int k = 3;
    cout << kthLargest(root, k) << endl;

    return 0;
}
/*
TreeNode *root = new TreeNode(3);
root->left = new TreeNode(1);
root->right = new TreeNode(4);
root->left->right = new TreeNode(2);
*/
