/*
    Print level order traversal line by line | Set 1
    https://www.geeksforgeeks.org/print-level-order-traversal-line-line/
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

// tc : O(nlog(n))
void levelOrderTraversal(Node *root){
    queue<Node *> q;
    q.push(root);

    int height = -1;

    while(!q.empty()){                                      // log(n)
        queue<Node *>temp = q;

        while(!q.empty()){                                  // n
            cout << (q.front())->key << " ";
            q.pop();
        }
        cout << "\n";

        while(!temp.empty()){                               // n
            Node *t = temp.front();
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);

            temp.pop();
        }

        height++;
    }

    cout << "height : " << height << endl;
}

// using 2 queues
// tc : O(nlog(n))
void levelOrderTraversalII(Node *root){
    queue<Node *> q1, q2;

    if(root == nullptr) return ;

    q1.push(root);

    while(!q1.empty() || !q2.empty()){
        while(!q1.empty()){
            if(q1.front()->left != nullptr)
                q2.push(q1.front()->left);

            if(q1.front()->right != nullptr)
                q2.push(q1.front()->right);

            cout << q1.front()->key << " ";
            q1.pop();
        }

        cout << "\n";

        while(!q2.empty()){
            if(q2.front()->left != nullptr)
                q1.push(q2.front()->left);

            if(q2.front()->right != nullptr)
                q1.push(q2.front()->right);

            cout << q2.front()->key << " ";
            q2.pop();
        }

        cout << "\n";
    }
}

// tc : O(n)
void levelOrderTraversalIII(Node *root){
    queue<Node *> q;

    q.push(root);
    q.push(nullptr);                        // place holder

    while(q.size() > 1){                    // because there will always be null in the stack
        Node *curr = q.front();
        q.pop();

        // puts the place-holder
        if(curr == nullptr){
            q.push(nullptr);
            cout << "\n";
        }
        else{
            if(curr->left)
                q.push(curr->left);

            if(curr->right)
                q.push(curr->right);

            cout << curr->key << " ";
        }
    }
}

// Driver function
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    levelOrderTraversalIII(root);

    return 0;
}
