// To merge 2 sorted linked list using recursion
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *createNode(int data){
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void insertNode(Node *&root, int data){
    Node *node = createNode(data);

    if(root == nullptr){
        root = node;
        return ;
    }

    node->next = root;
    root = node;
    return ;
}

void display(Node *root){
    while(root != nullptr){
        cout << root->data << " ";
        root = root->next;
    }
    cout << endl;
    return ;
}

Node *mergeSortedLL(Node *a, Node *b){
    Node *result = nullptr;

    // base cases :
    if(a == nullptr)    return b;
    else if(b == nullptr)   return a;

    // pick either a or b
    if(a->data <= b->data){
        result = a;
        result->next = mergeSortedLL(a->next, b);
    }
    else {
        result = b;
        result->next = mergeSortedLL(a, b->next);
    }

    return result;
}

// Driver function
int main(){
    Node *list_1 = nullptr;
    insertNode(list_1, 98);
    insertNode(list_1, 57);
    insertNode(list_1, 31);
    insertNode(list_1, 30);
    insertNode(list_1, 10);


    display(list_1);

    Node *list_2 = nullptr;
    insertNode(list_2, 120);
    insertNode(list_2, 88);
    insertNode(list_2, 67);
    insertNode(list_2, 23);
    insertNode(list_2, 1);

    display(list_2);


    Node *result = mergeSortedLL(list_1, list_2);

    display(result);
    return 0;
}
