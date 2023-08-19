// leetcode 1123
// Lowest Common Ancestor of Deepest Leaves
// 这道题是两个节点的最小公共祖先的问题变体
// 但是这里这两个节点是隐藏起来的，是两个深度最大的叶子节点。
// 所以我们需要找到这两个叶子节点，并且找到他们的最小公共祖先
// 首先我们可以递归的求出每个节点的高度，并且存储起来
// 然后在求lca的过程中，如果两个子树的高度是一样的，我们就可以返回它
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
    map<TreeNode*, int> memo;
    
    // 递归 + 记忆化求解所有节点的高度信息
    int height(TreeNode* node) {
        if (!node) return 0;
        
        if (memo[node]) return memo[node];
        memo[node] = 1+max(height(node->left), height(node->right));
        return memo[node];
    }

    // lca就是分别拿到左右两个儿子节点的深度
    // 是后序遍历 所以从底至上的处理所有节点，
    // 如果两个儿子的深度一样，那么返回它，否则就返回左边或者右边
    TreeNode* lca(TreeNode* node) {
        int l = height(node->left);
        int r = height(node->right);

        if (l == r) return node;
        else if (l > r) return lca(node->left);
        return lca(node->right);
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return lca(root);
    }
};