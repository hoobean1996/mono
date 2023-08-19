// leetcode 114
// Flatten Binary Tree to Linked List

// 基本思路是递归，假设我们左右子树都已经是单链表
// 我们如何解决当前节点的问题
// 这道题是binary tree，所以不能利用中序遍历
// 如果是BST，是可以利用中序遍历有序处理的
class Solution {
public:
    TreeNode* flattenTree(TreeNode* root) {
        if (!root) return root;
        
        if (root->left == nullptr && root->right == nullptr) return root;
        
        TreeNode* ltail = flattenTree(root->left);
        TreeNode* rtail = flattenTree(root->right);
        
        if (ltail != nullptr) {
            ltail->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        
        return rtail == nullptr ? ltail : rtail;
    }
    
    void flatten(TreeNode* root) {
        flattenTree(root);
    }
};