// Remove all elements from a linked list of integers that have value val.
#include <bits/stdc++.h>
using namespace std;


 // Definition for singly-linked list.
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// insert elements head-on
ListNode *insertTail(ListNode *tail, int data){
    ListNode *node = new ListNode(data);
    if(tail == nullptr){
        tail = node;
        return node;
    }

    tail->next = node;
    return node;
}

// removes all k's from the linked list
// t : O(n)
// s : O(1)
ListNode *removeK(ListNode *head, int val){
    if(head == nullptr) return head;
    ListNode *p = head;

    // except the 1st element it skips all k element from the list
    while(p->next != nullptr){
        if(p->next->val == val)     p->next = p->next->next;
        else                        p = p->next;
    }

    // if the 1st element is k
    if(head->val == val)
        head = head->next;

    return head;
}

// display ll

void displayList(ListNode *root){
    while(root != nullptr){
        cout << root->val << " ";
        root = root->next;
    }
}

// Driver function
int main(){
    ListNode *root = nullptr, *tail = nullptr;
    root = insertTail(root, 1);
    tail = insertTail(root, 2);
    tail = insertTail(tail, 6);
    tail = insertTail(tail, 3);
    tail = insertTail(tail, 5);
    tail = insertTail(tail, 6);

    displayList(root);
    cout << "\n\n";
    displayList(removeK(root, 6));

    return 0;
}
