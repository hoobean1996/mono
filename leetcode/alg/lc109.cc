// leetcode 109
// Conver Sorted List to Binary Search Tree

// 和通过有序数组构造是一样的
// 需要关注的几个点
// 1. middleOf里面的prev可能为空
class Solution {
public:
    ListNode* middleOf(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* s = head;
        
        ListNode* f = head;
        
        while(f && f->next) {
            prev = s;
            s = s->next;
            f = f->next->next;
        }
        
        if (prev) prev->next = nullptr;
        return s;
    }
    
    TreeNode* buildTree(ListNode* head) {
        if (!head) return nullptr;
        
        ListNode* mid = middleOf(head);
        
        TreeNode* root = new TreeNode(mid->val);
        if (head == mid) return root;
        
        root->left = buildTree(head);
        root->right = buildTree(mid->next);
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head);
    }
};