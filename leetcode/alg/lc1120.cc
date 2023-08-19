// leetcode 1120
// Max Average Subtree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    double ans = -1;
    
    // sum, size
    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};
        
        auto l = dfs(node->left);
        auto r = dfs(node->right);
        
        double avg = (node->val + l.first + r.first) * 1.0 / (1 + l.second + r.second);
        
        ans = max(ans, avg);
        
        return {node->val + l.first + r.first, 1 + l.second + r.second};
    }
    
    double maximumAverageSubtree(TreeNode* root) {
        dfs(root);
        
        return ans;
    }
};