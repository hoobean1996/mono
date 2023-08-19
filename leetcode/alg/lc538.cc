// leetcode 538
// Convert BST to Greater Tree

// 把一棵BST转换为一棵Greater Tree
// Greater Tree就是把每个节点变为 >=该节点的和
// 利用后序遍历就能完成
// 利用一个sum来计算当前经过的值
// 先处理右子节点，然后当前节点，最后左子节点

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
    int sum = 0;

    void dfs(TreeNode* root) {
        if (!root) return;

        dfs(root->right);

        sum += root->val;

        root->val = sum;

        dfs(root->left);
    }

    TreeNode* convertBST(TreeNode* root) {
        if (!root) return root;

        dfs(root);

        return root;
    }
};