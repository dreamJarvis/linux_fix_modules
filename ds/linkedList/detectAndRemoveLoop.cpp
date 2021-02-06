// given a ll with a loop, find the starting point of the loop
#include <bits/stdc++.h>
using namespace std;

// definatation Node
struct Node {
    int key;
    Node *next;
};

// to Create a new Node
Node* newNode(int data){
    Node* temp = new Node();
    temp->key = data;
    temp->next = nullptr;
    return temp;                        // new node
}

// to display a linked list
void printList(Node *head){
    while(head != nullptr){
        cout << head->key << " ";
        head = head->next;
    }
    cout << "\n";
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

// function to detect and remove loop in a linked list that may contain loop
void detectAndRemoveLoop(Node *head){
    // if list is empty or has only one node without loop
    if(head == nullptr || head->next == nullptr)
        return ;

    Node *slow = head, *fast = head;

    // move slow and fast pointers move 1 and 2 steps ahead at a time
    slow = slow->next;
    fast = fast->next->next;

    // searching for loop using slow and fast pointers
    while(slow != fast){
        slow = slow->next;
        fast = fast->next->next;
    }

    // if loop does not exist
    if(slow != fast)    return ;

    // if loop exists, then have a ptr from head and a pointer from where the fast and slow ptr meets, then move both of these pointer ahead by one step, the point where they meet is the starting point of the loop
    Node *prev = nullptr;
    while(head != slow){
        prev = slow;
        head = head->next;
        slow = slow->next;
    }

    prev->next = nullptr;
}

// Driver function
int main(){
    Node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);

    // Create a loop for testing
    head->next->next->next->next->next = head->next->next;

    detectAndRemoveLoop(head);

    printList(head);

    return 0;
}
