/*
    Print Nodes in Top View of Binary Tree
    https://www.geeksforgeeks.org/print-nodes-top-view-binary-tree/?ref=rp
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

// =============================== Method 1 ================================== //

void leftView(TreeNode *root, int level){
    static int currLvl = 0;
    if(!root) return;

    if(currLvl < level){
        cout << root->val << " ";
        currLvl = level;
    }

    leftView(root->left, level+1);
    leftView(root->right, level+1);
    return;
}

void rightView(TreeNode *root, int level){
    static int currLvl = 0;
    if(!root) return;

    if(currLvl < level){
        cout << root->val << " ";
        currLvl = level;
    }

    rightView(root->right, level+1);
    rightView(root->left, level+1);
    return;
}

// top view
// tc : O(nlog(n))
void topView1(TreeNode *root){
    leftView(root, 1);
    rightView(root->right, 1);
}

// ================================= Method 2 ================================== //
/*
Time Complexity of the above implementation is O(nlogn) where n is the number of nodes in the given binary tree with each insertion operation in Map requiring O(log2n) complexity.
*/
void topView2(TreeNode *root, int h, map<int, vector<TreeNode *>, greater<int>> &map){
    if(!root)   return;

    auto i = map[h];
    i.push_back(root);
    map[h] = i;

    topView2(root->left, h+1, map);
    topView2(root->right, h-1, map);
    return ;
}

void topViewUtil(TreeNode *root){
    map<int, vector<TreeNode *>, greater<int>> map;
    topView2(root, 0, map);
    for(auto i:map){
        if(i.first >= 0){
            cout << i.second[0]->val << " ";
        }
        else {
            cout << i.second[i.second.size()-1]->val << " ";
        }
    }
}

// ================================= Method 3 =============================== //
// tc : O(n)
void topView3(TreeNode *root){
    if(!root)   return ;

    unordered_map<int, bool> visited;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});

    while(!q.empty()){
        TreeNode *temp = q.front().first;
        int d = q.front().second;
        q.pop();


        if(!visited.count(d)){
            cout << temp->val << " ";
            visited[d] = true;
        }

        if(temp->left)
            q.push({temp->left, d-1});

        if(temp->right)
            q.push({temp->right, d+1});
    }
}

// Driver function
int main(){
    // TreeNode* root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);
    // root->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(7);
    // root->right->right->right = new TreeNode(8);

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(5);
    root->left->right->right->right = new TreeNode(6);

    topView3(root);

    return 0;
}
