/*
    Write a program to Calculate Size of a tree
    https://www.geeksforgeeks.org/write-a-c-program-to-calculate-size-of-a-tree/
*/
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left, *right;

    Node(int x){
        key = x;
        left = right = nullptr;
    }
};

// total number of nodes in the tree
int sizeOfTreeRecursive(Node *root){
    if(!root)   return 0;
    return (sizeOfTreeRecursive(root->left) + 1 + sizeOfTreeRecursive(root->right));
}

int sizeOfTreeIterative(Node *root){
    queue<Node *> q;
    q.push(root);

    if(!root)   return 0;

    int count = 1;
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        if(temp->left){
            count++;
            q.push(temp->left);
        }

        if(temp->right){
            count++;
            q.push(temp->right);
        }
    }

    return count;
}

// Driver function
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // cout << "size of tree : " << sizeOfTreeRecursive(root) << endl;
    cout << "size of tree : " << sizeOfTreeIterative(root) << endl;

    return 0;
}
