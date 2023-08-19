// leetcode 83
// Remove Duplicates from Sorted List

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
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *cur = head;

    // 考虑当前的数和下一个数都存在
    // 如果当前的数和下一个数相同
    while (cur && cur->next) {
      if (cur->val == cur->next->val) {
        // 使用一个while循环直接往后走
        // 1 2 2 2 2
        while (cur->next && cur->val == cur->next->val) {
          cur->next = cur->next->next;
        }
        cur = cur->next;
      } else
        cur = cur->next;
    }

    return head;
  }
};