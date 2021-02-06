// binary tree deletion
/*
    Given a binary tree, delete a node from it by making sure that tree shrinks from the bottom (i.e. the deleted node is replaced by bottom most and rightmost node).
    This different from BST deletion. Here we do not have any order among elements, so we replace with last element.
*/

// NOT WORKING 

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left, *right;

    Node(int x){
        key = x;
        left = right = nullptr;
    }
};

// using BFS
void insert(Node *root, int data){
    queue<Node *> q;
    q.push(root);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        // if left child is empty
        if(temp->left)
            q.push(temp->left);
        else {
            temp->left = new Node(data);
            break;
        }

        // if right child is empty
        if(temp->right)
            q.push(temp->right);
        else {
            temp->right = new Node(data);
            break;
        }
    }
}

// to find the k'th element Node in a binary tree
Node *findKthElement(Node *root, int key){
    if(!root)   return nullptr;

    if(root->key == key)   return root;

    Node *left = findKthElement(root->left, key);
    Node *right = findKthElement(root->right, key);

    return (left != nullptr ? left : right);
}

// find parent node of k'th node element
Node *findParent(Node *root, int key){
    if(!root)   return nullptr;

    if( root->left != nullptr && root->left->key == key ||
        root->right != nullptr && root->right->key == key)
    {
            return root;
    }

    // if we can't find it on the left side, look to the right side
    Node *parent = findParent(root->left, key);
    if(!parent)
        parent = findParent(root->right, key);
    return parent;
}

// finding the bottom-most right-most node using recursion
// Node *bottomRightMost(Node *root){
//     if(root->left == nullptr && root->right == nullptr)
//         return root;
//
//     if(!root->right)
//         return bottomRightMost(root->left);
//     return bottomRightMost(root->right);
// }

// // deletion - iteration
// void deletion(Node *root, int key){
//     Node *parentDel = findParent(root, key);
//     Node *lastNode = bottomRightMost(root);
//     Node *toBeDel = findKthElement(root, key);
//     Node *parentLast = findParent(root, lastNode->key);
//
//     if(toBeDel == lastNode){
//         parentLast->right = nullptr;
//         delete lastNode;
//         return ;
//     }
//
//     // step 1s; bottom Right Most node krne wale parent ko null ko pt krna h
//     parentLast->right = nullptr;
//
//     lastNode->left = toBeDel->left;
//     lastNode->right = toBeDel->right;
//
//     if(parentDel->left == toBeDel){
//         parentDel->left = lastNode;
//     }
//     else{
//         parentDel->right = lastNode;
//     }
//
//     delete toBeDel;
// }

// inorder traversal for trees
void inorderTraversal(Node *head){
    if(!head)   return;

    inorderTraversal(head->left);
    cout << head->key << " ";
    inorderTraversal(head->right);
}

// Driver function
int main(){
    vector<int> arr({10, 11, 3, 2, 45, 1, 64});

    Node *btree = new Node(76);     // root node
    for(auto i:arr)
        insert(btree, i);

    inorderTraversal(btree);
    cout << "\n\n";

    deletion(btree, 1);
    inorderTraversal(btree);
    cout << "\n\n";

    // deletion(btree, 2);
    // inorderTraversal(btree);

    // cout << findParent(btree, 64)->key << endl;
    cout << bottomRightMost(btree)->key << endl;

    return 0;
}
