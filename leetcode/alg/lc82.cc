// leetcode 82
// Remove Duplicate From Sorted List II

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
    ListNode* deleteDuplicates(ListNode* head) {
        // 假设dummy是不含重复的链表
        ListNode* dummy = new ListNode(-101);
        
        ListNode* prev = dummy;
        
        ListNode* cur = head;
        
        while(cur && cur->next) {
            // 如果当前节点和它的下一个节点不同
            if (cur->val != cur->next->val) {
                prev->next = cur;
                prev = prev->next;
                
                cur = cur->next;
            }
            // 如果是相同的，那么就要移动
            else {
                int val = cur->val;
                
                while(cur->val == val ) {
                    cur = cur->next;
                    if (!cur) break;
                }
            }
        }
        
        prev->next = cur;
        prev = prev->next;
        
        return dummy->next;
    }
};