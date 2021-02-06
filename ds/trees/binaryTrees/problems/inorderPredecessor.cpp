#include <bits/std++.h>
using namespace std;

int main(){
    TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(12);
	root->right = new TreeNode(15);
	root->left->left = new TreeNode(25);
	root->left->right = new TreeNode(30);
	root->right->left = new TreeNode(36);



    return 0;
}
