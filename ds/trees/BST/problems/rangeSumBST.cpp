/*
    938. Range Sum of BST
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {}
    TreeNode(int data, TreeNode *left, TreeNode *right) : val(data), left(left), right(right) {}
};

class Solution {
public:
    // recursive approach
    // tc : O(n), sc : O(H), H -> height of the tree
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        rangeSum(root, L, R, sum);
        return sum;
    }

    // helper function
    // it doent matter which traversal we use, we just have to traverse the whole tree looking for the values that lies in the range
    void rangeSum(TreeNode *root, int L, int R, int &sum){
        if(!root)   return ;

        if(root->val >= L && root->val <= R)
            sum += root->val;
        rangeSum(root->right, L, R, sum);
        rangeSum(root->left, L, R, sum);
    }

    // iterate approach
    int rangeSumBSTIterative(TreeNode *root, int L, int R){
        int sum = 0;
        stack<TreeNode *> s;
        TreeNode *curr = root;

        while(!s.empty() || curr){
            while(curr){
                s.push(curr);
                curr = curr->right;
            }

            curr = s.top();
            if(curr->val >= L && curr->val <= R)
                sum += curr->val;
            s.pop();
            curr = curr->left;
        }

        return sum;
    }

    // using segment tree, range sum query
};

// Driver function
int main(){
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(18);

    Solution s;
    cout << s.rangeSumBST(root, 7, 15) << endl;
    cout << s.rangeSumBSTIterative(root, 7, 15) << endl;

    return 0;
}
