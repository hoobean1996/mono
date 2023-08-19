// leetcode 24
// Swap Nodes in Pairs

// 两个两个交换节点的值
#include <bits/stdc++.h>

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
    ListNode *swapPairs(ListNode *head)
    {
        // 如果没有节点或者只有一个节点，直接返回
        if (!head || !head->next)
            return head;

        // 递归解决，假设swapPair能够将后面的节点完成交换
        // 那么对于当前的head 和 head->next来说，我们需要处理他们的交换问题即可
        ListNode *new_head = head->next;
        head->next = swapPairs(new_head->next);
        new_head->next = head;
        return new_head;
    }
};