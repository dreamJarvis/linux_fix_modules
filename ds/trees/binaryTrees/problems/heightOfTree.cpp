/*
    To find the height of tree
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

int heightOfTree(Node *root){
    if(!root)   return -1;

    return (
        max(
            heightOfTree(root->left),
            heightOfTree(root->right)
        ) + 1
    );
}

// Driver function
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(15);

    cout << "Height : " << heightOfTree(root) << endl;

    return 0;
}
