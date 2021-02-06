/*
    Write a function to get the intersection point of two Linked Lists? Implement both techniques
    without a hashtable and with hash table?

    leetcode 160. Intersection of Two Linked Lists
    https://leetcode.com/problems/intersection-of-two-linked-lists/
*/
#include <bits/stdc++.h>
using namespace std;

// with hashtable
// tc : O(M+N)
// sc O (N) or O(M)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode *, bool> mp;

        if(!headA || !headB)    return nullptr;

        while(headA != nullptr){
            mp[headA] = true;
            headA = headA->next;
        }

        while(headB != nullptr){
            if(mp.count(headB))
                return headB;
            headB = headB->next;
        }

        if(!headA && !headA)    return nullptr;
        return nullptr;
    }
};

// without hashtable
// using 2 ptr technique
// tc : O(n+m)
// sc : O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1 = headA, *temp2 = headB;

        int countA=0, countB=0;

        while(temp1 != nullptr){
            temp1 = temp1->next;
            countA++;
        }

        while(temp2 != nullptr){
            temp2 = temp2->next;
            countB++;
        }

        temp1 = headA, temp2 = headB;

        int diff = abs(countA - countB);

        if(countB > countA){
            swap(temp1, temp2);
        }

        while(diff--){
            temp1 = temp1->next;
        }


        while(temp1 != temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return temp1;
    }
};

// Driver function
int main(){
    return 0;
}
