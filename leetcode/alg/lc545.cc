// leetcode 545
// Boundary of Binary Tree

// 二叉树的边界由三部分组成, root, left boundary, leaves(left->right), reverse(right bounday)
// left boundary的定义如下：
//  root节点的left孩子应该在这个集合，如果没有left孩子，那么left bounday为空
//  如果一个节点在left boundary中间，那么该节点的left孩子也应该在left boundary里面
//  如果一个节点在left boundary中间，但是它没有left孩子，那么它的right孩子应该在left boundary里面
//  leftmost叶子节点不在left boundary里面

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isLeaf(TreeNode* node) {
        if (!node) return false;

        return node->left == nullptr && node->right == nullptr;
    }

    void addLeaves(vector<int>& ans, TreeNode* root) {
        if (isLeaf(root)) ans.push_back(root->val);
        else {
            if (root->left) addLeaves(ans, root->left);
            if (root->right) addLeaves(ans, root->right);
        }
    }

    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) return {};

        vector<int> ans;
        if (!isLeaf(root)) ans.push_back(root->val);

        TreeNode* t = root->left;

        while(t) {
            if (!isLeaf(t)) ans.push_back(t->val);
            if (t->left) t = t->left;
            else t = t->right;
        }

        addLeaves(ans, root);

        vector<int> rightBoundary;
        t = root->right;

        while(t) {
            if (!isLeaf(t)) rightBoundary.push_back(t->val);
            if (t->right) t = t->right;
            else t = t->left;
        }

        reverse(rightBoundary.begin(), rightBoundary.end());

        ans.insert(ans.end(), rightBoundary.begin(), rightBoundary.end());
        return ans;
    }
};