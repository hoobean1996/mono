// leetcode 543
// Diameter of a Binary Tree
// 首先递归的考虑这个问题
// 空节点和叶子节点的直径是为0
// 假设我们有两个节点的信息 l, r
// 那么加上当前节点的最大直径是 l + 1 + r + 1
// 但是在向上返回的时候，只能选择最长的那条路径
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
    int ans = 0;
    
    int dfs(TreeNode* node) {
        if (!node || (node->left == nullptr && node->right == nullptr)) return 0;
        
        int l = 0;
        int r = 0;
        
        if (node->left) l = dfs(node->left) + 1;
        if (node->right) r = dfs(node->right) + 1;
        
        int path = l + r;
        ans = max(path, ans);
        
        return max(l, r);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        
        return ans;
    }
};