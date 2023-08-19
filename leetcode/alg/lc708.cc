// leetcode 708
// Insert into a Sorted Circular Linked List
// 给定一个循环链表，我们想要在循环链表中插入一个元素。并维护有序性
// 首先找到最大的元素，然后开始寻找待插入的位置即可
// 注意用一个map来避免无限循环
// 比如 1 -> 1（一个元素的情况)
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node() : val(0), next(nullptr) {}
    Node(int _val) : val(_val), next(nullptr) {}
    Node(int _val, Node *_next) : val(_val), next(next) {}
};

class Solution
{
public:
    Node *insert(Node *head, int insertVal)
    {
        // 如果该循环链表是空的，创建一个新的头节点
        // 并指向自己
        if (!head)
        {
            Node *n = new Node(insertVal);
            n->next = n;
            return n;
        }

        Node *h = head;
        unordered_map<Node *, bool> m;

        // 如果当前的节点的下一个节点比当前的节点值大
        // 那么移动到下一个元素
        // 不断这样移动，我们会找到移动到最大的元素
        while ((h->next->val >= h->val) && m.find(h->next) == m.end())
        {
            h = h->next;
            m[h] = true;
        }
        m.clear();

        // 如果当前插入的节点比下一个节点的值大，那么我们往前移动
        while ((insertVal > h->next->val) && m.find(h->next) == m.end())
        {
            h = h->next;
            m[h] = true;
        }

        Node *n = new Node(insertVal);
        n->next = h->next;
        h->next = n;
    
        return head;
    }
};