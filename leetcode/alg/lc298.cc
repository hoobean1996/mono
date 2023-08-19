// leetcode 298
// Binary Tree Longest Consecutive Sequnce

// 二叉树的最长连续路径
// 给定一棵二叉树，返回在这棵树上最长的连续路径长度
// 考虑后序，假设全是连续的路径的话
// l  = dfs(left) + 1
// r = dfs(right) + 1
// 对于当前节点来说 max(l, r)当前节点可以得到的最长的路径长度并返回即可
// 
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int m = 0;
    
    int dfs(TreeNode* root) {
        if (!root) return 0;
        
        int l = dfs(root->left) + 1;
        int r = dfs(root->right) + 1;
        
        if (root->left && root->val + 1 != root->left->val) l = 1;
        if (root->right && root->val + 1 != root->right->val) r = 1;
        
        m = max(m, max(l, r));
        
        return max(l, r);
    }
    
    int longestConsecutive(TreeNode* root) {
        dfs(root);
        
        return m;
    }
};