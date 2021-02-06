/*
    Construct Full Binary Tree from given preorder and postorder traversals
    https://www.geeksforgeeks.org/full-and-complete-binary-tree-from-given-preorder-and-postorder-traversals/
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

Node *constructTree(    vector<int> preorder, vector<int> postorder,
                        unordered_map<int, int> &map, int start, int end
){
    static int preIndex = 0;            // pointing to the next root

    if(preIndex > preorder.size()-1 || start > end)    return nullptr;

    Node *currRoot = new Node(preorder[preIndex++]);

    if(start == end)    return currRoot;

    int index = map[preorder[preIndex]];

    // the next root, should lie within the index of the previous range
    if(index <= end){
        currRoot->left = constructTree(preorder, postorder, map, start, index);     // left
        currRoot->right = constructTree(preorder, postorder, map, index+1, end);    // right
    }

    return currRoot;
}

Node *constructTreeUTIL(vector<int> preorder, vector<int> postorder){
    int n = preorder.size();
    unordered_map<int, int> map;

    for(int i = 0; i < n; i++)
        map[postorder[i]] = i;

    return constructTree(preorder, postorder, map, 0, n-1);
}

void inorderTraversal(Node *head){
    if(!head)   return;

    inorderTraversal(head->left);
    cout << head->key << " ";
    inorderTraversal(head->right);
}

// Driver function
int main(){
    // vector<int> preorder({1, 2, 4, 8, 9, 5, 3, 6, 7});
    // vector<int> postorder({8, 9, 4, 5, 2, 6, 7, 3, 1});
    vector<int> preorder({20, 15, 10, 5, 12, 18, 25, 2\4, 30});
    vector<int> postorder({5, 12, 10, 18, 15, 24, 30, 25, 20});

    Node *root = constructTreeUTIL(preorder, postorder);

    inorderTraversal(root);

    return 0;
}
