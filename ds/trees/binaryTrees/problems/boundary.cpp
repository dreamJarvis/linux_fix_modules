/*
    Boundary Traversal of binary tree
    https://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/
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

// O(n)
void treeBoundary(TreeNode *root, map<int, vector<int>, greater<int>> &lst , int level){
    if(!root)   return ;

    if(lst.count(level)){
        auto it = lst.find(level);
        it->second.push_back(root->val);
    }else
        lst.insert({level, vector<int>({root->val})});

    treeBoundary(root->left, lst, level+1);
    treeBoundary(root->right, lst, level-1);
}

// O(n)
void printBoundaryOfTree(TreeNode *root){
    if(!root)   return;

    map<int, vector<int>, greater<int>> lst;
    treeBoundary(root, lst, 0);

    cout << "top boundary : ";
    for(auto i:lst){
        auto it = i.second;
        cout << it.front() << " ";
    }
    cout << endl;

    cout << "bottom boundary : ";
    for(auto i:lst){
        auto it = i.second;
        if(it.size() > 1)
            cout << it.back() << " ";
    }

    return ;
}

// Driver function
int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left->right = new TreeNode(8);

    printBoundaryOfTree(root);

    return 0;
}
