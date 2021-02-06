// leetcode 404. Sum of Left Leaves
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

// BFS
class SolutionI {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)   return 0;
        int sum = 0;
        helper(root, sum);
        return sum;
    }

    void helper(TreeNode *root, int &sum){
        if(!root)   return;

        helper(root->left, sum);
        if(root->left){
            if(!(root->left)->left && !(root->left)->right)
                sum += root->left->val;
        }
        helper(root->right, sum);
    }
};

// DFS
class SolutionII {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        
    }
};

// Driver function
int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    SolutionII s;
    cout << s.sumOfLeftLeaves(root) << endl;

    return 0;
}
