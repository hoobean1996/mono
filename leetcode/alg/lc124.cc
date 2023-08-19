// leetcode 124
// Binary Tree Maximum Path Sum

// 求二叉树的最大和路径
#include <bits/stdc++.h>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int max_sum = -1e9;
    int dfs(TreeNode* node) {
        if (!node) return 0;
        
        int l = max(dfs(node->left), 0);
        int r = max(dfs(node->right), 0);
        
        int price_newpath = node->val + l + r;
        
        max_sum = max(max_sum, price_newpath);
        
        return node->val + max(l, r);
    }
    
    int maxPathSum(TreeNode* root) {
        dfs(root);
        
        return max_sum;
    }
};