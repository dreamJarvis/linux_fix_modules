/*
    Given Inorder and Postorder traversals of a binary tree, print Preorder traversal.
    https://www.geeksforgeeks.org/preorder-from-inorder-and-postorder-traversals/?ref=rp
*/
#include <bits/stdc++.h>
using namespace std;

int preIndex = 0;

// tc : O(n^2)
// sc : 2*O(n), for using hash-map, stack
void preorder( vector<int> &inorder, vector<int> &postorder,
                unordered_map<int, int> &map, stack<int> &s, int left, int right)
{
    if(left > right)
        return ;

    int val = postorder[preIndex];
    int index = map[postorder[preIndex--]];

    preorder(inorder, postorder, map, s, index+1, right);       // right sub-tree
    preorder(inorder, postorder, map, s, left, index-1);        // left sub-tree

    s.push(val);                                                // root
}

void preorderUtil(vector<int> &inorder, vector<int> &postorder){
    int n = inorder.size();
    preIndex = n - 1;
    unordered_map<int, int> mp;
    stack<int> s;

    for(int i = 0; i < n; i++)
        mp[inorder[i]] = i;

    preorder(inorder, postorder, mp, s, 0, n-1);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}

// Driver function
int main(){
    vector<int> inorder({4, 2, 5, 1, 3, 6});
    vector<int> postorder({4, 5, 2, 6, 3, 1});

    preorderUtil(inorder, postorder);

    return 0;
}
