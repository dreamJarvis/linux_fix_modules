/*
    95. Unique Binary Search Trees II
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
    vector<TreeNode *> helper(int start, int end){
        vector<TreeNode *> res;
        if(start > end){
            res.push_back(NULL);
            return res;
        }

        for(int i = start; i <= end; i++){
            vector<TreeNode *> lefts = helper(start, i-1);
            vector<TreeNode *> rights = helper(i+1, end);

            for(int j = 0; j < (int)lefts.size(); j++){
                for(int k = 0; k < (int)rights.size(); k++){
                    TreeNode *root = new TreeNode(i);
                    root->left = lefts[j];
                    root->right = rights[k];
                    res.push_back(root);
                }
            }
        }

        return res;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)  return (vector<TreeNode*>({0}));
        return helper(1, n);
    }

    void preorder(TreeNode *root){
        if(!root)   return;

        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
};

// Driver function
int main(){
    int n = 3;

    Solution s;
    for(auto i:s.generateTrees(n)){
        s.preorder(i);
        cout << "\n";
    }

    cout << endl;

    return 0;
}
