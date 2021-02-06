/*
    Morris inorder traversal
    https://www.youtube.com/watch?v=wGXB9OWhPTg
    https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int key) : val(key), left(nullptr), right(nullptr) {}
    TreeNode(int key, TreeNode *left, TreeNode *right) : val(key), left(left), right(right) {}
};

// to traverse the binary tree without recursion and without stack
void MorrisTraversal(TreeNode *root){
    struct TreeNode *curr, *pre;

    if(!root)   return;

    curr = root;
    while(curr){
        if(!curr->left){
            cout << curr->val << " ";
            curr = curr->right;
        }
        else{
            // find the inorder predecessor of current
            pre = curr->left;
            while(pre->right && pre->right != curr)
                pre = pre->right;

            /*make the current as the right child of its inorder predecessor */
            if(!pre->right){
                pre->right = curr;
                curr = curr->left;
            }

            /*revert the changes made in the above if statement, i.e. when we visit the current node who alredy had an predecessor poiting to it, then it means we have completed the traversal of the sub-tree below it's time to print this node, and turn back the nodes ptr's to its orginal state
            */
            else{
                pre->right = nullptr;
                cout << curr->val << " ";
                curr = curr->right;
            }
        }
    }
}

// Driver finction
int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    MorrisTraversal(root);

    return 0;
}
