// leetcode 897
// Increasing Order Binary Search Tree

// 给定一棵二叉搜索树，我们想把它变成一棵升序的类似链表的结构
// 由于二叉搜索树的中序遍历是有序的，我们只需要维护一个prev指针即可
// 为了实现简单，我们创建一个dummy TreeNode, 然后把prev指针指向它，
// 这样在中序遍历的时候就不用判断是否为空了
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    TreeNode* prev;
    TreeNode* ans;

    void inorder(TreeNode* node) {
        if (!node) return;

        inorder(node->left);

        node->left = nullptr;
        prev->right = node;
        prev = node;

        inorder(node->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        if (!root) return root;
        ans = new TreeNode(0);
        prev = ans;
        inorder(root);
        return ans->right;
    }
};