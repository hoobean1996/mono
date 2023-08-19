// leetcode 199
// Binary Tree Right Side View
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return vector<int>();
        
        queue<TreeNode*> q;
        
        vector<int> ans;
        
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            
            for(int i=0; i<n; i++) {
                TreeNode* t = q.front();
                q.pop();
                
                if (i == n-1) {
                    ans.push_back(t->val);
                }
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        
        return ans;
    }
};

// DFS解法
// DFS解法更简单，每次
class Solution {
public:
    vector<int> rightside;
    
    // 如果当前的level == rightside的长度就返回即可
    // 注意到现调用右子树，在调用左子树
    void helper(TreeNode* node, int level) {
        if (level == rightside.size()) rightside.push_back(node->val);

        if (node->right) helper(node->right, level + 1);
        if (node->left) helper(node->left, level+ 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        helper(root, 0);
        return rightside;
    }
};