/*
    leetcode 538. Convert BST to Greater Tree
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
    int sum = 0;
public:

    // recursive solution
    // tc : O(n)
    // sc : O(n)
    TreeNode* convertBSTI(TreeNode* root) {
        if(root){
            convertBSTI(root->right);
            sum += root->val;
            root->val = sum;
            convertBSTI(root->left);
        }
        return root;
    }

    // iterative solution
    // tc : O(n)
    // sc : O(n)
    TreeNode *convertBSTII(TreeNode *root){
        int sum = 0;
        TreeNode *node = root;
        stack<TreeNode *> st;

        /* we iterate to the right-most element in the sub-trees, and then add's its value to the sum,
        and add's sum vaue to current nodes val,
        repeat the same process for current nodes predecessor(next smallest element),
        i.e it's left element
        */
        while(!st.empty() || node){

            // pushing all the nodes this sub-trees Maximum in the stack
            while(node){
                st.push(node);
                node = node->right;
            }

            // adding this this nodes value in the sum and then adding it to the node->val
            node = st.top();
            st.pop();
            sum += node->val;
            node->val = sum;

            // after getting the sub-trees maximum node, we will iterate to the nodes smaller than the current nodes
            node = node->left;
        }

        return root;
    }

    TreeNode *convertBSTIII(TreeNode *root){
        int sum = 0;
        TreeNode *node = root;

        while(node){
            // if there is no left, go right

            if(!node->right){
                sum += node->val;
                node->val = sum;
                node = node->left;
            }
            else {
                // find the inorder successor of the current node
                TreeNode *succ = node->right;
                while(succ->left && succ->left != node)
                    succ = succ->left;

                // and attach it's left pointer to the current element
                if(!succ->left){
                    succ->left = node;
                    node = node->right;
                }

                // if the left pointer already exist then, it means we have already visited all nodes before it, so we need not to go over it again and agin, so we remove the left pointer
                else {
                    succ->left = nullptr;
                    sum += node->val;
                    node->val = sum;
                    node = node->left;
                }
            }
        }

        return root;
    }
};

//
void inorderTraversal(TreeNode *root){
    if(!root)   return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// Driver fucntion
int main(){
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(13);

    Solution s;
    // root = s.convertBST(root);
    root = s.convertBSTII(root);
    inorderTraversal(root);

    return 0;
}
