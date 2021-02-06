// leetocode 111. Minimum Depth of Binary Tree
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
    // BFS
    int minDepthBFS(TreeNode* root) {
        queue<TreeNode *> q;
        int height = 0;

        if(!root)   return height;

        q.push(root);
        while(!q.empty()){
            height++;
            int k = q.size();

            for(int i = 0; i < k; i++){
                TreeNode *temp = q.front();

                if(temp->left != nullptr)  q.push(temp->left);
                if(temp->right != nullptr) q.push(temp->right);

                q.pop();

                if(!temp->left && !temp->right) return height;
            }
        }

        return -1;
    }

    // DFS
    void helper(TreeNode* root, int height, int &minDepth){
        if(!root)   return ;
        if(!root->left && !root->right){
            minDepth = min(minDepth, height+1);
            return ;
        }

        if(root->left)
            helper(root->left, height+1, minDepth);
        if(root->right)
            helper(root->right, height+1, minDepth);
    }

    int minDepthDFS(TreeNode* root) {
        int minDepth = INT_MAX, height = 0;
        helper(root, 0, minDepth);
        return minDepth < INT_MAX ? minDepth : 0;
    }
};

// Driver function
int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    cout << s.minDepthBFS(root) << endl;
    cout << s.minDepthDFS(root) << endl;

    return 0;
}
