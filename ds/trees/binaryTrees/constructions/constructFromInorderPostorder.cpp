/*
    Construct a Binary Tree from Postorder and Inorder
    https://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/
*/
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

Node *constructTree(    vector<int> &inorder, vector<int> &postorder,
                        unordered_map<int, int> &map, int start, int end
){
    static int preIndex = inorder.size()-1;           // global variable pointing to the next index

    if(start > end) return nullptr;

    Node *currNode = new Node(postorder[preIndex--]);                          // root
    int key = currNode->key;

    // if the node has no child, return
    if(start == end)    return currNode;

    int index = map[key];

    currNode->right = constructTree(inorder, postorder, map, index+1, end);     // right
    currNode->left = constructTree(inorder, postorder, map, start, index-1);    // left

    return currNode;
}

Node *constructTreeUTIL(vector<int> &inorder, vector<int> &postorder){
    int n = inorder.size();
    unordered_map<int, int> map;

    for(int i = 0; i < n; i++)
        map[inorder[i]] = i;

    return constructTree(inorder, postorder, map, 0, n-1);
}

void inorderTraversal(Node *head){
    if(!head)   return;

    inorderTraversal(head->left);
    cout << head->key << " ";
    inorderTraversal(head->right);
}

// Driver function
int main(){
    vector<int> inorder({4, 8, 2, 5, 1, 6, 3, 7});
    vector<int> postorder({8, 4, 5, 2, 6, 7, 3, 1});

    Node *root = constructTreeUTIL(inorder, postorder);
    inorderTraversal(root);

    return 0;
}
