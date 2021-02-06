/*
    112. Path Sum
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

class Solution {
    void rootPaths(TreeNode *root, int path, int sum, bool &isSum){
        if(!root)   return;
        if(!root->left && !root->right){
            path += root->val;
            if(path == sum){
                isSum = true;
                return ;
            }
            return ;
        }

        path += root->val;
        rootPaths(root->left, path, sum, isSum);
        rootPaths(root->right, path, sum, isSum);
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        bool isSum = false;
        rootPaths(root, 0, sum, isSum);
        return isSum;
    }
};

// Driver function
int main(){
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    int sum = 22;
    Solution s;
    cout << s.hasPathSum(root, 22) << endl;

    return 0;
}
