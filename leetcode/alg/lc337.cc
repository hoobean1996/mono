// leetcode 337
// House Robber III

// 打家劫舍 树形地图
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // 考虑后序遍历的模式
    // dfs返回两个值，一个是选中当前节点的结果，一种是不选中当前节点的结果
    // {选中，不选中}
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return make_pair(0, 0);
        
        pair<int, int> l = dfs(root->left);
        pair<int, int> r = dfs(root->right);
        
        // 考虑选择该节点的话，左右一定不能选，
        // 考虑不选该节点的话，左右可选可不选，所以是两个max的和
        return {root->val + l.second + r.second, max(l.first, l.second) + max(r.first, r.second)};
    }
    
    int rob(TreeNode* root) {
        pair<int, int> val = dfs(root);
        return max(val.first, val.second);
    }
};