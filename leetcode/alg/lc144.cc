// leetcode 144
// Binary Tree Preorder Traversal 

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(TreeNode* node, vector<int>& ans) {
        if (!node) return;
        
        ans.push_back(node->val);
        
        dfs(node->left, ans);
        dfs(node->right, ans);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> sk;
        vector<int> ans;
        
        while(root) {
            ans.push_back(root->val);
            sk.push(root);
            root = root->left;
        }
        
        
        while(!sk.empty()) {
            auto top = sk.top(); sk.pop();
            
            auto t = top->right;
            
            while(t) {
                ans.push_back(t->val);
                sk.push(t);
                t = t->left;
            }
        }
        
        return ans;
    }
};