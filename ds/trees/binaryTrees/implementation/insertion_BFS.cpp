// binary tree implementatinon
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

// inorder traversal for trees
void inorderTraversal(Node *head){
    if(!head)   return;

    inorderTraversal(head->left);
    cout << head->key << " ";
    inorderTraversal(head->right);
}

// Driver function
int main(){
    vector<int> arr({10, 11, 3, 2, 34, 67, 1, 45});

    Node *btree = new Node(76);     // root node
    for(auto i:arr)
        insert(btree, i);

    inorderTraversal(btree);


    return 0;
}
