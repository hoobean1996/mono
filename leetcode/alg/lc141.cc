// leetcode 141
// Linked List Cycle
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 空链表直接返回
        if (!head) return false;
            
        auto slow = head;
        auto fast = head;
        
        // 假设有环的话，一定会二次相遇，
        // 所以采用do while写法，先移动一次
        // 在移动之前判断fast和fast->next是否为空，如果快指针到底了
        // 肯定就是没有cycle
        do {
            if (!fast || !(fast->next)) return false;
            slow = slow->next;
            fast = fast->next->next;
        } while(slow != fast);

        return true;
    }
};