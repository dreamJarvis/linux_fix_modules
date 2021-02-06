// Binary search tree
#include <bits/stdc++.h>
using namespace std;

// Tree node
struct TreeNode{
    int val;
    TreeNode *left, *right;

    TreeNode(int x){
        val = x;
        left = right = nullptr;
    }
};

// insertion in tree
TreeNode *insert(TreeNode *root, int key){
    if(!root)   return new TreeNode(key);

    // inserting accordingly to values
    if(key < root->val)                                 // if val is smaller than root
        root->left = insert(root->left, key);
    else if(key > root->val)                            // if val is larger than root
        root->right = insert(root->right, key);

    return root;                                        // return current value
}

// search for an element in the tree
bool search(TreeNode *root, int k){
    // if(!root || root->val == k)
    //     return root;
    if(!root)   return false;
    if(root->val == k)  return true;

    if(root->val < k)
        return search(root->right, k);
    return search(root->left, k);
}

// deletion : deleting an k'th item from the tree
TreeNode *deleteNode(TreeNode *root, int k){
    // base case
    if(root == nullptr) return root;

    if(k < root->val)
        root->left = deleteNode(root->left, k);
    else if(k > root->val)
        root->right = deleteNode(root->right, k);
    else{
        // node with one child or no child
        if(root->left == nullptr){
            TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == nullptr){
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        // node with 2 children : get inorder successor (smallest in the right)
        TreeNode *temp = root->right;
        while(temp && temp->left)
            temp = temp->left;


        root->val = temp->val; // copy the inorder successor's content to this node
        root->right = deleteNode(root->right, temp->val); // delete the inorder successor
    }

    return root;
}

// ================================= Traversals ====================================== //
// inorder trversal
void inorderTraversal(TreeNode *root){
    if(!root)   return ;

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// preOrder traversal
void preOrderTraversal(TreeNode *root){
    if(!root)   return ;

    cout << root->val <<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// post order traversals
void postOrderTraversals(TreeNode *root){
    if(!root)   return;

    postOrderTraversals(root->left);
    postOrderTraversals(root->right);
    cout << root->val << " ";
}

// Driver function
int main(){
    TreeNode *root = nullptr;
    root = insert(root, 50);

    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // cout << search(root, 40) << endl;

    inorderTraversal(root);
    cout << "\n";
    root = deleteNode(root, 70);
    inorderTraversal(root);

    return 0;
}
