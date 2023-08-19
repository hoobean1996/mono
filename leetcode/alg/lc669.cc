// leetcode 669
// Trim a Binary Search Tree

// Trim一棵二叉搜索树，给定一个区间，我们想把这颗二叉搜索树上所有不在这个区间的所有节点都删除
// 这样剩下的二叉搜索树都在这个区间
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
    // 考虑trimBST会处理以root为跟节点的子树
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // 如果当前子树根节点为空，返回即可
        if (!root) return root;
        
        // 如果当前节点值比high更大，那么右子树就完全可以删除了，所以我们就只需要左子树
        if (root->val > high) return trimBST(root->left, low, high);

        // 如果当前节点值比low更小，那么左子树就完全可以删除了，所以就只需要右子树
        if (root->val < low) return trimBST(root->right, low, high);

        // 其他情况的话，当前节点值在这个区间，所以当前节点不必处理
        // 但是左子树和右子树都有可能需要删除一些节点
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }
};