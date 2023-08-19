// leetcode 938
// Range Sum of BST

// 给定一颗二叉搜索树
// 求解所有节点的值在[low, high]的节点的和
// 直接利用dfs即可
// 整体的模式是后序遍历，首先求得两个左右儿子的和，然后判断当前节点是否在区间内，如果是就加上并返回
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
    int dfs(TreeNode* node, int low, int high) {
        if (!node) return 0;

        int l = dfs(node->left, low, high);
        int r = dfs(node->right, low, high);

        int val = 0;
        if (node->val >= low && node->val <= high) val = node->val;

        return val + l + r;
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        return dfs(root, low, high);
    }
};