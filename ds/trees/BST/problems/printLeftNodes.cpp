/*
    leetcode 404. Sum of Left Leaves
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
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)   return 0;
        int sum = 0;
        // string path = "";
        helper(root, sum);

        // cout << path << endl;

        return sum;
    }

    void helper(TreeNode *root, int &sum){
        if(root){
            if(!root->left->left && !root->left->right){
                cout << root->left->val << " ";
                return ;
            }

            helper(root->left, sum);
            helper(root->right, sum);
        }
        return ;
    }
};

// Driver function
int main(){
    // TreeNode *root = new TreeNode(3);
    // root->left = new TreeNode(9);
    // root->right = new TreeNode(20);
    // root->right->left = new TreeNode(15);
    // root->right->right = new TreeNode(7);

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution s;
    cout << s.sumOfLeftLeaves(root) << endl;

    return 0;
}
