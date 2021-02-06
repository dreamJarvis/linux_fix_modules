// middle of the linked list
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* middleNode(ListNode* head){
    if(head == nullptr) return nullptr;

    int len = 0;
    ListNode *temp = head;
    while(temp != nullptr){
        temp = temp->next;
        len++;
    }

    len/=2;
    temp = head;
    while(--len){
        temp = temp->next;
    }

    return temp;
}

// Driver function
int main(){
    ListNode *root;

    return 0;
}
