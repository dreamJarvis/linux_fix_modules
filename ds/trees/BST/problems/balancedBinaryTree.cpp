// leetcode 110. Balanced Binary Tree
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

class Info{
public:
    int height;
    bool balanced;
};

// tc : O(n)
// sc : O(n)
class SolutionI {
public:
    bool isBalanced(TreeNode* root) {
        Info temp = helper(root);
        return temp.balanced;
    }

    Info helper(TreeNode *root){
        Info var;

        if(!root){
            var.height = 0;
            var.balanced = true;
            return var;
        }

        Info leftSubtree = helper(root->left);
        Info rightSubtree = helper(root->right);

        var.height = max(leftSubtree.height, rightSubtree.height) + 1;

        if(leftSubtree.balanced && rightSubtree.balanced){
            var.balanced = abs(leftSubtree.height - rightSubtree.height) <= 1 ? true : false;
            return var;
        }
        else{
            var.balanced = false;
            return var;
        }
    }
};

class SolutionII {
public:
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return checkBalance(root, height);
    }

    bool checkBalance(TreeNode* root, int& height) {
        if (root == NULL) {
            height = 0;
            return true;
        }

        int leftHeight = 0;
        int rightHeight = 0;

        if (!checkBalance(root->left, leftHeight)) return false;
        if (!checkBalance(root->right, rightHeight)) return false;
        if ( abs(leftHeight - rightHeight) > 1 ) return false;

        height = max(leftHeight, rightHeight) + 1;
        return true;
    }
};


// Driver function
int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    SolutionI s1;
    SolutionII s2;

    cout << s1.isBalanced(root) << endl;
    cout << s2.isBalanced(root) << endl;

    return 0;
}
