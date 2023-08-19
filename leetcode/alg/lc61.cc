// leetcode 61
// Rotate List

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
    // 利用引用，在反转链表的时候顺便求出长度
    // 整体的思路是
    // 1. 整体反转
    // 2. 两次局部反转
    ListNode* reverse(ListNode* head, int& len) {
        if (!head) return head;
        
        ListNode* prev = nullptr;
        
        while(head) {
            ++len;
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        return prev;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        // 如果没有任何节点，或者k == 0， 那么就不用rotate了
        if (!head || k == 0) return head;
        
        // 首先求出长度
        int len = 0;
        ListNode* rh = reverse(head, len);
        
        // 由于k可能会循环，所以直接mod
        k = k % len;
        
        // 如果mod之后为0，则不用rotate了
        if (k == 0) return reverse(rh, len);
        
        ListNode* p = rh;
                
        while(k > 1) {
            k--;
            p=p->next;
        }
        
        ListNode* q = p->next;
        p->next = nullptr;
        
        int lenp = 0;
        ListNode* rp = reverse(rh, lenp);
        
        int lenq = 0;
        ListNode* rq = reverse(q, lenq);
        
        ListNode* ans = rp;
        
        while(rp->next) rp=rp->next;
        rp->next = rq;
        
        return ans;
    }
};