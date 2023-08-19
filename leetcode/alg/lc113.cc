// leetcode 113
// Path Sum II
// 相比于Path Sum I，我们需要记录所有的方案。
// 肯定是需要考虑回溯的解决方案。
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    
    void dfs(TreeNode* cur, vector<int>& path, int targetSum) {   
        path.push_back(cur->val);
        
        // 如果满足条件并且当前节点是叶子节点，那么我们就放入答案
        if (cur->val == targetSum && cur->left == nullptr && cur->right == nullptr) {
            ans.push_back(path);
            path.pop_back();
            return;
        }
        
        // 考虑把左孩子放入
        if (cur->left) {
            dfs(cur->left, path, targetSum - cur->val);
        }
        
        //  考虑把右孩子放入
        if (cur->right) {
            dfs(cur->right, path, targetSum - cur->val);
        }
        
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return vector<vector<int>>();
        
        vector<int> path;
        
        dfs(root, path, targetSum);
        
        return ans;
    }
};