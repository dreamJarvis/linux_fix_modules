// C++ program to delete element in binary tree
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has key, pointer to left
child and a pointer to right child */
struct Node {
	int key;
	Node *left, *right;

    Node(int x){
        key = x;
        left = right = nullptr;
    }
};


/* Inorder traversal of a binary tree*/
void inorder(Node* temp){
	if (!temp) return;

	inorder(temp->left);
	cout << temp->key << " ";
	inorder(temp->right);
}

/* function to delete the given deepest node
(d_node) in binary tree */
void deletDeepest(Node* root, Node* d_node){
	queue<Node*> q;
	q.push(root);

	// Do level order traversal until last node
	Node* temp;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		if (temp == d_node) {
			temp = NULL;
			delete (d_node);
			return;
		}
		if (temp->right) {
			if (temp->right == d_node) {
				temp->right = NULL;
				delete (d_node);
				return;
			}
			else
				q.push(temp->right);
		}

		if (temp->left) {
			if (temp->left == d_node) {
				temp->left = NULL;
				delete (d_node);
				return;
			}
			else
				q.push(temp->left);
		}
	}
}

/* function to delete element in binary tree */
Node* deletion(Node* root, int key)
{
	if (root == NULL)
		return NULL;

	if (root->left == NULL && root->right == NULL) {
		if (root->key == key)
			return NULL;
		else
			return root;
	}

	queue<Node*> q;
	q.push(root);

	Node* temp;
	Node* key_node = NULL;

	// Do level order traversal to find deepest
	// node(temp) and node to be deleted (key_node)
	while (!q.empty()) {
		temp = q.front();
		q.pop();

		if (temp->key == key)
			key_node = temp;

		if (temp->left)
			q.push(temp->left);

		if (temp->right)
			q.push(temp->right);
	}

	if (key_node != NULL) {
		int x = temp->key;
		deletDeepest(root, temp);
		key_node->key = x;
	}
	return root;
}

void insert(Node *root, int data){
    queue<Node *> q;
    q.push(root);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        // if left child is empty
        if(temp->left)
            q.push(temp->left);
        else {
            temp->left = new Node(data);
            break;
        }

        // if right child is empty
        if(temp->right)
            q.push(temp->right);
        else {
            temp->right = new Node(data);
            break;
        }
    }
}

// Driver code
int main(){
    Node* root = new Node(10);                      // initializing the root
    vector<int> arr({11, 9, 7, 12, 15, 8});

    // inserting elements in tree
    for(auto i:arr)
        insert(root, i);

	cout << "Inorder traversal before deletion : ";
	inorder(root);

	int key = 11;
	root = deletion(root, key);

	cout << endl;
	cout << "Inorder traversal after deletion : ";
	inorder(root);

	return 0;
}
