// leetcode 25
// Reversed Nodes in K-Group

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
  // Reverse a linked list
  ListNode *reverse(ListNode *h) {
    if (!h)
      return h;

    ListNode *prev = nullptr;

    while (h) {
      ListNode *next = h->next;
      h->next = prev;
      prev = h;
      h = next;
    }

    return prev;
  }

  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *fast = head;
    ListNode *prev;
    int i;
    for (i = 0; i < k && fast->next; i++) {
      prev = fast;
      fast = fast->next;
    }
    if (i == k - 1)
      return reverse(head);
    else if (i < k)
      return head;
    prev->next = nullptr;
    ListNode *reversedHead = reverse(head);
    ListNode *tail = reverseKGroup(fast, k);
    ListNode *rh = reversedHead;
    while (rh->next)
      rh = rh->next;
    rh->next = tail;

    return reversedHead;
  }
};