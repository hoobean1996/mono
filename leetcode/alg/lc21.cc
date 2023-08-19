// leetcode 21
// Merge Two Sorted Lists
// 合并有序的链表

#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *p1 = l1;
        ListNode *p2 = l2;

        ListNode *ans = new ListNode(0);
        ListNode *head = ans;

        while (p1 && p2)
        {
            if (p1->val <= p2->val)
            {
                ans->next = p1;
                p1 = p1->next;
                ans = ans->next;
            }
            else
            {
                ans->next = p2;
                p2 = p2->next;
                ans = ans->next;
            }
        }

        ListNode *left = p1 ? p1 : p2;
        while (left)
        {
            ans->next = left;
            left = left->next;
            ans = ans->next;
        }

        return head->next;
    }
};