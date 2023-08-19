// leetcode 160
// Intersection of Two Linked Lists
// 给定两个链表，其中相聚于某个点
// 我们想知道相交的点在哪儿
// 首先给定两个指针分别指向l1, 和 l2
// 设相交的位置为x
// l1 -> x = a 
// l2 -> x = b
// 公共的部分记为c
// a + c + b
// b + c + a
// 所以一直移动指针即可，如果到底了，就指向另外一个链表
// 这样会在相交处相遇
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto p1 = headA;
        auto p2 = headB;
        
        while(p1 != p2) {
            p1 = p1 ? p1->next : headB;
            p2 = p2 ? p2->next : headA;
        }
        
        return p1;
    }
};