// leetcode 143
// Reorder List
// 给定一个链表 l0 l1 ... ln
// 希望转化为 l0 ln l1 ln-1 ....的格式
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // 反转链表
    ListNode *reverse(ListNode *h) {
        if (!h) return h;

        ListNode *prev = nullptr;

        while (h) {
            ListNode *next = h->next;
            h->next = prev;
            prev = h;
            h = next;
        }

        return prev;
    }

    ListNode *middle(ListNode *h)
    {
        ListNode *fast = h;
        ListNode *slow = h;
        ListNode *prev;
        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        return slow;
    }

    ListNode *merge(ListNode *h1, ListNode *h2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *ans = dummy;

        while (h1 && h2)
        {
            ListNode *h1next = h1->next;
            ListNode *h2next = h2->next;

            ans->next = h1;
            h1->next = h2;

            h1 = h1next;
            h2 = h2next;
            ans = ans->next->next;
        }
        return dummy->next;
    }
    // 首先利用middle函数求链表中点
    // 然后反转后一个链表
    // 合并链表即可
    void reorderList(ListNode *head)
    {
        if (!head || !(head->next))
            return;

        ListNode *mid = middle(head);
        ListNode *rh = reverse(mid);
        ListNode *ans = merge(head, rh);
        head = ans;
    }
};