// leetcode 23
// Merge K Sorted Lists
// 给定K个有序链表，我们希望合并成一个有序链表
// 第一种思路是 全部放入堆，然后出堆然后创建一棵新的链表 O(nlogn)
    // priority_queue<int, vector<int>, greater<int>> pq;
// 第二种思路就是利用heap来实现一个k路归并即可， 时间复杂度是O(nlogk) 空间复杂度是O(k)
    // struct cmp {
    //   bool operator()(const pair<int, ListNode*>& p1, const pair<int, ListNode*>& p2){}    
    // }
    // priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, cmp> pq;
// 第三种思路是利用分治策略，是实现空间复杂度为O(1)的归并
//   首先考虑我们有一个方法为 merge能够在O(1)的空间复杂度合并两个链表
//   基于这个假设我们来考虑如何归并k个
//      第一轮：我们考虑这样分组来进行合并 (0, 1) (2, 3) ... 合并以后的新链表是 (0, 2, 4 ...)
//      第二轮: 我们考虑这样分组 (0, 2) (4, 6) ...
//   interval := 1
//   while(interval < n) {
//      lists[i] = merge(lists[i], lists[i+interval])
//      interval *= 2
//   }
#include <bits/stdc++.h>
#include <queue>

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int value): val(value), next(nullptr) {} 
};

class Solution {
public:
    // 合并两个链表
    ListNode* _merge(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
        ListNode* head = ans;
        
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        
        while(p1 && p2) {
            if (p1->val <= p2->val) {
                ans->next = p1;
                p1 = p1->next;
                ans = ans->next;
            } else {
                ans->next = p2;
                p2 = p2->next;
                ans = ans->next;
            }
        }
        
        ListNode* left = p1 ? p1 : p2;
        while(left) {
            ans->next = left;
            left = left->next;
            ans = ans->next;
        }
        
        return head->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) return nullptr;

        int interval = 1;
        while(interval < n) {
            // 分组部分
            // 注意到循环的条件
            // i=0, i<n-interval; i+=interval*2
            //  _merge(list[i], lists[i+interval])
            for(int i=0; i<n-interval; i += interval * 2) {
                lists[i] = _merge(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        return lists[0];
    }
};