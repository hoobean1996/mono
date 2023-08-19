// leetcode 404
// Sum of Left Leaves
// 给定一棵二叉树，我们想知道所有左叶子节点的和

// 我们递归的时候，携带一个标识代表是否为左叶子
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
    int ans;

    void dfs(TreeNode* node, bool isLeft) {
        if (!node) return;

        if (node->left == nullptr && node->right == nullptr && isLeft) {
            ans += node->val;
            return;
        }

        dfs(node->left, true);
        dfs(node->right, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;

        dfs(root, false);

        return ans;
    }
};