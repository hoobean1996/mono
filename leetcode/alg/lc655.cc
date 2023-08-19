// leetcode 655
// Print Binary Tree

// 给定一棵二叉树，我们希望把它格式化的打印在一个m*n的矩阵中
// 假设我们的树高为height，那么 m = height + 1
// 对于我们的宽度 n = 2^(height+1) - 1
// 然后把root节点放置到第一行的中间位置
// 对于每个已经放置到矩阵的节点，如果他的位置是(r,c)，那么我们应该把他的儿子放置到
// (r+1, c - 2^(height - r - 1)) (r+1, c + 2^(height - r - 1))

// 格式化打印一棵二叉树

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
    vector<vector<string>> ans;
    int h;
    
    int getHeight(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
    
    // dfs是把当前节点放置到 第l行，区间是 [l .. r]
    // 我们每次都需要把节点放置到 [l..r]的中间
    void dfs(TreeNode* node, int level, int l, int r) {
        if (!node) return;
        
        int mid = l + (r - l) / 2;
        ans[level][mid] = to_string(node->val);
        dfs(node->left, level + 1, l, mid-1);
        dfs(node->right, level + 1, mid+1, r);
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root);
        int width = (int)pow(2, height) - 1;
                
        ans = vector<vector<string>>(height, vector<string>(width));
        dfs(root, 0, 0, width - 1);
        return ans;
    }
};