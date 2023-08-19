// leetcode 328
// Odd Even Linked List
// 给定一个单链表，我们希望按照奇偶来重排链表
// 比如 12345 变成 13524
// 创建两个指针，分别指向奇数节点 和 偶数节点，初始化为从第一个节点和第二个节点
// 然后我们就不断连接移动就可以了
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;

        auto old = head;
        auto even = head->next;
        auto evenHead = even;

        while (even && even->next) {
            old->next = even->next;
            old = old->next;
            even->next = old->next;
            even = even->next;
        }
        old->next = evenHead;
        return head;
    }
};