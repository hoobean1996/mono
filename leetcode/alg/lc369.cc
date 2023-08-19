// leetcode 369
// Plus One Linked List
// 链表+1
// 最通用的办法就是利用两个数求和的方法
// 但是对于+1来说，我们有更简单的方法
// 首先找到最右侧的非9的数位 进行加一
// 然后改位之后的所有的9都置为0即可
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
    ListNode* plusOne(ListNode* head) {
        ListNode* h = new ListNode(0);
        h->next = head;
        ListNode* notNine = h;

        // 找到最右侧的非9
        // 遍历整个链表，找到最后的非9的数位
        while (head) {
            if (head->val != 9) notNine = head;
            head = head->next;
        }
        
        notNine->val++;
        notNine = notNine->next;

        // 把右侧的9都置为0
        while (notNine) {
            notNine->val = 0;
            notNine = notNine->next;
        }

        return h->val != 0 ? h : h->next;
    }
};