// leetcode 203
// Remove Linked List Elements

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* h = new ListNode(-1);
        h->next = head;
        ListNode* ans = h;
        
        while(h) {
            auto p = h->next;
            bool removed = false;
           
            while(p && p->val == val) {
                removed = true;
                p = p->next;
            }
            if (!removed) h = h->next;
            else {
                h -> next = p;
                h = h->next;
            }
        }
        
        return ans->next;
    }
};