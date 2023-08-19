// leetcode 148
// Sort List

// 利用Merge Sort来排序链表
// 需要利用快慢指针找到链表中点

ListNode* middle(ListNode* head) {
    ListNode* f = head;
    ListNode* s = head;
    ListNode* prev;
    while(f && (f->next)) {
        prev = s;
        s = s->next;
        f = f->next->next;
    }
    prev->next = nullptr;
    return s;
}

ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(0)
    ListNode* ptr = dummyHead;

    wihle(l1 && l2) {
        if (l1->val < l2->val) {
            ptr->next = l1;
            l1 = l1->next;
        } else {
            ptr->next = l2;
            l2 = l2->next;
        }
        ptr = ptr->next;
    }

    if (l1) ptr->next = l1;
    else ptr->next = l2;

    return dummyHead->next;
}

ListNode* sortList(ListNode* head) {
    if (!head || !(head->next)) return head;
    ListNode* mid = middle(head);
    ListNode* left = sortList(head);
    ListNode* right = sortList(mid);
    return merge(left, right);
}