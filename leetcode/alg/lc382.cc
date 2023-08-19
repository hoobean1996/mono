// leetcode 382
// Linked List Random Node

// 给定一个单链表，随机返回任何一个节点。要求每个节点都有相同概率被选中

// 解决方案是蓄水池抽样算法
// 适合于总的样本数量未知，从所有样本中抽取若干个，要求每个样本被抽到的概率相等。
// 具体的做法是：
// 从前往后处理每个样本，每个样本成为答案的概率都是1/i，其中i是样本的编号，
// 最终可以保证每个样本被选中的概率是1/n

// 证明：
// 假设最终成为答案的样本为k，那么k成为答案的充要条件是在遍历到k的时候选中k
// 并且在遍历到大于k的元素的时候，没有替换掉k
// P = 1/k * (1 - 1/k+1) * (1 - 1/k+2) * ... * (1 - 1/n)
// 化简就能得到
// P = 1/n
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode* _head;
    
    Solution(ListNode* head) {
        this->_head = head;        
    }
    
    int getRandom() {
        int count = 1;
        int chosenValue = 0;

        ListNode* cur = this->_head;

        while(cur) {
            if (rand() % count == 0) chosenValue = cur->val;
            count ++;
            cur = cur->next;
        }
        
        return chosenValue;
    }
};