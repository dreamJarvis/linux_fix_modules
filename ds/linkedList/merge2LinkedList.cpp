// to merge two linked lists
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

// to insert a node in a linked list
// insert's a node at the head
//  ll : 2->4->8, insert(10); => 10 -> 2 -> 4 -> 8
void insertNode(Node* &root, int data){
    Node *node = createNode(data);

    if(root == nullptr){
        root = node;//98
        return ;
    }

    node->next = root;
    root = node;
    return ;
}

// insert at tail
void insertAtTail(Node *&root, int data){
    Node *node = createNode(data);

    // agar head null h toh, head me value insert kr denge
    if(root == nullptr){
        root = node;
        return ;
    }

    Node *temp = root;
    while(temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
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

void MoveNode(Node *&destRef, Node *&sourceRef){
    // front source node
    Node *newNode = sourceRef;
    assert(newNode != nullptr);

    // advance the source pointer
    sourceRef = newNode->next;

    // link the old dest off the new node
    newNode->next = destRef;

    // move to the point to the new node
    destRef = newNode;
}

Node *mergeSortedLL(Node *a, Node *b){
    Node *result = nullptr;

    // point to the last pointer
    Node **lastPtrRef = &result;

    while(true){
        if(a == nullptr){
            *lastPtrRef = b;
            break;
        }else if(b == nullptr){
            *lastPtrRef = a;
            break;
        }

        if(a->data <= b->data){
            MoveNode(*lastPtrRef, a);
        }
        else{
            MoveNode(*lastPtrRef, b);
        }

        // advance to point to the next ".next" field
        lastPtrRef = &((*lastPtrRef)->next);
    }

    return result;
}

// Driver function
int main(){
    Node* list_1 = nullptr;
    insertNode(list_1, 98);
    insertNode(list_1, 57);
    insertNode(list_1, 31);
    insertNode(list_1, 30);
    insertNode(list_1, 10);

    // head = nullptr
    // insert(98), head -> 98
    // insert(57), head -> 57 -> 98


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
