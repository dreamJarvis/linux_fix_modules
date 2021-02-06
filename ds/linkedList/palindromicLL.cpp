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

bool isPalindrome(Node *head){
    Node *slowPtr = head;
    Node *fastPtr = head;
    Node *rev = nullptr;

    while(fastPtr && fastPtr->next){
        fastPtr = fastPtr->next->next;
        Node *temp = slowPtr->next;         // ye original list ko point krega
        slowPtr->next = rev;
        rev = slowPtr;
        slowPtr = temp;
    }

    if(fastPtr)
        slowPtr = slowPtr->next;

    while(slowPtr && rev){
        if(slowPtr->data != rev->data)
            return false;
        slowPtr = slowPtr->next;
        rev = rev->next;
    }

    return true;
}

// Driver function
int main(){
    Node *head = nullptr;
    head = insertAtFront(head, 1);
    head = insertAtFront(head, 2);
    head = insertAtFront(head, 3);
    head = insertAtFront(head, 2);
    head = insertAtFront(head, 1);
    // head = insertAtFront(head, 30);
    // head = insertAtFront(head, 40);

    cout << isPalindrome(head) << endl;

    return 0;
}
