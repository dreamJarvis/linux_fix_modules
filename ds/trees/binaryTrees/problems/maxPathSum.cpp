/*
    Leetcode 124. Binary Tree Maximum Path Sum
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

// O(n)
int maxPathSumUtil(TreeNode *root, int &maxSum){
    if(!root)
        return INT_MIN;

    int leftSubtreeMax = maxPathSumUtil(root->left, maxSum);
    int rightSubtreeMax = maxPathSumUtil(root->right, maxSum);

    int ifPathContinues = max(
                            max(leftSubtreeMax, rightSubtreeMax) + root->val,
                            root->val
                        );
    int ifPathDoesntContinue = max(
                                leftSubtreeMax + rightSubtreeMax + root->val,
                                ifPathContinues
                            );
    maxSum = max(maxSum, ifPathDoesntContinue);

    return ifPathContinues;
}

//Alternate and concise code by Prankishor

/*
int findMaxSum (TreeNode *root, int &maxsum)
{
	if(root == NULL)
	{
		return 0;
	}
	
	int l = findMaxSum(root->left, res);
	int r = findMaxSum(root->right, res);
	
	//first case
	int temp = max(max(l,r)+root->data, root->data);
	//2nd case
	int ans = max(temp, l+r+root->data);
	
	res = max(res, ans);
	
	return temp;
}
*/

int maxPathSum(TreeNode *root){
    int maxSum = INT_MIN;
    maxPathSumUtil(root, maxSum);
    //findMaxSum(root, maxSum);
    return maxSum;
}

// Driver function
int main(){
    TreeNode *root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right= new TreeNode(7);

    // TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(-2);
    // root->right = new TreeNode(3);

    // TreeNode *root = new TreeNode(5);
    // root->left = new TreeNode(4);
    // root->right = new TreeNode(8);
    // root->left->left = new TreeNode(11);
    // root->left->left->left = new TreeNode(7);
    // root->left->left->right = new TreeNode(2);
    // root->right->left = new TreeNode(13);
    // root->right->right = new TreeNode(4);
    // root->right->right->right = new TreeNode(1);

    // TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(-2);
    // root->right = new TreeNode(-3);
    // root->left->left = new TreeNode(1);
    // root->left->right= new TreeNode(3);
    // root->right->left = new TreeNode(-2);
    // root->right->left->left = new TreeNode(-1);

    // TreeNode *root = new TreeNode(-1);
    // root->left = new TreeNode(5);
    // root->left->left = new TreeNode(4);
    // root->left->left->right= new TreeNode(-4);
    // root->left->left->left = new TreeNode(2);

    // TreeNode *root = new TreeNode(-1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(2);
    // root->left->left = new TreeNode(3);
    // root->left->right = new TreeNode(-2);
    // root->left->left->left = new TreeNode(-1);
    // root->left->left->right = new TreeNode(-1);

    // int maxVal = 0;
    cout << maxPathSum(root) << endl;
    // cout << maxVal << endl;

    return 0;
}
