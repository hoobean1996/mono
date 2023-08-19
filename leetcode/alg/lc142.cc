// leetcode 142
// Linked List Cycle II
// 给定一个带环的链表，我们希望找到链表的起点
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto slow = head;
        auto fast = head;
        
        // 先通过快慢指针移动到两个指针碰到的位置
        // 然后把慢指针移动的head，在来一次就可以了
        do {
            if (!fast || !(fast->next)) return nullptr;
            
            slow = slow->next;
            fast = fast->next->next;
        } while(slow != fast);
        
        // 关于为什么要重置到head的证明
        
        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};