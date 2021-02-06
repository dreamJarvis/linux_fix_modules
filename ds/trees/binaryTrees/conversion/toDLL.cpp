/*
    Convert a given Binary Tree to Doubly Linked List | Set 1
    https://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list/
*/
#include <bits/stdc++.h>
using namespace std;

// tree node
struct TreeNode{
    int val;
    TreeNode *left, *right;

    TreeNode(int x){
        val = x;
        left = right = nullptr;
    }
};

// =========================================== METHOD 1 ========================================//

TreeNode *btToDllUtil1(TreeNode *root){
    // base case
    if(root == nullptr) return root;

    // convert the left sub-tree and link to root
    if(root->left != nullptr){
        TreeNode *left = btToDllUtil1(root->left);

        // find the inorder predecessor, after this loop left will point to the inorder predecessor
        for(;left->right != nullptr; left = left->right);

        left->right = root;     // make root as the next of predecessor
        root->left = left;      // make predecessor as precious of root
    }

    // convert the right subtree and link to root
    if(root->right != nullptr){
        TreeNode *right = btToDllUtil1(root->right);

        // find the inorder successor, after this loop, right will point to inorder successor
        for(; right->left != nullptr; right = right->left);

        right->left = root;     // make root as the previous of successor
        root->right = right;    // make successor as next of root
    }

    return root;
}

TreeNode *btToDll1(TreeNode *root){
    // base case
    if(root == nullptr) return root;

    root = btToDllUtil1(root);

    // in order to traverse the list , we need the left most node of the tree
    while(root->left != nullptr)
        root = root->left;

    return (root);
}

// =========================================== METHOD 2 ========================================//

// fixing prev pointers
void fixPrevPtr(TreeNode *root){
    static TreeNode *prev = nullptr;
    if(root != nullptr){
        fixPrevPtr(root->left);
        root->left = prev;
        prev = root;
        fixPrevPtr(root->right);
    }
}

// fixing next pointers
TreeNode *fixNextPtr(TreeNode *root){
    static TreeNode *pre = nullptr;

    // to the right-most nodes in the tree, or the last node in dll
    while(root && root->right != nullptr){
        root = root->right;
    }

    while(root && root->left != nullptr){
        pre = root;
        root = root->left;
        root->right = pre;
    }

    return root;    // leftmost node : head of the DLL
}


// tc : O(n)
TreeNode *btToDll2(TreeNode *root){
    // set the previous pointers first
    fixPrevPtr(root);

    // while(root->left){
    //     cout << root->val << " ";
    //     root = root->left;
    // }


    // set the next pointers and return head of DLL
    return fixNextPtr(root);
}

// =========================================== METHOD 3 ========================================//

void btToDll3Util(TreeNode *root, TreeNode **head){
    if(!root)   return;

    static TreeNode *prev = nullptr;

    btToDll3Util(root->left, head);

    if(prev == nullptr){
        *head = root;
    }
    else{
        prev->right = root;
        root->left = prev;
    }
    prev = root;

    btToDll3Util(root->right, head);
}

// tc : O(n)
TreeNode *btToDll3(TreeNode *root){
    TreeNode *head;
    btToDll3Util(root, &head);
    return head;
}


// =========================================== METHOD 3 ========================================//

void btToDll4Util(TreeNode *root, TreeNode **head){
    if(!root)   return;

    btToDll4Util(root->right, head);

    root->right = (*head);

    if(*head)
        (*head)->left = root;
    (*head) = root;

    btToDll4Util(root->left, head);
}

TreeNode *btToDll4(TreeNode *root){
    TreeNode *head = nullptr;
    btToDll4Util(root, &head);
    return head;
}

void printList(TreeNode *head){
    while(head != nullptr){
        cout << head->val << " ";
        head = head->right;
    }
}

// Driver function
int main(){
    TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(12);
	root->right = new TreeNode(15);
	root->left->left = new TreeNode(25);
	root->left->right = new TreeNode(30);
	root->right->left = new TreeNode(36);

    // TreeNode *head = btToDll1(root);
    TreeNode *head = btToDll2(root);
    // TreeNode *head = btToDll3(root);
    // TreeNode *head = btToDll4(root);
    printList(head);

    return 0;
}
/*
TreeNode *root = new TreeNode(-10);
root->left = new TreeNode(9);
root->right = new TreeNode(20);
root->right->left = new TreeNode(15);
root->right->right= new TreeNode(7);

TreeNode *root = new TreeNode(1);
root->left = new TreeNode(-2);
root->right = new TreeNode(3);

TreeNode *root = new TreeNode(5);
root->left = new TreeNode(4);
root->right = new TreeNode(8);
root->left->left = new TreeNode(11);
root->left->left->left = new TreeNode(7);
root->left->left->right = new TreeNode(2);
root->right->left = new TreeNode(13);
root->right->right = new TreeNode(4);
root->right->right->right = new TreeNode(1);

TreeNode *root = new TreeNode(1);
root->left = new TreeNode(-2);
root->right = new TreeNode(-3);
root->left->left = new TreeNode(1);
root->left->right= new TreeNode(3);
root->right->left = new TreeNode(-2);
root->right->left->left = new TreeNode(-1);

TreeNode *root = new TreeNode(-1);
root->left = new TreeNode(5);
root->left->left = new TreeNode(4);
root->left->left->right= new TreeNode(-4);
root->left->left->left = new TreeNode(2);

TreeNode *root = new TreeNode(-1);
root->left = new TreeNode(2);
root->right = new TreeNode(2);
root->left->left = new TreeNode(3);
root->left->right = new TreeNode(-2);
root->left->left->left = new TreeNode(-1);
root->left->left->right = new TreeNode(-1);
*/
