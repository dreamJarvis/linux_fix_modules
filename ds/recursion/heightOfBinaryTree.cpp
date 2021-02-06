#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

int height(TreeNode *root){
    // base condition
    if(root == nullptr || !root->left && !root->right)
        return 0;

    // hypothesis
    int leftSubtree = height(root->left);
    int rightSubtree = height(root->right);

    // induction
    int maxHeight = max(leftSubtree, rightSubtree) + 1;
    return maxHeight;
}

// Driver function
int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(12);
    root->left->left->right = new TreeNode(22);

    cout << height(root) << endl;

    return 0;
}
