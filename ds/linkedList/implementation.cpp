// given a ll with a loop, find the starting point of the loop
#include <bits/stdc++.h>
using namespace std;

// definatation Node
struct Node {
    int key;
    Node *next;
};

// creates a node
Node *createNode(int data){
    Node *newNode = new Node();
    newNode->key = data;
    newNode->next = nullptr;
    return newNode;
}

// to Create a new Node
Node* newNode(int data){
    Node* temp = new Node();
    temp->key = data;
    temp->next = nullptr;
    return temp;                        // new node
}

// to insert a node in a linked list
// insert's a node at the head
//  ll : 2->4->8, insert(10); => 10 -> 2 -> 4 -> 8
void insertAtFront(Node* &root, int data){
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

    Node *temp = root;                  // temp node to store the address the head
    while(temp->next != nullptr)        // traverse to the end of the ll
        temp = temp->next;

    temp->next = node;                  // insert value at the end of LL
    return ;
}

// to display a linked list
void printList(Node *head){
    while(head != nullptr){
        cout << head->key << " ";
        head = head->next;
    }
    cout << "\n";
}

// Driver function
int main(){
    Node* head = nullptr;

    insertAtFront(head, 10);
    insertAtFront(head, 20);
    insertAtFront(head, 30);
    insertAtFront(head, 40);
    printList(head);

    insertAtTail(head, 50);
    insertAtTail(head, 60);
    insertAtTail(head, 70);
    printList(head);

    return 0;
}
