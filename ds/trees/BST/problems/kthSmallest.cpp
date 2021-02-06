/*
    230. Kth Smallest Element in a BST
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

// brute force
// time : O(n), space : O(n)
class SolutionI {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> st;
        helper(root, st);
        return st[k-1];
    }

    void helper(TreeNode *root, vector<int> &st){
        if(!root) return;

        helper(root->left, st);
        st.push_back(root->val);
        helper(root->right, st);
    }
};

class SolutionII {
public:
    int kthSmallest(TreeNode* root, int k) {
        int kthMin = INT_MAX;
        helper(root, k, kthMin);
        if(k-1 == 0)
            return root->val;
        return (kthMin);
    }

    void helper(TreeNode *root, int &k, int &kthMin){
        if(!root){
            return;
        }

        helper(root->left, k, kthMin);
        k--;
        if(k == 0){
            kthMin = root->val;
        }
        helper(root->right, k, kthMin);
    }
};

class SolutionIII {
public:
    void utility(TreeNode* root, int k, int &c, int &res){
        if(root==NULL || c>=k) return;

        utility(root->left, k, c, res);
        c++;

        if(c==k){
            res = root->val;
            return;
        }
        utility(root->right, k, c, res);
    }

    int kthSmallest(TreeNode* root, int k) {
        int c=0;
        int res=-1;
        utility(root, k, c, res);
        return res;
    }
};

// Driver function
int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    SolutionIII s;
    cout << s.kthSmallest(root, 1) << endl;

    return 0;
}
