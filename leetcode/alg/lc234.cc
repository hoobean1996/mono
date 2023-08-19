// leetcode 234
// Palindrome Linked List

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
    
    ListNode* middle(ListNode* h) {
        ListNode* fast = h;
        ListNode* slow = h;
        
        ListNode* prev = nullptr;
        
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = nullptr;
        return slow;
    }
    
    bool isPalindrome(ListNode* head) {
        if (!head | !(head->next)) return true; 
        
        ListNode* h1 = head;
        ListNode* _h2 = middle(head);
        ListNode* h2 = reverse(_h2);
        while(h1 && h2) {
            if (h1->val != h2->val) return false;
            h1 = h1->next;
            h2 = h2->next;
        }
        return true;
    }
};