// leetcode 226
// Invert Binary Tree
// 直接利用后序遍历就能invert
// 反转二叉树
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    TreeNode* rev(TreeNode* root) {
        if (!root) return root;
        TreeNode* l = rev(root->left);
        TreeNode* r = rev(root->right);
        root->left = r;
        root->right = l;
        return root;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        return rev(root);
    }
};