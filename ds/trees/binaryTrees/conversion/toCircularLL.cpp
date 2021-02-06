/*
    Convert a Binary Tree to a Circular Doubly Link List
    https://www.geeksforgeeks.org/convert-a-binary-tree-to-a-circular-doubly-link-list/
    https://www.youtube.com/watch?v=Dte6EF1nHNo&t=47s
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;

    TreeNode(int x){
        val = x;
        left = right = nullptr;
    }
};

TreeNode *concatenate(TreeNode *a, TreeNode *b){
    if(!a)   return b;
    if(!b)  return a;

    TreeNode *aEnd = a->left;
    TreeNode *bEnd = b->left;

    a->left = bEnd;
    bEnd->right = a;
    aEnd->right = b;
    b->left = aEnd;
    return a;
}

TreeNode *CLL(TreeNode *root){
    if(!root)   return root;

    TreeNode *leftList = CLL(root->left);
    TreeNode *rightList = CLL(root->right);

    root->left = root;
    root->right = root;

    root = concatenate(leftList, root);
    root = concatenate(root, rightList);
    return root;
}

void printList(TreeNode *head){
    TreeNode *root = head;
    cout << root->val << " ";
    root = root->right;
    while(root != head){
        cout << root->val << " ";
        root = root->right;
    }
}

// Driver function
int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    TreeNode *head = CLL(root);
    printList(head);

    return 0;
}
