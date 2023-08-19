// leetcode 257
// Binary Tree Paths

// 给定一棵二叉树，打印所有的路径
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
    vector<string> ans;
    
    void dfs(TreeNode* root, vector<int>& path) {
        path.push_back(root->val);
        
        if (root->left == nullptr && root->right == nullptr) {
            string s;
            if (path.size() >= 1) {
                s += to_string(path[0]);
                for(int i=1; i<path.size(); i++) s += "->" + to_string(path[i]);
            }
            ans.push_back(s);
        }
        
        if (root->left) dfs(root->left, path);
        
        if (root->right) dfs(root->right, path);
        
        path.pop_back();
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        
        vector<int> path;
        
        dfs(root, path);
        
        return ans;
    }
};