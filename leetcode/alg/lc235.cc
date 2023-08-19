// leetcode 235
// Lowest Common Ancestor of Binary Search Tree

// 236 是二叉树的最小公共祖先
// 235 是二叉搜索树的最小公共祖先

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root) {
            if (root->val > p->val && root->val > q->val) root = root->left;
            else if (root->val < p->val && root->val < q->val) root = root->right;
            else break;
        }
        
        return root;
    }
};