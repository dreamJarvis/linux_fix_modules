/* Given Inorder and Preorder traversals of a binary tree, print Postorder traversal.

https://www.geeksforgeeks.org/print-postorder-from-given-inorder-and-preorder-traversals/
*/
#include <bits/stdc++.h>
using namespace std;

int preIndex = 0;

// tc : O(n)
// sc : O(n), for using hash-map
void postorder( vector<int> &inorder, vector<int> &preorder,
                unordered_map<int, int> &map, int left, int right){
    if(left > right){
        return ;
    }

    int index = map[preorder[preIndex++]];

    postorder(inorder, preorder, map, left, index-1);       // left
    postorder(inorder, preorder, map, index+1, right);      // right

    cout << inorder[index] << " ";                          // root
}

void postOrderUtil(vector<int> &inorder, vector<int> &preorder){
    int n = inorder.size();
    unordered_map<int, int> map;

    for(auto i:preorder)
        map[i] = -1;

    for(int i = 0; i < inorder.size(); i++){
        map[inorder[i]] = i;
    }

    postorder(inorder, preorder, map, 0, n-1);
}

// Driver function
int main(){
    vector<int> inorder({4, 2, 5, 1, 3, 6});
    vector<int> preorder({1, 2, 4, 5, 3, 6});

    postOrderUtil(inorder, preorder);

    return 0;
}
