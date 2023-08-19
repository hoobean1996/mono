// leetcode 783
// Minimum Distance Between BST Nodes

// 给定一棵二叉搜索树，我们想知道在所有的顶点中，最小的的两个顶点的差值是多少
// 由于是二叉搜索树，所以最小的差值只能发生在连续的两个节点中
// 所以我们采用中序遍历，并记录prev节点
// 在中序处理的过程中，如果prev不为空，我们就能计算 prev->val - node->val的差值，同时更新prev
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* prev;
    int ans = 1e9;
    
    void inorder(TreeNode* node) {
        if (!node) return;
        
        inorder(node->left);
        
        if (prev) ans = min(ans, abs(prev->val - node->val));
        prev = node;
        
        inorder(node->right);
    }
    
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return ans;
    }
};