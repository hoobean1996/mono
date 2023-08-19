// leetcode 2
// Add Two Numbers

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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *h = new ListNode(-1);
    ListNode *ans = h;

    int c = 0;
    // 优化过的写法
    // 如果 l1 || l2 存在一个就继续添加
    while (l1 || l2) {
      // 由于两个链表的长度不一定相同，所以可能有一个为空
      int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + c;
      ListNode *n = new ListNode(sum % 10);
      c = sum / 10;
      h->next = n;
      h = h->next;
      // 如果存在在继续移动
      if (l1)
        l1 = l1->next;
      if (l2)
        l2 = l2->next;
    }

    if (c > 0) {
      ListNode *n = new ListNode(c);
      h->next = n;
    }

    return ans->next;
  }
};