// leetcode 1382
// Balance a Binary Search Tree

// 把一棵不平衡的二叉搜索树变得平衡
// Solution 1: 通过中序遍历得到有序的数组，利用中点作为root，递归的构建即可
// 构建的时候是采用中序遍历的模式， 先构建跟节点，然后构建左右两个子节点
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
    vector<int> vals;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        vals.push_back(root->val);
        inorder(root->right);
    }
    // 给定一个有序数组，构建一个平衡的BST
    // 在[l..r]区间构建子树
    TreeNode* buildBalancedBST(vector<int> vals, int l, int r) {
        // 如果 l > r 空节点
        if (l > r) return nullptr;
        // 用当前的中间节点来作为根节点来尽可能保证平衡
        int mid = l + (r - l) / 2;
        TreeNode* root = new TreeNode(vals[mid]);
        root->left = buildBalancedBST(vals, l, mid - 1);
        root->right = buildBalancedBST(vals, mid + 1, r);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        if (!root) return root;

        inorder(root);

        return buildBalancedBST(vals, 0, vals.size() - 1);
    }
};