// leetcode 1973
// Count Nodes Equal to Sum of Descendants

// 计算一棵二叉树上的节点数目：
// 这些节点的值需要等于它所有的后代节点的和
// 整体来说采用后序遍历
// getSum(root) {
//      int left = getSum(root->left); 
//      int right = getSum(root->right);
//      if (left + right == root->val) ...
// }
#include <bits/stdc++.h>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(){}

    TreeNode(int val): val(val) {}
};

class Solution {
public:
    int ans = 0;
    
    long long descendantsSum(TreeNode* root) {
        if (!root) return 0;
        
        long long left = descendantsSum(root->left);
        long long right = descendantsSum(root->right);
        
        if (left + right == root->val) ans ++;
        
        return left + right + root->val;
    }
    
    int equalToDescendants(TreeNode* root) {
        descendantsSum(root);
        
        return ans;
    }
};