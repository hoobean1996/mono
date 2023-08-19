// leetcode 138
// Copy List with Random Pointer

// 和深度复制一个图是一样的，唯一需要注意的是，在递归到下一层之前标记visited

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
public:
    unordered_map<Node*, Node*> m;

    Node* copyRandomList(Node* head) {
        if (!head) return head;
        
        if (m.count(head)) return m[head];
        
        Node* copyHead = new Node(head->val);
        m[head] = copyHead;

        copyHead->next = copyRandomList(head->next);
        copyHead->random = copyRandomList(head->random);
        return copyHead;
    }
};