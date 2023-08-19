// leetcode 102
// Binary Tree Level Order Traversal 

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
    vector<vector<int>> bfs(TreeNode* root) {
        if (!root) return vector<vector<int>>();
        
        
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            vector<int> tmp;
            int n = q.size();
            for(int i=0; i<n; i++) {
                TreeNode* h = q.front();
                q.pop();
                tmp.push_back(h->val);
                if (h->left) q.push(h->left);
                if (h->right) q.push(h->right);
            }
            ans.push_back(tmp);
        }
        
        return ans;
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        return bfs(root);
    }
};