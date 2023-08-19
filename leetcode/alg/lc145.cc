// leetcode 145
// Binary Tree Postorder Traversal 

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(TreeNode* node, vector<int>& ans) {
        if (!node) return;
        
        dfs(node->left, ans);
        dfs(node->right, ans);
        ans.push_back(node->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        dfs(root, ans);
        
        return ans;
    }
};


class Solution {
public:
    // 二叉树的非递归遍历 后序遍历
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> sk;
        
        vector<int> ans;
        
        TreeNode* last = nullptr;
        
        // 把根节点及其所有的左儿子放入到栈中
        while(root) {
            sk.push(root);
            root = root->left;
        }
        
        while(!sk.empty()) {
            auto top = sk.top();
            
            if (
                // 如果当前的节点满足以下任意一种情况
                // 证明它的左右儿子已经遍历完了，所以可以弹出处理
                // 叶子节点
                (top->left == nullptr && top->right == nullptr) ||
                // 前一个节点是当前节点的右子树
                (last == top->right) ||
                // 前一个节点是当前节点的左子树 并且右子树为空
                (last == top->left && top->right == nullptr)) {
                last = top;
                ans.push_back(top->val);
                sk.pop();
            }
            // 其他情况都是一样的，把右儿子及其所有的左儿子放入到栈中
            else {
                TreeNode* t = top->right;
                while(t) {
                    sk.push(t);
                    t = t->left;
                }
            }
        }
        
        return ans;
    }
};