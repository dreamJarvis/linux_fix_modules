/*
    leetcode 107. Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode *> q;

        if(!root)   return res;

        q.push(root);
        q.push(NULL);

        vector<int> ans;
        while(q.size() > 1){
            TreeNode *temp = q.front();
            q.pop();

            if(temp == NULL){
                q.push(NULL);
                res.push_back(ans);
                ans = vector<int>();            // cleaning the array after each level
            }
            else{
                ans.push_back(temp->val);
                if(temp->left)  q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        res.push_back(ans);

        vector<vector<int>> temp;
        for(int i = res.size()-1; i >= 0; i--)
            temp.push_back(res[i]);

        return temp;
    }
};

int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    for(auto i:s.levelOrderBottom(root)){
        for(auto j:i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
