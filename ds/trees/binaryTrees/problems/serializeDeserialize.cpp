/*
    Serialize and Deserialize a Binary Tree
    https://www.geeksforgeeks.org/serialize-deserialize-binary-tree/

    leetcode 297. Serialize and Deserialize Binary Tree
    https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
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

class Codec {
public:
    string serialize(TreeNode *root){
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    TreeNode *deserialize(string data){
        istringstream in(data);
        return deserialize(in);
    }

private:
    void serialize(TreeNode* root, ostringstream& out) {
        if (root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        }else {
            out << "# ";
        }
    }

    TreeNode *deserialize(istringstream &in){
        string val;
        in >> val;
        if(val=="#")
            return nullptr;

        TreeNode *root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};

void inorderTraversal(TreeNode *root){
    if(!root)   return;

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// Driver function
int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Codec codec;
    string ser = codec.serialize(root);

    cout << ser << endl;

    // TreeNode *head = codec.deserialize( codec.serialize(root));
    inorderTraversal(codec.deserialize( codec.serialize(root)));

    return 0;
}
