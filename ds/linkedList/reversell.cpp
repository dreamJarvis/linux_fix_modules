// To reverse a linked list
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node *createNode(int k){
    Node *newNode = new Node();
    newNode->data = k;
    newNode->next = nullptr;
    return newNode;
}

Node *insertAtFront(Node *head, int data){
    Node *newNode = createNode(data);
    if(head == nullptr){
        return newNode;
    }

    newNode->next = head;
    head = newNode;
    return head;
}

void displayList(Node *head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
}

// reverse a ll
Node *reverseLL(Node *head, Node *&root){
    if(head->next == nullptr){
        root = head;
        return head;
    }

    reverseLL(head->next, root)->next = head;
}

// Driver function
int main(){
    Node *head = nullptr;
    head = insertAtFront(head, 10);
    head = insertAtFront(head, 20);
    head = insertAtFront(head, 30);
    head = insertAtFront(head, 40);

    displayList(head);

    reverseLL(head, head)->next = nullptr;

    cout << "\n";
    displayList(head);

    return 0;
}
