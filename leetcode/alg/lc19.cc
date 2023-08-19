// leetcode 19
// Remove Nth Node From End of List

// 删除链表的倒数第n个数，我们可以利用两个指针，
// 他们的距离差是n，当快指针走到第的时候，慢指针就在倒数第n个位置的前躯位置
// 然后直接利用它删除第n个节点即可

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (!head)
      return head;

    ListNode *dummy = new ListNode(-1, head);
    ListNode *fast = dummy;
    ListNode *slow = dummy;

    // 快指针先移动n次，
    // 当快指针移动到末尾的时候，慢指针就是倒数第n个节点
    for (int i = 0; i < n; i++)
      fast = fast->next;

    // fast->next = nullptr 意味着
    // 当前的fast已经到了末尾了
    // 所以循环条件是 fast->next != nullptr
    while (fast->next != nullptr) {
      fast = fast->next;
      slow = slow->next;
    }

    // 删除这个节点
    slow->next = slow->next->next;
    return dummy->next;
  }
};