// leetcode 92
// Reverse Linked List II

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* h) {
        if (!h) return h;
        
        ListNode* prev = nullptr;
        
        while(h) {
            ListNode* next = h->next;
            h->next = prev;
            prev = h;
            h = next;
        }
        
        return prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* prevFrom = dummy;
        ListNode* from = head;
        
        while(left-- > 1) {
            prevFrom = from;
            from = from->next;
        }
        
        ListNode* to = head;
        
        while(right-- > 1) {
            to = to->next;
        }
        
        prevFrom->next = nullptr;
        ListNode* tail = to->next;
        to->next = nullptr;
        
        ListNode* rev = reverse(from);
        ListNode* r = rev;
        while(r->next) r = r->next;
        r->next = tail;
        prevFrom->next = rev;
        return dummy->next;
    }
};