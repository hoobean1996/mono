// leetcode 147
// Insertion Sort List

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
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return head;
        
        ListNode* h = new ListNode(0);
        ListNode* cur = head;
        
        while(cur) {
            ListNode* hh = h;
            
            // 找到插入的位置
            while(hh->next && hh->next->val <= cur->val) hh = hh->next;
            
            ListNode* hhnext = hh->next;
            hh->next = cur;
            cur = cur->next;
            hh->next->next = hhnext;
        }
        
        return h->next;
    }
};